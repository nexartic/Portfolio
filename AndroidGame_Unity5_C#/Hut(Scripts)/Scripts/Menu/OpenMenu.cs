using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenMenu : MonoBehaviour {

    [SerializeField] GameObject menu;
    [SerializeField] GameObject blockForMenu;
    [SerializeField] GameObject question;
    public delegate void Open();
    public static Open[] open;
    static int numberOperation;

    public  static int NumberOperation
    {
        set
        {
            numberOperation = value;
        }

        get
        {
            return numberOperation;
        }
    }

    private void Start()
    {
        numberOperation = 0;
        open = new Open[4];
        open[0] = () =>
        {
            StartCoroutine(ToOpen());
        };

        open[1] = () =>
        {
            StartCoroutine(Close());
        };

        open[2] = () =>
        {
            StartCoroutine(OpenAfterPlay());
        };

        open[3] = () =>
        {
            StartCoroutine(CloseAfterPlay());
        };
    }

    private void OnMouseDown()
    {
        Hint.PlayClip();
        open[numberOperation]();
    }

    IEnumerator Close()
    {
        blockForMenu.SetActive(false);
        Animation anim = menu.GetComponent<Animation>();
        anim["OpenMenu"].time = anim["OpenMenu"].length;
        anim["OpenMenu"].speed = -1;
        anim.Play("OpenMenu");
        yield return new WaitForSeconds(anim["OpenMenu"].length);
        menu.SetActive(false);
        numberOperation = 0;
        CloseMenu.NumberOperation = 0;
        PauseGame.SetActivePause(true);
        question.SetActive(true);
    }

    IEnumerator ToOpen()
    {
        question.SetActive(false);
        PauseGame.SetActivePause(false);
        menu.SetActive(true);
        Animation anim = menu.GetComponent<Animation>();
        anim["OpenMenu"].time = 0;
        anim["OpenMenu"].speed = 1;
        anim.Play("OpenMenu");
        yield return new WaitForSeconds(anim["OpenMenu"].length);
        blockForMenu.SetActive(true);
        numberOperation = 1;
        CloseMenu.NumberOperation = 1;
    }

    IEnumerator OpenAfterPlay()
    {
        question.SetActive(false);
        PauseGame.SetActivePause(false);

        if (!PauseGame.IsPause)
        {
            MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 0;
            MessageSystemGameBlock.SaveSpeed();
            MessageSystemGameBlock.StopGame();
        }
        MessageSystemGameBlock.ChangeLayerRight(0);
        menu.SetActive(true);
        Animation anim = menu.GetComponent<Animation>();
        anim["OpenMenuDuringPlay"].time = 0;
        anim["OpenMenuDuringPlay"].speed = 1;
        anim.Play("OpenMenuDuringPlay");
        yield return new WaitForSeconds(anim["OpenMenuDuringPlay"].length);
        blockForMenu.SetActive(true);
        numberOperation = 3;
        CloseMenu.NumberOperation = 1;
    }

    IEnumerator CloseAfterPlay()
    {
        MessageSystemGameBlock.ChangeLayerRight(1);
        blockForMenu.SetActive(false);
        Animation anim = menu.GetComponent<Animation>();
        anim["OpenMenuDuringPlay"].time = anim["OpenMenuDuringPlay"].length;
        anim["OpenMenuDuringPlay"].speed = -1;
        anim.Play("OpenMenuDuringPlay");
        yield return new WaitForSeconds(anim["OpenMenuDuringPlay"].length);
        menu.SetActive(false);
        numberOperation = 2;
        CloseMenu.NumberOperation = 0;
        if (!PauseGame.IsPause)
        {
            MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 1;
            MessageSystemGameBlock.StartAfterHit();
            PauseGame.SetActivePause(true);
        }
        question.SetActive(true);
    }

    public static void PressAtMenu()
    {
        Hint.PlayClip();
        open[numberOperation]();
    }
}
