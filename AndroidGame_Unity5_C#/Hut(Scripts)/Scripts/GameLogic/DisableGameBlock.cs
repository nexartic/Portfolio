using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DisableGameBlock : MonoBehaviour {

    int i, j;

    private void Start()
    {
        i = 0;
        j = 0;
    }

    public void Disable()
    {
        MessageSystemGameBlock.ReturnEqualGameBlock(gameObject, ref i, ref j);
        MessageSystemGameBlock.DisableDinamicGameBlock(i, j);
    }
}
