using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Earth : MonoBehaviour{

    static GameObject earthSample;
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
        earthSample = GameObject.Find("EarthUp(0)");
        float deltaMinus = -0.065f;
        delta = earthSample.GetComponent<BoxCollider2D>().bounds.size.x + deltaMinus;
    }

    
}
