using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Portal : MonoBehaviour {

    bool isOne;

    private void OnTriggerExit2D(Collider2D collision)
    {       
            if ((collision.gameObject.CompareTag("Player") || collision.gameObject.CompareTag("Hit")) && collision.gameObject.activeInHierarchy)
            {
                if (collision.gameObject.name != tag && !isOne)
                {
                    isOne = true;
                    MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDeath", true);
                    MessageSystemPlayingScene.GeneralyPartOfDeath();
                }
            }
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
