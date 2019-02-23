using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level_4 : Levels
{
    int workTime;
    int[] timeMass;
    Generate gen;

    private void Start()
    {
        workTime = 0;
        timeMass = new int[3];
        gen = GetComponent<Generate>();

        timeMass[0] = 5;
        timeMass[1] = 10;
        timeMass[2] = 15;
    }

    public override GameObject Generate(GameObject obj)
    {
        MessageSystemGameBlock.LEVEL = Random.Range(1, 4);
        workTime = timeMass[Random.Range(0, 3)];
        gen.Generation(obj);
        StartCoroutine(StopWatch(workTime));
        return null;
    }

    IEnumerator StopWatch(int time)
    {
        yield return new WaitForSeconds(time);
        while (isGenerate)
        {
            yield return null;
        }
        MessageSystemGameBlock.LEVEL = 4;
    }
}
