using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PauseGame : Base {

    [SerializeField] GameObject Go;
    static GameObject I;
    static bool isPause;

    private void Start()
    {
        isPause = false;
        I = gameObject;
    }
    public static bool IsPause
    {
        get
        {
            return isPause;
        }

        set
        {
            isPause = value;
        }
    }

    private void OnMouseDown()
    {
        Hint.PlayClip();
        DisableButtons();
        isPause = true;
        MessageSystemGameBlock.SaveSpeed();
        MessageSystemGameBlock.StopGame();
        MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 0;
        Go.SetActive(true);
        gameObject.SetActive(false);
    }

    public static void SetActivePause(bool num)
    {
        if(I != null)
          I.SetActive(num);
    }
}
