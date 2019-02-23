using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level_3 : Levels
{
    new const int size = 12;
    int[][] groupBlock = new int[size][];
    int countRemainingBlock;
    int numberGroup;

    private void Start()
    {
        isGenerate = false;
        countRemainingBlock = 0;
        numberGroup = 0;
        //номер блока|особые параметры|число блоков земли после блока
        //Any - 1; Same - 2; AnyBesidePreviouse - 3; SamePreviouseTwo - 4;
        groupBlock[0] = new int[5] { 102, 502, 312, 902, 702 };
        groupBlock[1] = new int[4] { 502, 102, 101, 212 };
        groupBlock[2] = new int[5] { 1002, 401, 702, 702, 102 };
        groupBlock[3] = new int[5] { 602, 212, 331, 322, 232 };
        groupBlock[4] = new int[4] { 802, 902, 211, 212 };
        groupBlock[5] = new int[4] { 1002, 212, 322, 903 };
        groupBlock[6] = new int[6] { 211, 331, 602, 341, 242, 212 };
        groupBlock[7] = new int[5] { 102, 102, 601, 702, 803 };
        groupBlock[8] = new int[5] { 211, 331, 402, 502, 402 };
        groupBlock[9] = new int[6] { 502, 102, 701, 601, 312, 702 };
        groupBlock[10] = new int[4] { 701, 402, 1002, 313 };
        groupBlock[11] = new int[5] { 101, 312, 701, 332, 222 };

        percent = new float[size + 1][];
        bufPercent = new float[size + 1][];
        selectedBlock = new bool[size];
        float difference = 1f / size;
        percent[0] = new float[1] { 0 };
        bufPercent[0] = new float[1] { 0 };
        for (int i = 1; i < percent.Length; i++)
        {
            percent[i] = new float[2];
            bufPercent[i] = new float[2];
            percent[i][0] = percent[i - 1][0] + difference;
            percent[i][1] = difference * 100;
        }
        Copy(percent, ref bufPercent);
    }


    public override GameObject Generate(GameObject currentBlock)
    {
        GameObject obj;
        if (Storage.CountBlockEarth > 0)
        {
            obj = GenerateNextEarth(currentBlock);
        }
        else
        {
            GenerateGroup(currentBlock, out obj);
        }
        return obj;
    }

    void GenerateGroup(GameObject currentBlock, out GameObject returnBlock)
    {
        if (countRemainingBlock == 0)
        {
            isGenerate = true;
            Randomizer(ref numberGroup);
            numberGroup -= 1;
            countRemainingBlock = groupBlock[numberGroup].Length;
            PreparingPercent(numberGroup);
        }
        GenerateNextBlock(currentBlock, out returnBlock);
        countRemainingBlock--;
        if (countRemainingBlock == 0)
            isGenerate = false;
    }

    void GenerateNextBlock(GameObject currentBlock,out GameObject returnBlock)
    {
        int i = groupBlock[numberGroup].Length - countRemainingBlock;
        int blockValue = groupBlock[numberGroup][i];
        int indexNextBlock = blockValue / 100;
        Storage.CountBlockEarth = blockValue % 10;
        int index = (blockValue / 10) % 10;
        GameBlock block = MessageSystemGameBlock.ReturnBlockFromGroup(indexNextBlock, index);

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
