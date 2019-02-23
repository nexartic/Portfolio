using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Screens : MonoBehaviour {

    Vector3 downPosition;
    Vector3 upPosition;
    Vector3 direction;
    bool isSwipe;

    private void Start()
    {
        isSwipe = false;
    }
    private void Update()
    {
        if (MessageSystemPlayingScene.IsStart && isSwipe)
        {
            upPosition = Input.mousePosition;
            float deltaX, deltaY;
            byte swipeLenght = 5;
            deltaX = downPosition.x - upPosition.x;
            deltaY = downPosition.y - upPosition.y;
            if ((Mathf.Abs(deltaX) > swipeLenght || Mathf.Abs(deltaY) > swipeLenght))
            {
                isSwipe = false;
                if (Mathf.Abs(deltaX) > Mathf.Abs(deltaY))// горизонтальный свайп
                {
                    StartCoroutine(Teleport(deltaX));
                }
                else if (Mathf.Abs(deltaX) < Mathf.Abs(deltaY))// вертикальный свайп
                {
                    if (deltaY < 0)// Jump
                    {
                        StartCoroutine(Jump());
                    }
                    else// Slip
                    {
                        StartCoroutine(Slip());
                    }
                }
            }
        }
    }

    private void OnMouseDown()
    {
        isSwipe = true;
        downPosition = Input.mousePosition;
    }

    private void OnMouseUp()
    {
        upPosition = Input.mousePosition;

        if (downPosition == upPosition)// Hit
        {
            MessageSystemPlayingScene.Hit();
            isSwipe = false;
            DisableScreen();
        }
        isSwipe = false;
    }

    IEnumerator Jump()
    {
        yield return new WaitForEndOfFrame();
        MessageSystemPlayingScene.Jump();
        DisableScreen();
    }

    IEnumerator Slip()
    {
        yield return new WaitForEndOfFrame();
        MessageSystemPlayingScene.Slip();
        DisableScreen();
    }

    IEnumerator Teleport(float deltaX)
    {
        yield return new WaitForEndOfFrame();
        if (deltaX < 0)//Teleport
        {
            MessageSystemPlayingScene.Teleport();
            if(!MessageSystemPlayingScene.IsTeleport)
               DisableScreen();
        }
    }

    void DisableScreen()
    {
        gameObject.SetActive(false);
        WaitingScreen.wait(gameObject);
    }
}
