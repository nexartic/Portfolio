using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EventSpeedyTimer : MonoBehaviour {

    public void Speedy()
    {
        float coeff = 1.7f;
        TapToHero.Multy = 1;
        MessageSystemGameBlock.Speed /= coeff;
    }
}
