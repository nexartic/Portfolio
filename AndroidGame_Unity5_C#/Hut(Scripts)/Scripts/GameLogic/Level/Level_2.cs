using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level_2 : Levels {

    private void Start()
    {
        percent = new float[size + 1][];
        bufPercent = new float[size + 1][];
        selectedBlock = new bool[size];
        for (int i = 1; i < size + 1; i++)
        {
            percent[i] = new float[2];
            bufPercent[i] = new float[2];
        }
        percent[0] = new float[1];
        bufPercent[0] = new float[1];

        percent[0][0] = 0;
        percent[1][0] = 0.11f;
        percent[1][1] = 11;
        percent[2][0] = 0.22f;
        percent[2][1] = 11;
        percent[3][0] = 0.33f;
        percent[3][1] = 11;
        percent[4][0] = 0.42f;
        percent[4][1] = 9;
        percent[5][0] = 0.51f;
        percent[5][1] = 9;
        percent[6][0] = 0.6f;
        percent[6][1] = 9;
        percent[7][0] = 0.77f;
        percent[7][1] = 17;
        percent[8][0] = 0.86f;
        percent[8][1] = 9;
        percent[9][0] = 0.93f;
        percent[9][1] = 7;
        percent[10][0] = 1;
        percent[10][1] = 7;

        Copy(percent, ref bufPercent);
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
            Storage.CountBlockEarth = Random.Range(2, 4);
            GenerateNextBlock(currentBlock,out obj);
        }
        isGenerate = false;
        return obj;
    }

    void GenerateNextBlock(GameObject currentBlock , out GameObject returnBlock)
    {
        int index = 1;
        GameBlock block = new GameBlock();

        for (int i = 0; i < 3; i++)
        {
            Randomizer(ref index);
            block = MessageSystemGameBlock.ReturnUnusedGameBlock(index);
            if (block.GetGameObject() != null)
            {
                selectedBlock[index - 1] = true;
                StartCoroutine(PreparingPercent(index));
                break;
            }
            if (i == 2)
            {
                returnBlock = GenerateNextEarth(currentBlock);
                Storage.CountBlockEarth = 0;
                return;
            }
        }
        block.CountUsing++;
        GameObject newBlock = block.GetGameObject();
        BoxCollider2D curBox = currentBlock.GetComponent<BoxCollider2D>();
        float offset = 0;
        if (block.Extents != -1)
            offset = curBox.bounds.extents.x + block.Extents;
        else
        {
            GenerateNextEarth(currentBlock);
            Storage.CountBlockEarth++;
        }
        newBlock.transform.position = new Vector3(curBox.bounds.center.x + offset, newBlock.transform.position.y, newBlock.transform.position.z);
        MessageSystemGameBlock.SetupParent(newBlock, false);
        block.SetActiveFull(true);
        returnBlock = newBlock;
    }

    
}
