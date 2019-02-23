using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level_1 : Levels
{
    public Level_1()
    {
        isGenerate = false;
    }

    public override GameObject Generate(GameObject currentBlock)
    {
        isGenerate = true;
        GameObject obj;
        if (Storage.CountBlockEarth > 0)
        {
            obj = GenerateNextEarth(currentBlock);
        }
        else
        {
            Storage.CountBlockEarth = 3;
            obj = GenerateNextBlock(Storage.IndexNextBlock,currentBlock);
            if (Storage.IndexNextBlock == 10)
            {
                Storage.IndexNextBlock = 1;
            }
            else if(Storage.CountTripleBlock == 0)
            {
                Storage.IndexNextBlock++;
            }
        }
        isGenerate = false;
        if (obj.name == "Blade")
            Storage.CountBlockEarth = 5;
        if (obj.name == "Needles")
            Storage.CountBlockEarth = 4;
        return obj;
    }

    GameObject GenerateNextBlock(int index,GameObject currentBlock)
    {
        GameBlock block = MessageSystemGameBlock.ReturnDisactiveGameObject(index);
        GameObject newBlock = block.GetGameObject();
        BoxCollider2D curBox = currentBlock.GetComponent<BoxCollider2D>();
        float offset = 0;
        if (newBlock.name == "Barrier_Grey" || newBlock.name == "Portal_Grey")
            Storage.CountTripleBlock = 3;
        if (block.Extents != -1)
            offset = curBox.bounds.extents.x + block.Extents;
        else
        {
            GenerateNextEarth(currentBlock);
            Storage.CountBlockEarth++;
        }
        newBlock.transform.position = new Vector3(curBox.bounds.center.x + offset , newBlock.transform.position.y, newBlock.transform.position.z);
        MessageSystemGameBlock.SetupParent(newBlock, false);
        block.SetActiveFull(true);
        if(Storage.CountTripleBlock != 0)
            Storage.CountTripleBlock--;
        return newBlock;
    }
}
