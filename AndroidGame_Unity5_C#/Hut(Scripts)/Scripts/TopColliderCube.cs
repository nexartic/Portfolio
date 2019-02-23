using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TopColliderCube : MonoBehaviour {

    static bool onCube;

    public static bool OnCube
    {
        get
        {
            return onCube;
        }

        set
        {
            onCube = value;
        }
    }

    

    IEnumerator PreparationToJump()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsJumpUp", false);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsJumpDown", false);
        yield return new WaitForSeconds(0.4f);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", false);
        MessageSystemPlayingScene.EnableCollider();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (PlayerZone.IsOutside)
        {
            PlayerZone.MoveToPlayerZone();
        }
        if (collision.gameObject.CompareTag("Player") && MessageSystemPlayingScene.IsJump && !Cube.IsCollision)
        {
            MessageSystemPlayingScene.exitFromPingPong = false;
            if (!PlayerZone.IsOutside)
                MessageSystemPlayingScene.SetDefaultConstraints();
            else
            {
                MessageSystemGameBlock.SetPlayingConstraints();
            }
            MessageSystemPlayingScene.IsJump = false;
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", true);
            StartCoroutine(PreparationToJump());
        }
    }
    private void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player"))
        {
            onCube = true;
            MessageSystemPlayingScene.IsJump = true;
            MessageSystemGameBlock.SetPlayingConstraints();
        }
    }

    private void OnDestroy()
    {
        onCube = false;
    }
}
