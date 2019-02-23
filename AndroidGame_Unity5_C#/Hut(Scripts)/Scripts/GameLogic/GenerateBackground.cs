using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateBackground : MonoBehaviour {

    [SerializeField]GameObject[] blocks;

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Background"))
        {
            int[] index = new int[2];
            GameObject newBlock;
            for (int i = 0, j = 0; i < 3; i++)
            {
                if (!blocks[i].activeInHierarchy)
                {
                    index[j] = i;
                    j++;
                }
            }
            int var = Random.Range(0, 2);
            if (var == 0)
                var = index[0];
            else
                var = index[1];
            newBlock = blocks[var];

            newBlock.transform.position = new Vector3(collision.gameObject.transform.position.x + Background.Delta, newBlock.transform.position.y, newBlock.transform.position.z);
            newBlock.SetActive(true);
        }
    }
}
