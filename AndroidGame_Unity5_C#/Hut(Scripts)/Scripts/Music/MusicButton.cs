using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MusicButton : MonoBehaviour {

    [SerializeField] GameObject panel;
    [SerializeField] GameObject mainMusic;
    static GameObject staticMainMusic;
    float changeScale = 0.1f;

    private void Start()
    {
        staticMainMusic = mainMusic;
        if (Conecting.Music == 0)
        {
            DisableMusicButton();
        }
    }

    private void OnMouseDown()
    {
        Hint.PlayClip();
        transform.localScale += new Vector3(changeScale, changeScale, 0);
        panel.SetActive(!panel.activeInHierarchy);
    }

    private void OnMouseUp()
    {
        transform.localScale -= new Vector3(changeScale, changeScale, 0);
    }

    public static void DisableMusicButton()
    {
        staticMainMusic.SetActive(false);
    }
}
