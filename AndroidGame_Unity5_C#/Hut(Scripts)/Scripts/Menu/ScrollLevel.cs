using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScrollLevel : MonoBehaviour {

    const float speedReturning = 4;
    static Vector3 pressDown,pressDrag;
    static GameObject levelManager;
    static float offset;
    protected static int numberOperation;
    delegate void Scroll();
    static Scroll[] scroll;
    static bool isPress;

    private void Start()
    {
        offset = 0;
        numberOperation = 0;
        isPress = false;

        if (name == "LevelManager")
        {
            levelManager = gameObject;
        }
        scroll = new Scroll[3];
        scroll[0] = () =>
        {
            levelManager.transform.localPosition += new Vector3(0, offset, 0);
        };

        scroll[1] = () =>
        {
            if(offset < 0)
                levelManager.transform.localPosition += new Vector3(0, offset, 0);
        };

        scroll[2] = () =>
        {
            if (offset > 0)
                levelManager.transform.localPosition += new Vector3(0, offset, 0);
        };
    }

    private void OnMouseDown()
    {
        isPress = true;
        pressDown = Input.mousePosition;
    }

    private void Update()
    {
        if (isPress)
        {
            pressDrag = Input.mousePosition;
            offset = pressDrag.y - pressDown.y;
            scroll[numberOperation]();
            pressDown = pressDrag;
        }
    }

    private void OnMouseUp()
    {
        isPress = false;
        if (LevelCollider.InCollider)
        {
            StartCoroutine(Return());
        }
    }

    IEnumerator Return()
    {
        float speed = 20;
        while (levelManager.transform.localPosition.y > 86)
        {
            levelManager.transform.localPosition -= new Vector3(0, speed, 0);
            yield return null;
        }
        while (levelManager.transform.localPosition.y < -260)
        {
            levelManager.transform.localPosition += new Vector3(0, speed, 0);
            yield return null;
        }
    }

}
