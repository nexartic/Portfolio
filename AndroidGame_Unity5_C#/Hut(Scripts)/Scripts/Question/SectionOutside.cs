using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SectionOutside : MonoBehaviour {

    [SerializeField] GameObject[] anim;
    Animator[] animat;

    private void Start()
    {
        animat = new Animator[anim.Length];
        for (int i = 0; i < anim.Length; i++)
            animat[i] = anim[i].GetComponent<Animator>();
    }
    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Offset"))
        {
            for(int i = 0; i < animat.Length; i++)
                animat[i].speed = 1;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Offset"))
        {
            for (int i = 0; i < animat.Length; i++)
                animat[i].speed = 0;
        }
    }
}
