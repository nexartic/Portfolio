using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyDeath : MonoBehaviour {

    [SerializeField]GameObject Enemy;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Hit"))
        {
            Enemy.GetComponent<Animator>().SetBool("IsDeath", true);
        }
    }
}
