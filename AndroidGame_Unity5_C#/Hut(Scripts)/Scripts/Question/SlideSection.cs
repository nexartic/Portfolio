using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SlideSection : MonoBehaviour {

    [SerializeField] GameObject[] parentMass;
    [SerializeField] float maxPos, minPos;
    GameObject parent;
    int isPressed = 0;
    delegate void Slide();
    Slide[] slide = new Slide[2];
    float pressDown, pressUp,lastPos;

    private void Start()
    {
        isPressed = 0;
        pressDown = 0;
        pressUp = 0;
        lastPos = 0;

        parent = parentMass[0];
        slide[0] = () => { };
        slide[1] = () =>
        {
            pressUp = Input.mousePosition.y;
            float offset = pressUp - pressDown;
            offset = offset * Time.deltaTime / (Screen.height / 5);
            float futurePos = parent.transform.localPosition.y + offset;
            if (futurePos <= maxPos && futurePos >= minPos)
            {
                parent.transform.localPosition += new Vector3(0, offset, 0);
            };
            pressDown = pressUp;
        };
    }

    private void OnMouseDown()
    {
        isPressed = 1;
        pressDown = Input.mousePosition.y;
    }

    private void OnMouseUp()
    {
        isPressed = 0;
    }

    private void Update()
    {
        slide[isPressed]();
    }
}
