using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToHit : MonoBehaviour {

    private void OnMouseDown()
    {
        MessageSystemPlayingScene.Hit();
    }
}
