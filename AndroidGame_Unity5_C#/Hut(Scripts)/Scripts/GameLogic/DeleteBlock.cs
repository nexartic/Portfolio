using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeleteBlock : MonoBehaviour {

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.layer == 8)
        {
     
            GameObject obj = collision.gameObject;
            if (obj.CompareTag("DownEarth"))
            {
                Level_0.NewBlock = obj;
                MessageSystemGameBlock.DisableDinamicGameBlock(obj, 0);
                obj.SetActive(false);
                return;
            }
            Animator anim;
            if (anim = obj.GetComponentInChildren<Animator>())
                anim.speed = 1;
            obj.GetComponent<DisableGameBlock>().Disable();
        }
    }
}
