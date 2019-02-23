using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Barrier : MonoBehaviour {

    BoxCollider2D box;
    private void Start()
    {
        box = GetComponent<BoxCollider2D>();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit"))
            if(collision.gameObject.name != tag)
               box.isTrigger = false;
    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit"))
            if (collision.gameObject.name == tag && !MessageSystemPlayingScene.IsJump)
            {
                MessageSystemPlayingScene.SetDefaultConstraints();
            }
    }

    private void OnCollisionStay2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit"))
            if (collision.gameObject.name == tag && !MessageSystemPlayingScene.IsJump)
            {
                MessageSystemPlayingScene.SetDefaultConstraints();
            }
    }
}
