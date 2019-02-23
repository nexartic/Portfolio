using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelCollider : ScrollLevel {

    static bool inCollider;


    private void Start()
    {
        inCollider = false;
    }
    public static bool InCollider
    {
        get
        {
            return inCollider;
        }
    }

    private void OnTriggerEnter(Collider collision)
    {
        if (collision.gameObject.CompareTag("Level"))
        {
            inCollider = true;
            if (collision.gameObject.name == "Up")
                numberOperation = 1;
            if (collision.gameObject.name == "Down")
                numberOperation = 2;
        }
    }

    private void OnTriggerExit(Collider collision)
    {
        if (collision.gameObject.CompareTag("Level"))
        {
            inCollider = false;
            numberOperation = 0;
        }
    }
}
