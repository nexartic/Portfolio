using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MessageSystemGameBlock : MonoBehaviour {

    const int size = 11;
    [SerializeField]GameObject[] StaticGameBlock;
	[SerializeField]GameObject[] Earth;
    [SerializeField]GameObject mainParent;
    [SerializeField] GameObject[] Buffer;
    static GameObject reserve;
    static GameBlock reserveBlock = new GameBlock();
    static GameObject parentUp, parentDown;
    static GameObject backgroundParent;
    Rigidbody2D mainRigid, backRigid;
    static float speed = 0;
    static float backgroundSpeed = 0;
    public static int LEVEL = 1;
    static float[] bufSpeed = new float[2];
    delegate GameBlock Property(int index);
    static Property[] property;
    string[] previous = new string[2];
    static GameObject canvasGameBlock;
    static bool isInicializeRobot;

    delegate void StopWatch();
    StopWatch[] stopWatch = new StopWatch[2];
    static float gameTime = 0;
    static int indexWatch = 1;

    static GameBlock[][] DinamicGameBlock = new GameBlock[size][];
    int[] countBlocks = new int[] {17,3,1,2};

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

    public static bool IsInicializeRobot
    {
        get
        {
            return isInicializeRobot;
        }

        set
        {
            isInicializeRobot = value;
        }
    }

    private void FixedUpdate()
    {
        mainRigid.velocity = new Vector2(-speed, 0);
        backRigid.velocity = new Vector2(-backgroundSpeed, 0);
        stopWatch[indexWatch]();
    }


    private void Start()
    {
        indexWatch = 1;
        reserve = GameObject.Find("Game'sBlock/Reserve/Portal_Grey");
        backgroundParent = GameObject.Find("Background/BackgroundParent");
        parentUp = GameObject.Find("Game'sBlock/MainParent/ParentUp");
        parentDown = GameObject.Find("Game'sBlock/MainParent/ParentDown");
        canvasGameBlock = GameObject.Find("Game'sBlock");
        mainRigid = mainParent.GetComponent<Rigidbody2D>();
        backRigid = backgroundParent.GetComponent<Rigidbody2D>();

        DinamicGameBlock[0] = new GameBlock[countBlocks[0]];//Earth
        DinamicGameBlock[1] = new GameBlock[countBlocks[3]];//Cube
        DinamicGameBlock[2] = new GameBlock[countBlocks[1]];//Barrier
        DinamicGameBlock[3] = new GameBlock[countBlocks[1]];//Portal
        DinamicGameBlock[4] = new GameBlock[countBlocks[3]];//Abyss
        DinamicGameBlock[5] = new GameBlock[countBlocks[3]];//Blade
		DinamicGameBlock[6] = new GameBlock[countBlocks[3]];//Speedy
        DinamicGameBlock[7] = new GameBlock[countBlocks[3]];//Saw
        DinamicGameBlock[8] = new GameBlock[countBlocks[3]];//Needles
        DinamicGameBlock[9] = new GameBlock[countBlocks[2]];//Enemy#1
        DinamicGameBlock[10] = new GameBlock[countBlocks[2]];//Robot
        for (int i = 0; i < size; i++)
            for (int j = 0; j < DinamicGameBlock[i].Length; j++)
                DinamicGameBlock[i][j] = new GameBlock();

        for (int i = 0; i < Earth.Length; i++)
        {
            DinamicGameBlock[0][i].SetValue(Earth[i],0);
            DinamicGameBlock[0][i].SetActive(true);
        }
        for (int i = 1, j = 0; i < size; i++, j++)
        {
            Instance(i, 0, j, StaticGameBlock);
        }

        for (int i = 0; i < 8; i++)
            Earth[i].transform.SetParent(parentUp.transform);

        for (int i = 8; i < Earth.Length; i++)// без 8 блока
            Earth[i].transform.SetParent(parentDown.transform);
        for(int i = 16; i < Earth.Length; i++)
            DinamicGameBlock[0][i].SetActiveFull(false);

        Instance(3, 1, 0, Buffer);
        Instance(3, 2, 1, Buffer);
        Instance(2, 1, 2, Buffer);
        Instance(2, 2, 3, Buffer);
        Instance(1, 1, 4, Buffer);
        for (int i = 5; i < 10; i++)
        {
            Instance(i - 1, 1, i, Buffer);
        }
        reserveBlock.SetValue(reserve, 0);
        reserveBlock.CalculateDelta();

        property = new Property[5];
        property[0] = new Property(ReturnDisactiveGameObject);
        property[1] = new Property(Any);
        property[2] = new Property(SamePrevious);
        property[3] = new Property(AnyBesidePrevious);
        property[4] = new Property(SamePreviousTwo);

        stopWatch[0] = () =>
        {
            gameTime += Time.deltaTime;
        };
        stopWatch[1] = () => { };
    }

    void Instance(int i1, int i2, int i3,GameObject[] mass)
    {
        DinamicGameBlock[i1][i2].SetValue(mass[i3],i1);
        DinamicGameBlock[i1][i2].CalculateDelta();
    }

    public static void DisableDinamicGameBlock(GameObject block, int index)
    {
        foreach (GameBlock obj in DinamicGameBlock[index])
        {
            if (obj.GetGameObject() == block)
                obj.SetActive(false);

        }
    }

    public static void SetupParent(GameObject block,bool parent)
    {
        if (block.CompareTag("DownEarth"))
            block.transform.SetAsFirstSibling();
        else
            block.transform.SetAsLastSibling();
        if (parent)
            block.transform.SetParent(parentUp.transform);
        else
            block.transform.SetParent(parentDown.transform);
    }

    public static GameBlock ReturnDisactiveGameObject(int index)
    {
        int i;
        bool isEnter = false;
        for ( i = 0; i < DinamicGameBlock[index].Length; i++)
        {
            if (!DinamicGameBlock[index][i].IsActive)
            {
                isEnter = true;
                break;
            }
        }

        if (!isEnter)
        {
           int rand = Random.Range(0, DinamicGameBlock[index].Length);
           i = IncreezeDinamicGameBlock(index,DinamicGameBlock[index][rand].GetGameObject());
        }

        return DinamicGameBlock[index][i];
    }

    public static GameObject ReturnDisactiveInParent(bool type)
    {

        if (type)
        {
            foreach (GameObject obj in parentUp.GetComponentsInChildren<GameObject>())
            {
                if (!obj.activeInHierarchy)
                    return obj;
            }
        }
        else
        {
            foreach (GameObject obj in parentDown.GetComponentsInChildren<GameObject>())
            {
                if (!obj.activeInHierarchy)
                    return obj;
            }
        }

        return null;
    }

    public static GameBlock ReturnDisactiveDownEarth()
    {
        foreach (GameBlock obj in DinamicGameBlock[0])
            if (!obj.IsActive && obj.GetGameObject().CompareTag("DownEarth"))
                return obj;
        return null;
    }
    public static void SaveSpeed()
    {
        if (speed != 0)
        {
            bufSpeed[0] = speed;
            bufSpeed[1] = backgroundSpeed;
        }
    }
    public static void StartGame()
    {
        Score.StopScore = false;
        Score.increeze();
        TapToGo.SetActiveScreen(true);
        StartStopWatch();
    }
    public static void StopGame()
    {
        ReverseMainParent.ReverseParent();
        Score.StopScore = true;
        speed = 0;
        backgroundSpeed = 0;
        TapToGo.SetActiveScreen(false);
        StopStopWatch();
    }
    public static void SetPlayingConstraints()
    {
        MessageSystemPlayingScene.Player.GetComponent<Rigidbody2D>().constraints = RigidbodyConstraints2D.FreezeRotation;
    }

    public static GameObject ReturnNearestEnemy()
    {
        GameObject enemy = new GameObject();
        foreach (RectTransform t in parentDown.GetComponentsInChildren<RectTransform>())
            if (t.name == "Robot" || t.name == "Enemy#1")
            {
                enemy = t.gameObject;
                foreach (RectTransform rec in enemy.GetComponentsInChildren<RectTransform>())
                    if (rec.GetComponent<Animator>())
                    {
                       return rec.gameObject;       
                    }
            }
        return null;
    }

    public static void ReturnEqualGameBlock(GameObject block,ref int first,ref int second)
    {
        for (int i = 0; i < DinamicGameBlock.Length; i++)
            for (int j = 0; j < DinamicGameBlock[i].Length; j++)
                if (DinamicGameBlock[i][j].GetGameObject() == block)
                {
                    first = i;
                    second = j;
                    return;
                }
    }

    public static void DisableDinamicGameBlock(int i, int j)
    {
        DinamicGameBlock[i][j].SetActiveFull(false);
    }

    public static GameBlock ReturnUnusedGameBlock(int index)
    {
        GameBlock nullGameBlock = new GameBlock();
        int countDisactiveBlock = 0;
        int localIndex = 0;
        for (int i = 0; i < DinamicGameBlock[index].Length; i++)
        {
            if (!DinamicGameBlock[index][i].IsActive)
            {
                countDisactiveBlock++;
                localIndex = i;
            }
        }

        if (countDisactiveBlock == 0)
        {
            return nullGameBlock;
        }
        else if (countDisactiveBlock == 1)
        {
            return DinamicGameBlock[index][localIndex];
        }
        else
        {
            int min = DinamicGameBlock[index][0].CountUsing;
            int minIndex = 0;
            for (int i = 1; i < DinamicGameBlock[index].Length; i++)
                if (min > DinamicGameBlock[index][i].CountUsing)
                {
                    min = DinamicGameBlock[index][i].CountUsing;
                    minIndex = i;
                }
            return DinamicGameBlock[index][minIndex];
        }
    }

    public static void DisableAllBlock()
    {
        for (int i = 1; i < DinamicGameBlock.Length; i++)
            for (int j = 0; j < DinamicGameBlock[i].Length; j++)
                DinamicGameBlock[i][j].SetActiveFull(false);
    }

    public static void StartAfterHit()
    {
        if (!MessageSystemPlayingScene.IsHit)
        {
            speed = bufSpeed[0];
            backgroundSpeed = bufSpeed[1];
            StartGame();
        }
    }
    //Any - 1; Same - 2; AnyBesidePreviouse - 3; SamePreviosueTwo - 4;
    public static GameBlock ReturnBlockFromGroup(int indexBlock, int index)
    {
        return property[index](indexBlock);
    }

    GameBlock Any(int index)
    {
        int count = 0;
        int lenght = DinamicGameBlock[index].Length;
        int[] mass = new int[lenght];

        for (int i = 0; i < lenght; i++)
            if (!DinamicGameBlock[index][i].IsActive && DinamicGameBlock[index][i].GetGameObject() != null)
            {
                mass[count] = i;
                count++;
            }
        int j = 0;
        if (count != 0)
        {
            int rand = Random.Range(0, count);
            j = mass[rand];
        }
        else
        {
            int rand = Random.Range(0, lenght);
            j = IncreezeDinamicGameBlock(index, DinamicGameBlock[index][rand].GetGameObject());
        }
        PutToPrevious(DinamicGameBlock[index][j].InvertName);
        if (DinamicGameBlock[index][j].IsActive)
            return reserveBlock;
        return DinamicGameBlock[index][j];
    }
    GameBlock SamePrevious(int index)
    {
        int k = 0;
        for (int i = 0; i < DinamicGameBlock[index].Length; i++)
            if (DinamicGameBlock[index][i].InvertName == previous[0])
            {
                k = i;
                if (!DinamicGameBlock[index][i].IsActive && DinamicGameBlock[index][i].GetGameObject() != null)
                {
                    PutToPrevious(DinamicGameBlock[index][i].InvertName);
                    return DinamicGameBlock[index][i];
                }
            }
        int j = IncreezeDinamicGameBlock(index,DinamicGameBlock[index][k].GetGameObject());
        PutToPrevious(DinamicGameBlock[index][j].InvertName);
        if (DinamicGameBlock[index][j].IsActive)
            return reserveBlock;
        return DinamicGameBlock[index][j];
        
    }
    GameBlock SamePreviousTwo(int index)
    {
        int k = 0;
        for (int i = 0; i < DinamicGameBlock[index].Length; i++)
            if (DinamicGameBlock[index][i].InvertName == previous[1])
            {
                k = i;
                if (!DinamicGameBlock[index][i].IsActive && DinamicGameBlock[index][i].GetGameObject() != null)
                {
                    PutToPrevious(DinamicGameBlock[index][i].InvertName);
                    return DinamicGameBlock[index][i];
                }
            }
        int j = IncreezeDinamicGameBlock(index, DinamicGameBlock[index][k].GetGameObject());
        PutToPrevious(DinamicGameBlock[index][j].InvertName);
        if (DinamicGameBlock[index][j].IsActive)
            return reserveBlock;
        return DinamicGameBlock[index][j];
    }
    GameBlock AnyBesidePrevious(int index)
    {
        int count = 0;
        int lenght = DinamicGameBlock[index].Length;
        int[] mass = new int[lenght];
        int k = 0;

        for (int i = 0; i < lenght; i++)
            if (DinamicGameBlock[index][i].InvertName != previous[0])
            {
                k = i;
                if (!DinamicGameBlock[index][i].IsActive && DinamicGameBlock[index][i].GetGameObject() != null)
                {
                    count++;
                    mass[count] = i;
                }
            }
        PutToPrevious(DinamicGameBlock[index][k].InvertName);
        int j;
        if (count != 0)
        {
            int rand = Random.Range(0, count);
            j = mass[rand];
        }
        else
        {
            j = IncreezeDinamicGameBlock(index, DinamicGameBlock[index][k].GetGameObject());
        }
        if (DinamicGameBlock[index][j].IsActive)
            return reserveBlock;
        return DinamicGameBlock[index][j];
    }
    void PutToPrevious(string name)
    {
        previous[1] = previous[0];
        previous[0] = name;
    }

    static int IncreezeDinamicGameBlock(int index, GameObject gameBlock)
    {
        GameBlock[] block = DinamicGameBlock[index];
        if (block[block.Length - 1].GetGameObject() != null)
        {
            int lenght = DinamicGameBlock[index].Length;
            DinamicGameBlock[index] = new GameBlock[lenght * 2];
            block.CopyTo(DinamicGameBlock[index], 0);
            for (int i = block.Length; i < DinamicGameBlock[index].Length; i++)
                DinamicGameBlock[index][i] = new GameBlock();
        }

        if (gameBlock == null)
        {
            gameBlock = reserve;
        }
        GameObject obj = Instantiate(gameBlock,gameBlock.transform) as GameObject;
        int j;
        for (j = 0; j < DinamicGameBlock[index].Length; j++)
            if (DinamicGameBlock[index][j].GetGameObject() == null)
                break;
        GameBlock newBlock = DinamicGameBlock[index][j];
        newBlock.SetValue(obj,index);
        newBlock.CalculateDelta();
        newBlock.SetActiveFull(false);
        newBlock.Name = gameBlock.name;
        newBlock.GetGameObject().transform.SetParent(canvasGameBlock.transform);
        CopyRecTransform(newBlock.GetGameObject().GetComponent<RectTransform>(), DinamicGameBlock[index][0].GetGameObject().GetComponent<RectTransform>());
        return j;       
    }

    public static void CopyRecTransform(RectTransform to, RectTransform from)
    {
        to.anchorMax = from.anchorMax;
        to.anchorMin = from.anchorMin;
        to.offsetMin = from.offsetMin;
        to.offsetMax = from.offsetMax;
        to.localScale = from.localScale;
        to.localRotation = from.rotation;
        to.sizeDelta = from.sizeDelta;
    }
    public static void StartStopWatch()
    {
        indexWatch = 0;
        Generate.timeDelegate();
        TapToLevel.SetNumberLevel();
    }
    public static void StopStopWatch()
    {
        indexWatch = 1;
    }

    public static float GameTime
    {
        get
        {
            return gameTime;
        }

        set
        {
            gameTime = value;
        }
    }

    public static int IndexWatch
    {
        get
        {
            return indexWatch;
        }
    }

    public static void SetDefaultValue()
    {
        speed = 0;
        backgroundSpeed = 0;
        gameTime = 0;
        isInicializeRobot = false;
    }

    public static void ChangeLayerRight(int layer)
    {
        foreach (GameBlock b in DinamicGameBlock[2])
            if (b.IsActive)
                b.ChangeLayerRight(layer);

        foreach (GameBlock b in DinamicGameBlock[3])
            if (b.IsActive)
                b.ChangeLayerRight(layer);
    }

    private void OnDestroy()
    {
        isInicializeRobot = false;
    }
}
