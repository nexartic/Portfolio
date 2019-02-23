using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CloseMenu : MonoBehaviour {

    delegate void Close();
    static Close[] close;
    static int numberOperation;

    public static int NumberOperation
    {
        set
        {
            numberOperation = value;
        }
    }

    private void Start()
    {
        numberOperation = 0;
        close = new Close[2];
        close[0] = () => { };
        close[1] = () =>
        {
            OpenMenu.open[OpenMenu.NumberOperation]();
        };
    }

    private void OnMouseDown()
    {
        close[numberOperation]();
    }

    public static void ManualCloseMenu()
    {
        close[numberOperation]();
    }
}
