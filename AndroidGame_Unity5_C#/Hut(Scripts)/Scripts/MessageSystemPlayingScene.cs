using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MessageSystemPlayingScene : MonoBehaviour {

    static GameObject player;
    static GameObject EvaIDLE, BrianIDLE, ZakIDLE, Zak, Eva, Brian;

    static GameObject[] circle;
    [SerializeField] GameObject[] hero;
    [SerializeField] GameObject failPanel;
    [SerializeField] GameObject parentPanel;

    [SerializeField] AudioClip[] clips;
    [SerializeField] AudioClip defaultClip;
    [SerializeField] GameObject speedyTimer;
    static AudioClip staticDefaultClip;
    static AudioClip[] staticClips;
    static AudioSource audioSource;
    static List<AudioClip> listAudio = new List<AudioClip>();
    static List<AudioClip> bufListAudio = new List<AudioClip>();
    delegate void PlayMusic();
    static PlayMusic playMusic;

    public delegate void FailPanel();
    public static FailPanel fail;
    public delegate void PingPong();
    public static PingPong pong;
    public static bool exitFromPingPong;
    public static bool inPingPong;
    public delegate void Rizen();
    public static Rizen speedy;
    delegate void SetDefaultValue();
    static SetDefaultValue setDefault;
    static bool isStart;
    static bool isDead;
    static bool isFinishGame;
    static bool isTeleport;
    static bool isHit;
    static bool animationDeathIsFinished;
    static string playerName;
    static float speed = 5.2f;
    static bool[] activeCircleCollider = new bool[3];
    static int countAlivePlayer = 3;
    static GameObject disableScreen;
    static bool isJump;
    static RigidbodyConstraints2D constraints;
    static float backgroundSpeed = 3;
    static bool inBodyColider;
    static Hashtable hash = new Hashtable();
    static DelegateStorage storageVoid = new DelegateStorage();

    static float relationTransform = 1000f / 740.1323f;
    static float relationResolution = 1280f / 720f;
    static float relation = relationResolution / relationTransform;


    private void Start()
    {
        animationDeathIsFinished = true;
        exitFromPingPong = false;
        inPingPong = false;
        isStart = false;
        isDead = false;
        isFinishGame = false;
        isTeleport = false;
        isHit = false;
        playerName = "";
        countAlivePlayer = 3;
        isJump = false;
        backgroundSpeed = 3;
        inBodyColider = false;
        float deltaSpeed = 1f / ((Screen.width / (float)Screen.height) / (1280f / 720f));
        speed = 5.2f / deltaSpeed;


        float a = (float)Screen.width / (float)Screen.height;
        float k = a / relation;
        float y = 1000 / k;
        parentPanel.transform.localScale = new Vector3(1000, y, 0);
        circle = new GameObject[3];
        circle[0] = GameObject.Find("Interface/Brian");
        circle[1] = GameObject.Find("Interface/Eva");
        circle[2] = GameObject.Find("Interface/Zak");
        disableScreen = GameObject.Find("DisableScreen/Block");
        setDefault = new SetDefaultValue(SetDefaultValueMessageSystem);
        fail = new FailPanel(OpenFailPanel);
        pong = new PingPong(StartPingPong);
        speedy = new Rizen(RizeSpeed);
        Brian = hero[0];
        Eva = hero[1];
        Zak = hero[2];
        BrianIDLE = hero[3];
        EvaIDLE = hero[4];
        ZakIDLE = hero[5];
        constraints = Brian.GetComponent<Rigidbody2D>().constraints;
        if(!hash.ContainsKey(Brian.name))
           hash.Add(Brian.name, 0);
        if(!hash.ContainsKey(Eva.name))
           hash.Add(Eva.name, 1);
        if(!hash.ContainsKey(Zak.name))
           hash.Add(Zak.name, 2);

        int size = 5;
        storageVoid.InstMemory( "void", size, 3);
        storageVoid[0, 0] = (p) => player = BrianIDLE;
        storageVoid[0, 1] = (p) => player = EvaIDLE;
        storageVoid[0, 2] = (p) => player = ZakIDLE;
        storageVoid[1, 0] = (p) => player = Brian;
        storageVoid[1, 1] = (p) => player = Eva;
        storageVoid[1, 2] = (p) => player = Zak;
        storageVoid[2, 0] = (p) =>
        {
            circle[0].GetComponent<BoxCollider2D>().enabled = false;
            activeCircleCollider[0] = false;
        };
        storageVoid[2, 1] = (p) =>
        {
            circle[1].GetComponent<BoxCollider2D>().enabled = false;
            activeCircleCollider[1] = false;
        };
        storageVoid[2, 2] = (p) =>
        {
            circle[2].GetComponent<BoxCollider2D>().enabled = false;
            activeCircleCollider[2] = false;
        };
        storageVoid[3, 0] = (obj) =>
         {
            GameObject buf = (GameObject)obj;
            buf.GetComponent<Animation>().Play("BufBrian");
         };
        storageVoid[3, 1] = (obj) =>
         {
             GameObject buf = (GameObject)obj;
             buf.GetComponent<Animation>().Play("BufEva");
         };
        storageVoid[3, 2] = (obj) =>
         {
             GameObject buf = (GameObject)obj;
             buf.GetComponent<Animation>().Play("BufZak");
         };
        storageVoid[4, 0] = (p) =>
        {
            TapToHero.InstantiateSpeed("Brian");
            SelectHero(Brian);
        };
        storageVoid[4, 1] = (p) =>
        {
            TapToHero.InstantiateSpeed("Eva");
            SelectHero(Eva);
        };
        storageVoid[4, 2] = (p) =>
        {
            TapToHero.InstantiateSpeed("Zak");
            SelectHero(Zak);
        };
        staticClips = new AudioClip[clips.Length];
        for (int i = 0; i < clips.Length; i++)
            staticClips[i] = clips[i];


        SetDefaultValueMessageSystem();

        audioSource = GetComponent<AudioSource>();
        for(int i = 0; i < clips.Length; i++)
            listAudio.Add(clips[i]);
        playMusic = new PlayMusic(StartPlaySound);
        ADS.ShowAdMobBanner();
        staticDefaultClip = defaultClip;

        SetupVolume();
    }

    public static GameObject Player
    {
        get
        {
            return player;
        }

        set
        {
            player = value;
        }
    }

    public static bool IsStart
    {
        get
        {
            return isStart;
        }

        set
        {
            isStart = value;
        }
    }

    public static float Speed
    {
        get
        {
            return speed;
        }

        set
        {
            speed = value;
        }
    }

    public static bool IsJump
    {
        get
        {
            return isJump;
        }

        set
        {
            isJump = value;
        }
    }

    public static bool IsDead
    {
        get
        {
            return isDead;
        }

        set
        {
            isDead = value;
        }
    }

    public static bool IsTeleport
    {
        get
        {
            return isTeleport;
        }

        set
        {
            isTeleport = value;
        }
    }

    public static bool InBodyColider
    {
        get
        {
            return inBodyColider;
        }

        set
        {
            inBodyColider = value;
        }
    }

    public static bool IsFinishGame
    {
        get
        {
            return isFinishGame;
        }
    }

    public static float BackgroundSpeed
    {
        get
        {
            return backgroundSpeed;
        }

        set
        {
            backgroundSpeed = value;
        }
    }

    public static Hashtable Hash
    {
        get
        {
            return hash;
        }
    }

    public static bool IsHit
    {
        get
        {
            return isHit;
        }

        set
        {
            isHit = value;
        }
    }

    public static bool AnimationDeathIsFinished
    {
        set
        {
            animationDeathIsFinished = value;
        }
    }

    public static void SelectHero(GameObject hero)
    {

        foreach (GameObject obj in circle)
        {
            if (obj.name == hero.name)
                obj.GetComponent<Animation>().Play("RizeCircle");
            else if (playerName == obj.name)
            {
                obj.GetComponent<Animation>().Play("ReduceCircle");
                if (IsActiveColider(playerName))
                    obj.GetComponentInChildren<BoxCollider2D>().enabled = true;
                else
                    ChangeToCrossSprite(obj);
            }
            else
            {
                if (IsActiveColider(obj.name))
                    obj.GetComponentInChildren<BoxCollider2D>().enabled = true;
            }
        }
        playerName = hero.name;
        player.SetActive(false);
        Vector2 positionLastPlayer = player.transform.position;
        string nameLastPlayer = player.name;

        if (!isStart)
            storageVoid[0, (int)hash[playerName]]();
        else
            ChangeHeroAfterStart();
        if (IsStart && IsActiveColider(nameLastPlayer))
            player.transform.position = positionLastPlayer;
        if (player.transform.position.x >= 0)
        {
            PlayerZone.IsOutside = false;
            PlayerZone.SetNoneRigid();
        }
        if (PlayerZone.IsOutside && !isDead)
        {
            PlayerZone.MoveToPlayerZone();
        }
        if (isJump && !isDead)
        { 
            MessageSystemGameBlock.SetPlayingConstraints();
        }
        if (!animationDeathIsFinished)
        {
            MessageSystemGameBlock.StartGame();
            isDead = false;
            EnableCollider();
        }
        DeadLine.IsDeadLine = false;
        player.SetActive(true);
    }

    static void ChangeHeroAfterStart()
    {
        storageVoid[1, (int)hash[playerName]]();
    }
    public static void StartGame()
    {
        isStart = true;
        MessageSystemGameBlock.Speed = speed;
        MessageSystemGameBlock.BackgroundSpeed = backgroundSpeed;
        player.SetActive(false);
        ChangeHeroAfterStart();
        OpenMenu.NumberOperation = 2;
        player.SetActive(true);
        MessageSystemGameBlock.StartStopWatch();
        Generate.Level = MessageSystemGameBlock.LEVEL;
        if (listAudio.Count != 0)
        {
            
            if (Conecting.Music == 1)
            {
                SaveListAudio();
                playMusic();
            }
        }
        else
            StopClip();
        MusicButton.DisableMusicButton();
    }

    public static GameObject DisableCollider()
    {
        disableScreen.SetActive(true);
        return disableScreen;
    }
    public static void EnableCollider()
    {
        disableScreen.SetActive(false);
    }

    public void OpenFailPanel()
    {
        Score.stop();
        TapToGo.SetActiveScreen(false);
        disableScreen.SetActive(false);
        Score.SetScoreFailPanel();
        failPanel.SetActive(true);
        MessageSystemGameBlock.ChangeLayerRight(0);
        StartCoroutine(FinishStopWatch());
        Question.DisableMenuAndQuestion();
        PauseGame.SetActivePause(false);
    }

    IEnumerator FinishStopWatch()
    {
        yield return null;
        MessageSystemGameBlock.StopStopWatch();
        while (true)
        {
            yield return null;
            Score.NULLScoreText();
        }

    }

    static bool IsActiveColider(string name)
    {
        return activeCircleCollider[(int)hash[name]];
    }
    public static void PlayerDeath(string name)
    {
        storageVoid[2,(int)hash[name]]();
    }

    static void ChangeToCrossSprite(GameObject obj)
    {
        storageVoid[3, (int)hash[obj.name]](obj);
    }

    public static void GeneralyPartOfDeath()
    {
        isDead = true;
        MessageSystemGameBlock.StopGame();
        PlayerDeath(Player.name);
        countAlivePlayer--;
        inBodyColider = false;
        if (countAlivePlayer == 0)
        {
            isDead = true;
            isFinishGame = true;
            player.SetActive(false);
            fail();
        }
    }

    public static void AutoSelectNextCharacter()
    {
        if (countAlivePlayer != 0)
        {
            int i;
            for (i = 0; i < 3; i++)
            {
                if (activeCircleCollider[i])
                    break;
            }
            storageVoid[4, i]();
            MessageSystemGameBlock.BackgroundSpeed = backgroundSpeed;
            isDead = false;
            pong();
        }
    }

    public IEnumerator PingPongPlayerAfterDeath()
    {
        inPingPong = true;
        player.tag = "InVisible";
        exitFromPingPong = false;
        TapToGo.SetActiveScreen(true);
        EnableCollider();

        int count = 5;
        float pingTime = 0.2f;
        float changeColor = 0.6f;
        Image img = player.GetComponent<Image>();
        SetVisibleImagePlayer(false);
        StartCoroutine(CheckOnVisible());
        while (count > 0)
        {           
            count--;
            img.color = new Color(changeColor, changeColor, changeColor, 1);
            yield return new WaitForSeconds(pingTime);
            img.color = new Color(1, 1, 1, 1);
            yield return new WaitForSeconds(pingTime);
            if (exitFromPingPong)
            {
                inPingPong = false;
                break;
            }
        }
        SetVisibleImagePlayer(true);

        player.tag = "Player";
        inPingPong = false;
        exitFromPingPong = true;
    }

    IEnumerator CheckOnVisible()
    {
        float timer = 0;
        while ((player.GetComponent<Image>().enabled || inBodyColider) && timer < 1)
        {
            timer += Time.deltaTime;
            yield return null;
        }


        SetVisibleImagePlayer(true);
    }

    public void StopPingPong()
    {
        StopCoroutine(PingPongPlayerAfterDeath());
    }

    public void StartPingPong()
    {
        StartCoroutine(PingPongPlayerAfterDeath());
    }

    public void RizeSpeed()
    {
        float coeff = 1.7f;
        MessageSystemGameBlock.Speed *= coeff;
        TapToHero.Multy = 1.7f;
        speedyTimer.GetComponent<Animation>().Play();
    }

    public static void SetDefaultConstraints()
    {
        player.GetComponent<Rigidbody2D>().constraints = constraints;
    }

    void SetDefaultValueMessageSystem()
    {
        for (int i = 0; i < 3; i++)
            activeCircleCollider[i] = true;
        countAlivePlayer = 3;
        isStart = false;
        isDead = false;

        player = ZakIDLE;
        playerName = "Zak";

        disableScreen.SetActive(false);
    }

    public static void SetDefaultVal()
    {
        setDefault();
        Storage.SetDefaultValue();
        Score.SetDefaultRecord();
        MessageSystemGameBlock.SetDefaultValue();
        Hint.SetDefaultValue();
        TapToGo.SetDefaulValue();
        OpenMenu.NumberOperation = 0;
    }

    public static void SetVisibleImagePlayer(bool value)
    {
        player.GetComponent<Image>().enabled = value;
    }

    public static void Jump()
    {
        if (!StopCollider.IsCollision)
        {
            float powerJump = 10;
            isJump = true;
            PlayerZone.SetNoneRigid();
            MessageSystemGameBlock.SetPlayingConstraints();
            if (!exitFromPingPong)
            {
                exitFromPingPong = true;
                player.tag = "Player";
            }
            if (!isDead)
            {
                WaitingScreen.wait(DisableCollider());
                player.GetComponent<Rigidbody2D>().AddForce(new Vector3(0, powerJump, 0), ForceMode2D.Impulse);
                player.GetComponent<Animator>().SetBool("IsJumpUp", true);
            }
        }
    }
    public static void Slip()
    {
        if (!StopCollider.IsCollision)
        {
            player.layer = 9;
            player.GetComponent<Animator>().SetBool("IsSlipDown", true);
        }
    }
    public static void Teleport()
    {
        if (!isTeleport && !StopCollider.IsCollision)
        {
            isTeleport = true;
            player.GetComponent<Animator>().SetBool("IsTeleport", true);
        }
    }
    public static void Hit()
    {
        if (!StopCollider.IsCollision)
        {
            player.GetComponent<Animator>().SetBool("IsHit", true);
            player.tag = "Hit";
        }
    }

    public static void PlayClip(AudioClip clip)
    {
        audioSource.clip = clip;
        audioSource.Play();
    }

    public static void StopClip()
    {
        audioSource.clip = null;
        audioSource.Stop();
        if (!isStart)
        {
            audioSource.clip = staticDefaultClip;
            audioSource.Play();
        }
    }

    public static void RemoveClipFromList(AudioClip clip)
    {
        listAudio.Remove(clip);
    }

    public static void AddClipToList(AudioClip clip)
    {
        listAudio.Add(clip);
    }

    public static void SaveListAudio()
    {
        bufListAudio.AddRange(listAudio);
    }

    IEnumerator PlaySound()
    {
        if (listAudio.Count == 0)
            listAudio.AddRange(bufListAudio);

        int rand = Random.Range(0, listAudio.Count);
        AudioClip currentClip = listAudio[rand];
        PlayClip(currentClip);
        yield return new WaitForSeconds(currentClip.length);
        RemoveClipFromList(currentClip);
        StartCoroutine(PlaySound());
    }

    void StartPlaySound()
    {
        StartCoroutine(PlaySound());
    }

    void SetupVolume()
    {
        if (Conecting.Music == 0)
        {
            audioSource.enabled = false;
        }
        else if(Conecting.Music == 1)
        {
            audioSource.volume *= Conecting.Volume;
        }
    }
}
