using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Speedy : MonoBehaviour {

    bool isOne;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isOne)
        {
            isOne = true;
            MessageSystemPlayingScene.speedy();
        }
    }

    private void OnDisable()
    {
        isOne = false;
    }

}
