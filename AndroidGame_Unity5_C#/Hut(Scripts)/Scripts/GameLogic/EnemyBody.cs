using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyBody : MonoBehaviour {
    [SerializeField]GameObject particalEnemy;

    private void OnCollisionEnter2D(Collision2D collision)
    {
       particalEnemy.GetComponent<Animation>().Play();
    }
}
