using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RobotDead : MonoBehaviour {

    [SerializeField] GameObject Enemy;
    [SerializeField] GameObject particalRobot;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Hit"))
        {
            Death();
        }
    }
    public void Death()
    {
        particalRobot.transform.position = Enemy.transform.position;
        particalRobot.SetActive(true);
        Enemy.SetActive(false);
    }
}
