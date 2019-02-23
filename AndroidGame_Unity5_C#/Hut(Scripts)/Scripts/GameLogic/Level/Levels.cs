using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Levels : MonoBehaviour {

    protected const int size = 10;
    protected const float changeChance = 0.05f;
    protected float[][] percent;
    protected float[][] bufPercent;
    protected bool[] selectedBlock;
    protected static bool isGenerate;



    public abstract GameObject Generate(GameObject obj);

    protected GameObject GenerateNextEarth(GameObject currentBlock)
    {
        Storage.CountBlockEarth--;
        GameBlock block = MessageSystemGameBlock.ReturnDisactiveDownEarth();
        GameObject newBlock = block.GetGameObject();
        block.SetActiveFull(true);
        float deltaMinus = -0.065f;
        BoxCollider2D curBox = currentBlock.GetComponent<BoxCollider2D>();
        BoxCollider2D newBox = newBlock.GetComponent<BoxCollider2D>();
        float delta = curBox.bounds.extents.x  + newBox.bounds.extents.x + deltaMinus;
        newBlock.transform.position = new Vector3(curBox.bounds.center.x + delta, newBlock.transform.position.y, newBlock.transform.position.z);
        MessageSystemGameBlock.SetupParent(newBlock, false);
        return newBlock;
    }

    protected void Randomizer(ref int index)
    {
        float chance = Random.Range(percent[0][0], percent[percent.Length - 1][0]);
        index = 1;
        for (int i = 1; i < percent.Length; i++)
        {
            if (chance > percent[i - 1][0] && chance <= percent[i][0])
            {
                index = i;
                break;
            }
        }
    }

    protected IEnumerator PreparingPercent(int index)
    {
        yield return new WaitForSeconds(0.05f);
        float fullChangeChance = changeChance;
        if (percent[index][1] > bufPercent[index][1])
        {
            fullChangeChance += (percent[index][1] - bufPercent[index][1]) / 100;
            percent[index][1] = (bufPercent[index][1] - (changeChance * 100));
        }
        else
        {
            if ((percent[index][1] - (changeChance * 100)) <= 0)
            {
                fullChangeChance = (percent[index][0] - percent[index - 1][0]);
                percent[index][0] = percent[index - 1][0];
                percent[index][1] = 0;
            }
            else
            {
                percent[index][0] -= changeChance;
                percent[index][1] -= (changeChance * 100);
            }
        }

        int count = 0;
        foreach (bool block in selectedBlock)
            if (!block)
                count++;
        if (count == 0)
        {
            Copy(bufPercent, ref percent);
            for (int i = 0; i < size; i++)
                selectedBlock[i] = false;
        }
        else
        {
            float changePercent = (fullChangeChance / count);
            for (int i = 1; i < size + 1; i++)
            {
                percent[i][0] = percent[i - 1][0] + (percent[i][1] / 100);
                if (!selectedBlock[i - 1])
                {
                    percent[i][0] += changePercent;
                    percent[i][1] += (changePercent * 100);
                }
            }
        }
    }
    protected void Copy(float[][] from, ref float[][] to)
    {
        for (int i = 0; i < from.Length; i++)
            for (int j = 0; j < from[i].Length; j++)
                to[i][j] = from[i][j];
    }
}
