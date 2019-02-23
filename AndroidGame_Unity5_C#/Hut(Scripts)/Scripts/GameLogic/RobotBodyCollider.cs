using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RobotBodyCollider : MonoBehaviour {

    Robot robotScript;
    [SerializeField]GameObject robot;
    RobotDead robDead;

    private void Start()
    {
        robotScript = robot.GetComponent<Robot>();
        robDead = GetComponent<RobotDead>();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !robotScript.IsOne)
        {
            robotScript.IsOne = true;
            robDead.Death();
            MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDeath", true);
            MessageSystemPlayingScene.GeneralyPartOfDeath();
        }
    }
}
