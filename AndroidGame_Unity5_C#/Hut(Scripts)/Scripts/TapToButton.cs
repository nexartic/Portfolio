using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToButton : MonoBehaviour {

    float changeScale = 50;
    float defaultScale;

    private void Start()
    {
        defaultScale = transform.localScale.x;
    }

    private void OnMouseDown()
    {
        if (!StopCollider.IsCollision)
        {
            if (!MessageSystemPlayingScene.IsDead)
                WaitingScreen.wait(MessageSystemPlayingScene.DisableCollider());
            transform.localScale = new Vector3(changeScale, changeScale, 1);
        }
    }

    private void OnMouseUp()
    {
        transform.localScale = new Vector3(defaultScale, defaultScale, 1);
    }
}
