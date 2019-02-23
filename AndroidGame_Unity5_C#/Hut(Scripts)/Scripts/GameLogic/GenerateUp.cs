using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateUp : MonoBehaviour {

    static GameObject newBlock;

    public static GameObject NewBlock
    {
        get
        {
            return newBlock;
        }

        set
        {
            newBlock = value;
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        GameObject currentBlock = collision.gameObject;
        newBlock.transform.position = new Vector3(currentBlock.transform.position.x + Earth.Delta, newBlock.transform.position.y, newBlock.transform.position.z);
        MessageSystemGameBlock.SetupParent(newBlock, true);
        newBlock.SetActive(true);
    }
}
