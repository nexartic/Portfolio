using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayOnMusicPanel : MonoBehaviour {

    [SerializeField] AudioClip clip;
    [SerializeField] Sprite[] sprite;
    static GameObject lastPlay;
    delegate void Play();
    Play[] play = new Play[2];
    float changeScale = 0.1f;
    Image img;
    int isPressed = 0;

    private void Start()
    {
        isPressed = 0;

        img = GetComponent<Image>();
        play[0] = () =>
        {
            if (lastPlay != null)
            {
                lastPlay.GetComponent<Image>().sprite = sprite[0];
                lastPlay.GetComponent<PlayOnMusicPanel>().isPressed = 0;
            }
            img.sprite = sprite[1];
            MessageSystemPlayingScene.PlayClip(clip);
            lastPlay = gameObject;
            isPressed = 1;
        };
        play[1] = () =>
        {
            img.sprite = sprite[0];
            MessageSystemPlayingScene.StopClip();
            isPressed = 0;
            lastPlay = null;
        };
    }

    private void OnMouseDown()
    {
        Hint.PlayClip();
        transform.localScale += new Vector3(changeScale, changeScale, 0);
    }

    private void OnMouseUp()
    {
        transform.localScale -= new Vector3(changeScale, changeScale, 0);
        play[isPressed]();
    }
}
