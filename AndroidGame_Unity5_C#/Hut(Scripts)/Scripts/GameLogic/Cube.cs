using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cube : MonoBehaviour {

    bool isOne;
    static bool isCollision;

    private void Start()
    {
        isCollision = false;
    }

    public static bool IsCollision
    {
        get
        {
            return isCollision;
        }
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isOne)
        {
            isCollision = true;
            isOne = true;
            Death();
        }
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player"))
            isCollision = false;
    }

    public void Death()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDefaultDeath", true);
        MessageSystemPlayingScene.GeneralyPartOfDeath();
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
