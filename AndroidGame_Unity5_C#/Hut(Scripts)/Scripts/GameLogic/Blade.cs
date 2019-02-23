using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Blade : MonoBehaviour {

    bool isOne;

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isOne)
        {
            isOne = true;
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDefaultDeath", true);
            MessageSystemPlayingScene.GeneralyPartOfDeath();
        }
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
