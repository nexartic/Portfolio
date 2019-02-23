using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeleteBackground : MonoBehaviour {

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Background"))
        {
            collision.gameObject.SetActive(false);
        }
    }
}
