using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Saw : MonoBehaviour {

    bool isOne;

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.layer == 10 && !isOne)
        {
            isOne = true;
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDeath", true);
            MessageSystemPlayingScene.GeneralyPartOfDeath();
        }
        if (collision.gameObject.layer == 9 && !isOne)
        {
            GetComponent<CircleCollider2D>().enabled = false;
        }
    }

    private void OnDisable()
    {
        GetComponent<CircleCollider2D>().enabled = true;
        isOne = false;
    }
}
