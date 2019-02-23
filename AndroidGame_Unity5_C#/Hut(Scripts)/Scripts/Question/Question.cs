using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Question : Base {

    [SerializeField] GameObject parentPanel;
    static GameObject menu,question;
    delegate void Education();
    Education[] education = new Education[2];
    static int numberOperation = 0;

	void Start ()
    {
        menu = GameObject.Find("DisableScreen/Menu/Enter");
        question = GameObject.Find("DisableScreen/Question/Question");
        education[0] = () =>
        {
            if (MessageSystemPlayingScene.IsStart && !PauseGame.IsPause)
            {
                MessageSystemGameBlock.SaveSpeed();
                MessageSystemGameBlock.StopGame();
                MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 0;
            }
            DisableButtons();
            menu.SetActive(false);
            question.SetActive(false);
            PauseGame.SetActivePause(false);
            parentPanel.SetActive(true);
            numberOperation = 1;
        };
        education[1] = () =>
        {
            if (MessageSystemPlayingScene.IsStart && !PauseGame.IsPause)
            {
                MessageSystemGameBlock.StartAfterHit();
                MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 1;
            }
            EnableButtons();
            numberOperation = 0;
            parentPanel.SetActive(false);
            if(!PauseGame.IsPause)
              PauseGame.SetActivePause(true);
            menu.SetActive(true);
            question.SetActive(true);
        };
	}

    private void OnMouseDown()
    {
        Hint.PlayClip();
        education[numberOperation]();
    }

    public static void DisableMenuAndQuestion()
    {
        menu.SetActive(false);
        question.SetActive(false);
    }

    private void OnDestroy()
    {
        numberOperation = 0;
    }
}
