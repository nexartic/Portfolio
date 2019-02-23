using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToGo : Base {

    Animation anim;
    [SerializeField] GameObject touchScreen;
    [SerializeField] GameObject pause;
    [SerializeField] GameObject menuPanel;
    static AudioSource source;
    static GameObject screen;
    static bool isInstal;

    public static GameObject Screen
    {
        get { return screen; }
        set { screen = value; }
    }


    private void Start()
    {
        source = GetComponent<AudioSource>();
        screen = touchScreen;
        anim = GetComponent<Animation>();
        if (Conecting.Music == 0)
            SetupVolume(0);
        else
            SetupVolume();
        isInstal = true;
    }
    private void OnMouseUp()
    {
        anim.Play("GoAway");
        if (!MessageSystemPlayingScene.IsStart)
        {
            menuPanel.SetActive(false);
            MessageSystemPlayingScene.StartGame();
            if (Conecting.Management == 0)
                screen.SetActive(true);
            else
            {
                StartCoroutine(EnButtons());
            }
            MessageSystemGameBlock.DisableAllBlock();
            Score.increeze();
        }
        else
        {
            MessageSystemGameBlock.StartAfterHit();
            MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 1;
            EnableButtons();
        }
        if (PlayerPrefs.HasKey("FirstStart"))
        {
            PauseGame.IsPause = false;
            pause.SetActive(true);
        }
        else
        {
            FirstStart.SetActiveStopCollider(true);
        }
        source.Play();
    }


    IEnumerator EnButtons()
    {
        yield return null;
        EnableButtons();
    }

    public static void SetActiveScreen(bool value)
    {
        if(Conecting.Management == 0)
          screen.SetActive(value);
    }

    public static void SetupVolume(int delta = 1)
    {
        source.volume *= Conecting.Volume * delta;
    }

    public static void SetDefaulValue()
    {
        isInstal = false;
    }

    public void DisactiveGameObject()
    {
        gameObject.SetActive(false);
    }
}
