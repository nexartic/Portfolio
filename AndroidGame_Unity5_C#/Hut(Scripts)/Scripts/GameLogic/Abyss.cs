using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Abyss : MonoBehaviour {

    bool isOne;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isOne)
        {
            isOne = true;
            GameObject player = MessageSystemPlayingScene.Player;
            player.GetComponent<Rigidbody2D>().AddForce(new Vector2(1.5f, 0), ForceMode2D.Impulse);
            player.GetComponent<Animator>().SetBool("IsFall", true);
            MessageSystemPlayingScene.GeneralyPartOfDeath();
            StartCoroutine(Death());
        }
    }

    IEnumerator Death()
    {
        yield return new WaitForSeconds(0.4f);
        MessageSystemPlayingScene.AutoSelectNextCharacter();
        yield return new WaitForSeconds(0.1f);
        MessageSystemPlayingScene.InBodyColider = false;
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
