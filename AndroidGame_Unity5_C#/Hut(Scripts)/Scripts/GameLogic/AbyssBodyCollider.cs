using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AbyssBodyCollider : MonoBehaviour {

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !MessageSystemPlayingScene.inPingPong)
        {
            MessageSystemPlayingScene.InBodyColider = true;
            MessageSystemGameBlock.SetPlayingConstraints();
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !MessageSystemPlayingScene.IsJump)
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
    }
}
