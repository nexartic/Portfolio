using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Generate : MonoBehaviour {

    Levels[] levels = new Levels[5];
    int[] timeToNewLevel = new int[3] { 30, 120, 240 };
    DelegateStorage newLevel = new DelegateStorage();
    DelegateStorage printTime = new DelegateStorage();
    public delegate void TimeDelegate();
    public static TimeDelegate timeDelegate;
    [SerializeField] GameObject nextLevel;
    [SerializeField] GameObject timeTxt;
    static int level;
    Text time;

    public static int Level
    {
        set
        {
            level = value;
        }

        get
        {
            return level;
        }
    }

    private void Start()
    {
        timeDelegate = new TimeDelegate(StartTime);
        time = timeTxt.GetComponent<Text>();
        levels[0] = new Level_0();
        levels[1] = new Level_1();
        levels[2] = GetComponent<Level_2>();
        levels[3] = GetComponent<Level_3>();
        levels[4] = GetComponent<Level_4>();
        newLevel.InstMemory("void", 6, 1);
        newLevel[1, 0] = (p) =>
         {
             if (MessageSystemGameBlock.GameTime >= timeToNewLevel[0])
             {
                 nextLevel.SetActive(true);
                 time.text = "0";
                 level = 5;
                 OpenNewLevel();
             }
         };
        newLevel[2, 0] = (p) =>
         {
             if (MessageSystemGameBlock.GameTime >= timeToNewLevel[1])
             {
                 nextLevel.SetActive(true);
                 time.text = "0";
                 level = 5;
                 OpenNewLevel();
             }
         };
        newLevel[3, 0] = (p) =>
         {
             if (MessageSystemGameBlock.GameTime >= timeToNewLevel[2])
             {
                 nextLevel.SetActive(true);
                 time.text = "0";
                 level = 5;
                 OpenNewLevel();
             }
         };
        newLevel[0, 0] = (p) => { };
        newLevel[4, 0] = (p) => { };
        newLevel[5, 0] = (p) =>
         {
             if (NextLevel.IsPressed)
             {
                 NextLevel.IsPressed = false;
                 MessageSystemGameBlock.LEVEL++;
                 MessageSystemGameBlock.GameTime = 0;
                 level = MessageSystemGameBlock.LEVEL;
                 TapToLevel.SetNumberLevel();
             }
         };
        printTime.InstMemory("void", 6, 1);
        printTime[0, 0] = (p) => time.text = Cut(MessageSystemGameBlock.GameTime).ToString();
        printTime[1, 0] = (p) => time.text = Cut((timeToNewLevel[0] - MessageSystemGameBlock.GameTime)).ToString();
        printTime[2, 0] = (p) => time.text = Cut((timeToNewLevel[1] - MessageSystemGameBlock.GameTime)).ToString();
        printTime[3, 0] = (p) => time.text = Cut((timeToNewLevel[2] - MessageSystemGameBlock.GameTime)).ToString();
        printTime[4, 0] = (p) => time.text = Cut(MessageSystemGameBlock.GameTime).ToString();
        printTime[5, 0] = (p) => { };
    }
    void StartTime()
    {
        StartCoroutine(Time());
    }
    IEnumerator Time()
    {
        printTime[Level, 0]();
        yield return null;
        if (MessageSystemGameBlock.IndexWatch == 0)
        {
            StartCoroutine(Time());
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        Generation(collision.gameObject);  
    }

    public void SetHint(GameObject returnObj)
    {
        if (returnObj != null)
        {
            foreach (RectTransform b in returnObj.GetComponentsInChildren<RectTransform>())
                if (b.CompareTag("Hint"))
                {
                    Hint.SetHint(b.gameObject);
                }
        }
    }

    public  void Generation(GameObject gameBlock)
    {
        newLevel[Level, 0]();
        GameObject obj = gameBlock;
        Levels level;
        if (obj.gameObject.CompareTag("DownEarth"))
        {
            level = levels[MessageSystemGameBlock.LEVEL];
            SetHint(level.Generate(obj));
        }
    }

    float Cut(float num)
    {
        num *= 100;
        num = (int)num;
        return Mathf.Abs(num /= 100);
    }

    void OpenNewLevel()
    {
        string key = "Level_" + (MessageSystemGameBlock.LEVEL + 1).ToString();
        if (!PlayerPrefs.HasKey(key))
        {
            PlayerPrefs.SetInt(key, 1);
            OpenedLevels.Activate();
        }
    }
}

