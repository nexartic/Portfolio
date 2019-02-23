using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Background : MonoBehaviour {

    static GameObject backgroundSample;
    private static float delta;

    public static float Delta
    {
        get
        {
            return delta;
        }

    }

    private void Start()
    {
        backgroundSample = GameObject.Find("BackgroundUp");
        float deltaMinus = -0.011f;
        delta = backgroundSample.GetComponent<BoxCollider2D>().bounds.size.x + deltaMinus;
    }
}
