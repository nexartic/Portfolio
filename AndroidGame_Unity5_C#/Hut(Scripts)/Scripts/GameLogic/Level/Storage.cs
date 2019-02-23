using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Storage : MonoBehaviour {

    private static int countBlockEarth = 0;
    private static int indexNextBlock = 10;
    private static int countTripleBlock = 0;

    public static int CountBlockEarth
    {
        get
        {
            return countBlockEarth;
        }

        set
        {
            countBlockEarth = value;
        }
    }

    public static int IndexNextBlock
    {
        get
        {
            return indexNextBlock;
        }

        set
        {
            indexNextBlock = value;
        }
    }

    public static int CountTripleBlock
    {
        get
        {
            return countTripleBlock;
        }

        set
        {
            countTripleBlock = value;
        }
    }

    public static void SetDefaultValue()
    {
        countBlockEarth = 0;
        indexNextBlock = 10;
        countTripleBlock = 0;
    }
}
