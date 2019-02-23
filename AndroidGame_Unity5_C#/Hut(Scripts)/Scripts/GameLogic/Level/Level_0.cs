using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level_0 : Levels {

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

    public override GameObject Generate(GameObject currentBlock)
    {
        newBlock.transform.position = new Vector3(currentBlock.transform.position.x + Earth.Delta , newBlock.transform.position.y, newBlock.transform.position.z);
        MessageSystemGameBlock.SetupParent(newBlock, false);
        newBlock.SetActive(true);
        return newBlock;
    }
}
