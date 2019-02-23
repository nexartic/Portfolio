using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyHit : MonoBehaviour {

    bool isOne;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isOne)
        {
            isOne = true;
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDeath", true);
            MessageSystemPlayingScene.GeneralyPartOfDeath();
            GetComponent<Animator>().SetBool("IsDeath", true);
        }
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
