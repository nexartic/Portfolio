using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rand : MonoBehaviour {

    private void OnTriggerEnter2D(Collider2D collision)
    {
        GameObject obj = collision.gameObject;
        if (obj.CompareTag("Random"))
        {
            float rand;
            if (obj.name == "Saw")
            {
                Animation anim = obj.GetComponent<Animation>();
                rand = Random.Range(0, anim["Saw"].length);
                anim["Saw"].time = rand;
            }
            else if (obj.name == "Blade")
            {
                rand = Random.Range(0, 1.5f);
                EventBlock.TimeBlade = rand;
            }
            else if (obj.name == "Needles")
            {
                rand = Random.Range(0, 1.5f);
                EventBlock.TimeNeedles = rand;
            }
            else if (obj.name == "Robot")
            {
                rand = Random.Range(1, 2f);
                obj.GetComponent<Animator>().speed = rand;
            }
        }
    }
}
