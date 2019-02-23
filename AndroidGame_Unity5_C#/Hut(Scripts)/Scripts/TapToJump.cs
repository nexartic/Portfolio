using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToJump : MonoBehaviour {

    private void OnMouseDown()
    {
        MessageSystemPlayingScene.Jump();  
    }
}
