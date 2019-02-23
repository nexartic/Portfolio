using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hint : MonoBehaviour {

    public delegate void Set(GameObject obj);
    public static Set SetHint;
    static AudioSource clip;
    static bool isInstal;

    private void Start()
    {
        clip = GetComponent<AudioSource>();
        SetHint = new Set(InstHint);
        if (Conecting.Music == 0)
        {
            SetupVolume(0);
        }
        else
        {
            SetupVolume();
        }
        isInstal = true;
    }

    public void InstHint(GameObject obj)
    {
        RectTransform hintRecTrans = GetComponent<RectTransform>();
        RectTransform objRecTrans = obj.GetComponent<RectTransform>();
        SpriteRenderer hintSprite = GetComponent<SpriteRenderer>();

        hintSprite.sprite = obj.GetComponent<SpriteRenderer>().sprite;
        MessageSystemGameBlock.CopyRecTransform(hintRecTrans, objRecTrans);
    }

    public static void PlayClip()
    {
        clip.Play();
    }

    public static void SetupVolume(int delta = 1)
    {
          clip.volume *= Conecting.Volume * delta;
    }

    public static void SetDefaultValue()
    {
        isInstal = false;
    }
}
