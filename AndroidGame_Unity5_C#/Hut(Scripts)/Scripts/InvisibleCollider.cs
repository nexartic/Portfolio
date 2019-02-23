using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InvisibleCollider : MonoBehaviour {

    static bool isOut;

    public static bool IsOut
    {
        get
        {
            return isOut;
        }

        set
        {
            isOut = value;
        }
    }

    private void Start()
    {
        isOut = false;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        GameObject obj = collision.gameObject;
        if (obj.layer == 10 || obj.layer == 9)
        {
            isOut = true;
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        GameObject obj = collision.gameObject;
        if (obj.layer == 10 || obj.layer == 9)
        {
            isOut = false;
        }
    }
}
