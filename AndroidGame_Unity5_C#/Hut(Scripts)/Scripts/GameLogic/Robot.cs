using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Robot : MonoBehaviour {

    bool isOne;
    [SerializeField] GameObject robot;
    RobotDead robDead;

    private void Start()
    {
        robDead = robot.GetComponent<RobotDead>();
    }

    public bool IsOne
    {
        get
        {
            return isOne;
        }

        set
        {
            isOne = value;
        }
    }


    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isOne)
        {
            isOne = true;
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDeath", true);
            MessageSystemPlayingScene.GeneralyPartOfDeath();
            robDead.Death();
        }
        if (collision.gameObject.CompareTag("Hit") && !isOne)
        {
            isOne = true;
            robDead.Death();
        }
    }

    public void DisableEnemy()
    {
        gameObject.SetActive(false);
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
