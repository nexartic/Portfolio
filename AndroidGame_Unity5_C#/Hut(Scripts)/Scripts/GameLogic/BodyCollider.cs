using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BodyCollider : MonoBehaviour {

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if ((collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit")) && !MessageSystemPlayingScene.inPingPong && !MessageSystemPlayingScene.IsJump)
        {
            MessageSystemPlayingScene.InBodyColider = true;
            MessageSystemGameBlock.SetPlayingConstraints();
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if ((collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit")) && !MessageSystemPlayingScene.inPingPong && !MessageSystemPlayingScene.IsJump && !TopColliderCube.OnCube)
        {
            if (!PlayerZone.IsOutside)
                MessageSystemPlayingScene.SetDefaultConstraints();
            else
            {
                MessageSystemGameBlock.SetPlayingConstraints();
            }
            MessageSystemPlayingScene.SetVisibleImagePlayer(true);
            MessageSystemPlayingScene.InBodyColider = false;
        }
        else if (collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit"))
        {
            TopColliderCube.OnCube = false;
            MessageSystemPlayingScene.SetVisibleImagePlayer(true);
            MessageSystemPlayingScene.InBodyColider = false;
        }
    }
}
