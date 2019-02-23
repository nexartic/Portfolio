using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeleteUp : MonoBehaviour {

    private void OnTriggerEnter2D(Collider2D collision)
    {
        GenerateUp.NewBlock = collision.gameObject;
    }
}
