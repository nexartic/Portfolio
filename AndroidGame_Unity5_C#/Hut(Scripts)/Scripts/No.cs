﻿using UnityEngine;
using System.Collections;

public class No : MonoBehaviour {

    float changeScale = 0.8f;
    private void OnMouseDown()
    {
        transform.localScale = new Vector3(changeScale, changeScale, changeScale);
    }
    private void OnMouseUp()
    {
        transform.localScale = new Vector3(1, 1, 1);
        MessageSystemMainScreen.CloseExitPanel();
        TapToExit.PlayClip();
    }
}
