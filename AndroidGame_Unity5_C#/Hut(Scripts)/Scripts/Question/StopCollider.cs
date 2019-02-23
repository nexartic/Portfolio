using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class StopCollider : MonoBehaviour {

    [SerializeField] GameObject panel;
    [SerializeField] GameObject adviceButton;
    [SerializeField] Sprite[] sprites;
    static GameObject[] imageButtons = new GameObject[3];
    static GameObject currentObj,sortingLayerObj;
    Text txt;
    Hashtable hashtable = new Hashtable();
    delegate void FirstEducation(GameObject obj);
    FirstEducation[] education = new FirstEducation[10];
    delegate void IsAnimatin();
    static IsAnimatin[] anim = new IsAnimatin[3];
    static int typeAnimation;
    string[][] message = new string[2][];
    static bool isCollision;
    static RigidbodyConstraints2D saveConstr;

    public static bool IsCollision
    {
        get
        {
            return isCollision;
        }

        set
        {
            isCollision = value;
        }
    }

    private void Start()
    {
        typeAnimation = 0;
        isCollision = false;
        saveConstr = RigidbodyConstraints2D.FreezeAll;
        int j = 0;
        foreach (Image img in adviceButton.GetComponentsInChildren<Image>())
        {
            imageButtons[j++] = img.gameObject;
        }
        panel.SetActive(false);
        imageButtons[0].SetActive(false);
        imageButtons[2].SetActive(false);
        for (int i = 0; i < 2; i++)
            message[i] = new string[10];
        txt = panel.GetComponentInChildren<Text>();
        hashtable.Add("Robot", 0);
        hashtable.Add("Cube", 1);
        hashtable.Add("Barrier_Grey", 2);
        hashtable.Add("Portal_Grey", 3);
        hashtable.Add("Abyss", 4);
        hashtable.Add("Blade", 5);
        hashtable.Add("Speedy", 6);
        hashtable.Add("Saw", 7);
        hashtable.Add("Needles", 8);
        hashtable.Add("Enemy#1", 9);

        education[0] = (obj) => // Robot
        {
            currentObj = obj.GetComponentInChildren<Animator>().gameObject;
            typeAnimation = 2;
            obj.GetComponentInChildren<Animator>().speed = 0;
            SetMessage(message[Conecting.Language][0]);
            SetButtonImage(sprites[1]);
        };
        education[1] = (obj) =>// Cube
        {
            typeAnimation = 0;
            SetMessage(message[Conecting.Language][1]);
            SetButtonImage(sprites[2]);
        };
        education[2] = (obj) =>// Barrier
        {
            sortingLayerObj = FindBarrier(obj);
            sortingLayerObj.GetComponent<SpriteRenderer>().sortingOrder = 0;
            typeAnimation = 0;
            SetMessage(message[Conecting.Language][2]);
            SetButtonImage(sprites[0]);
            SetActiveImageButtons(true);
        };
        education[3] = (obj) =>//Portal
        {
            sortingLayerObj = FindPortal(obj);
            sortingLayerObj.GetComponent<SpriteRenderer>().sortingOrder = 0;
            typeAnimation = 0;
            SetMessage(message[Conecting.Language][3]);
            SetButtonImage(sprites[0]);
            SetActiveImageButtons(true);
            PlayerPrefs.SetInt("FirstStart", 1);
        };
        education[4] = (obj) =>//Abyss
        {
            typeAnimation = 0;
            SetMessage(message[Conecting.Language][4]);
            SetButtonImage(sprites[2]);
        };
        education[5] = (obj) =>//Blade
        {
            currentObj = obj.GetComponentInChildren<Animator>().gameObject;
            obj.GetComponentInChildren<Animator>().speed = 0;
            typeAnimation = 2;
            SetMessage(message[Conecting.Language][5]);
            SetButtonImage(sprites[3]);
        };
        education[6] = (obj) =>//Speedy
        {
            SetFontMaxSize(78);
            typeAnimation = 0;
            SetMessage(message[Conecting.Language][6]);
            imageButtons[1].SetActive(false);
        };
        education[7] = (obj) =>//Saw
        {
            SetFontMaxSize(56);
            imageButtons[1].SetActive(true);
            currentObj = obj;
            currentObj.GetComponent<Animation>()["Saw"].speed = 0;
            typeAnimation = 1;
            SetMessage(message[Conecting.Language][7]);
            SetButtonImage(sprites[4]);
        };
        education[8] = (obj) =>//Needles
        {
            currentObj = obj;
            currentObj.GetComponent<Animator>().speed = 0;
            typeAnimation = 2;
            SetMessage(message[Conecting.Language][8]);
            SetButtonImage(sprites[2]);
        };
        education[9] = (obj) =>//Enemy #1
        {
            currentObj = obj.GetComponentInChildren<Animator>().gameObject;
            if (currentObj)
            {
                currentObj.GetComponent<Animator>().speed = 0;
                typeAnimation = 2;
                SetMessage(message[Conecting.Language][9]);
                SetButtonImage(sprites[1]);
                FirstStart.EnableMenuAndQuestion();
                gameObject.SetActive(false);
            }
            else
            {
                MessageSystemPlayingScene.EnableCollider();
                IsCollision = false;
                MessageSystemPlayingScene.IsHit = false;
                MessageSystemGameBlock.StartAfterHit();
                MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 1;
                RestoreConstraints();
                SetDefaultSortingLayer();
                SetActiveImageButtons(false);
                panel.SetActive(false);
                FirstStart.EnableMenuAndQuestion();
                gameObject.SetActive(false);
            }
        };

        anim[0] = () => { };
        anim[1] = () => currentObj.GetComponent<Animation>()["Saw"].speed = 1;
        anim[2] = () => currentObj.GetComponent<Animator>().speed = 1;

        InicializedMessage();
        gameObject.SetActive(false);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        string name = collision.gameObject.name;
        if (hashtable.ContainsKey(name))
        {
            GameObject obj = collision.gameObject;
            StopGame();
            sortingLayerObj = null;

            MessageSystemPlayingScene.EnableCollider();
            SaveConstraints();
            MessageSystemPlayingScene.Player.GetComponent<Rigidbody2D>().constraints = RigidbodyConstraints2D.FreezeAll;
            panel.SetActive(true);
            isCollision = true;
            education[(int)hashtable[obj.name]](obj);
            hashtable.Remove(name);
        }
    }

    void StopGame()
    {
        MessageSystemGameBlock.SaveSpeed();
        MessageSystemGameBlock.StopGame();
        MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 0;
    }

    void SetMessage(string msg)
    {
        txt.text = msg;
    }
    void InicializedMessage()
    {
        message[0][0] = "Это же Робот !\nжми на эту кнопку\nнадо поскорее избавиться от него";
        message[0][1] = "Здесь будет проще\nскорей нажимай на кнопку\nперепрыгнем этот кубик !";
        message[0][2] = "Все просто !\nКаждый игрок может пройти только через барьер своего цвета\nИспользуй кнопки сбоку экрана";
        message[0][3] = "Всё тоже самое\nНо теперь у тебя нет права на ошибку";
        message[0][4] = "Смелее !\nТы же уже умеешь прыгать";
        message[0][5] = "Эта штука очень быстрая ты можешь не успеть перепрыгнуть\nлучше телепортируйся через неё, но не забывай\nчто после, эта способность будет недоступна некоторое время";
        message[0][6] = "Приготовься к ускорению !";
        message[0][7] = "Тебе лучше пригнуться\nесли хочешь продолжить бежать";
        message[0][8] = "Смотри за камнями на земле\nОни подскажут когда ждать опасности";
        message[0][9] = "Эта машина очень далеко стреляет\nно уверен ты сможешь справится";

        message[1][0] = "It's Robot!\nClick on this button\nyou need to get rid of it as soon as possible";
        message[1][1] = "Here it will be easier\nto press the button more quickly and jump this cube!";
        message[1][2] = "It's simple!\nEach player can only pass through the barrier of his color\nUse the buttons on the side of the screen";
        message[1][3] = "All the same thing\nBut now you don't have the right to make a mistake";
        message[1][4] = "More brave!\nYou already know how to jump";
        message[1][5] = "This thing is very fast you may not have time to jump over\nbetter teleport through it, but do not forget\nthat after, this ability will be unavailable for a while";
        message[1][6] = "Prepare for acceleration!";
        message[1][7] = "You'd better duck\nif you want to keep running";
        message[1][8] = "Watch the rocks on the ground\nThey'll tell you when to wait for danger";
        message[1][9] = "This machine shoots very far away\nbut I'm sure you can handle it";
    }

    public static void PlayAnimation()
    {
        anim[typeAnimation]();
    }

    GameObject FindPortal(GameObject obj)
    {
        foreach (SpriteRenderer rec in obj.GetComponentsInChildren<SpriteRenderer>())
            if (rec.CompareTag("Right"))
                return rec.gameObject;
        return null;
    }
    GameObject FindBarrier(GameObject obj)
    {
        foreach (RectTransform rec in obj.GetComponentsInChildren<RectTransform>())
            if (rec.CompareTag("Right"))
                return rec.gameObject;
        return null;
    }

    public static void SetDefaultSortingLayer()
    {
        if(sortingLayerObj)
          sortingLayerObj.GetComponent<SpriteRenderer>().sortingOrder = 1;
    }

    void SetButtonImage(Sprite sp)
    {
        imageButtons[1].GetComponent<Image>().sprite = sp;
    }

    public static void SetActiveImageButtons(bool val)
    {
        imageButtons[0].SetActive(val);
        imageButtons[2].SetActive(val);
    }

    IEnumerator IfTeleport()
    {
        while (MessageSystemPlayingScene.IsTeleport)
            yield return null;
        StopGame();
        sortingLayerObj = null;

        panel.SetActive(true);
        isCollision = true;

        
    }

    void SetFontMaxSize(int size)
    {
        txt.resizeTextMaxSize = size;
    }

    void SaveConstraints()
    {
        saveConstr = MessageSystemPlayingScene.Player.GetComponent<Rigidbody2D>().constraints;
    }

    public static void RestoreConstraints()
    {
        MessageSystemPlayingScene.Player.GetComponent<Rigidbody2D>().constraints = saveConstr;
    }
}
