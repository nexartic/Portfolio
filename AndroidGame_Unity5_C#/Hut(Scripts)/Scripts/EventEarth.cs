using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EventEarth : MonoBehaviour {

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
        GameObject obj = collision.gameObject;

        if (PlayerZone.IsOutside && !MessageSystemPlayingScene.Player.CompareTag("InVisible") && !MessageSystemPlayingScene.IsDead)
        {
            PlayerZone.MoveToPlayerZone();
        }
        if ((obj.CompareTag("Player") || (obj.CompareTag("Hit") && obj.name == "Brian")) && MessageSystemPlayingScene.IsJump)
        {
            MessageSystemPlayingScene.exitFromPingPong = false;
            if (!PlayerZone.IsOutside)
                MessageSystemPlayingScene.SetDefaultConstraints();
            else
            {
                MessageSystemGameBlock.SetPlayingConstraints();
            }
            if (Conecting.Management == 0 && !TapToGo.Screen.activeInHierarchy)
            {
                TapToGo.Screen.SetActive(true);
            }
            MessageSystemPlayingScene.IsJump = false;
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", true);
            StartCoroutine(PreparationToJump());
        }

    }
}
