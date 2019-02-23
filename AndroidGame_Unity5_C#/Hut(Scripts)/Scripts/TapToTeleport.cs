using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToTeleport : MonoBehaviour {

    private void OnMouseDown()
    {
        MessageSystemPlayingScene.Teleport();
    }
}
