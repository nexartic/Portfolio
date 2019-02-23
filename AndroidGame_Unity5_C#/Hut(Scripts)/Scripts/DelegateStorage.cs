using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DelegateStorage : MonoBehaviour {

    public delegate void Act(object obj = null);
    Act[][] act;
    public delegate object Obj( object obj = null);
    Obj[][] obj;

    public void InstMemory(string type, int countRows, int countColumns = 3)
    {
        if (type == "void")
        {
            act = new Act[countRows][];
            for (int k = 0; k < countRows; k++)
                act[k] = new Act[countColumns];
        }
        else
        {
            obj = new Obj[countRows][];
            for (int k = 0; k < countRows; k++)
                obj[k] = new Obj[countColumns];
        }

    }

  

    public Act this[int i, int j]
    {
        get
        {
            return act[i][j];
        }

        set
        {
            act[i][j] = value;
        }
    }

    public Obj this[string i, string j]
    {
        get
        {
            return obj[int.Parse(i)][int.Parse(j)];
        }

        set
        {
            obj[int.Parse(i)][int.Parse(j)] = value;
        }
    }

    
}
