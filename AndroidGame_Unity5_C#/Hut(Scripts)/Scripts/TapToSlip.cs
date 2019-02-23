using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToSlip : MonoBehaviour {

    private void OnMouseDown()
    {
        MessageSystemPlayingScene.Slip();
    }
}
