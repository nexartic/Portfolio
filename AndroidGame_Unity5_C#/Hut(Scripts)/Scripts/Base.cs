using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Base : MonoBehaviour {

    static GameObject[] buttons;

	void Awake ()
    {
        buttons = new GameObject[4];
        buttons[0] = GameObject.Find("Interface/Buttons/Hit");
        buttons[1] = GameObject.Find("Interface/Buttons/Slip");
        buttons[2] = GameObject.Find("Interface/Buttons/Teleport");
        buttons[3] = GameObject.Find("Interface/Buttons/Jump");
        foreach (GameObject obj in buttons)
            obj.SetActive(false);
    }

    protected static void DisableButtons()
    {
        if (Conecting.Management == 1 && MessageSystemPlayingScene.IsStart)
        {
            foreach (GameObject obj in buttons)
                obj.SetActive(false);
        }
    }

    protected static void EnableButtons()
    {
        if (Conecting.Management == 1 && MessageSystemPlayingScene.IsStart)
        {
            foreach (GameObject obj in buttons)
                obj.SetActive(true);
        }
    }
}
