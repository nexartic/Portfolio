using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenedLevels : MonoBehaviour {

    static bool[] openedLevels = new bool[5] { true, true, false, false, false };
    public delegate void ActivateLevels();
    static ActivateLevels activate;
    [SerializeField] GameObject close;

    public static bool[] OpenedLevel
    {
        get
        {
            return openedLevels;
        }
    }

    public static ActivateLevels Activate
    {
        get
        {
            return activate;
        }
    }

    private void Start()
    {

        activate = new ActivateLevels(ActivateLevel);

        if (PlayerPrefs.HasKey(name))
        {
            ActivateLevel();
        }
    }

    public void ActivateLevel()
    {
        openedLevels[name[name.Length - 1] - '0'] = true;
        close.SetActive(false);
    }
}
