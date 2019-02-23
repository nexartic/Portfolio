using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RobotBody : MonoBehaviour {

    static GameObject particalRobot;
    static bool isInicialize;
    static bool isOne;

    public static bool IsOne
    {
        set
        {
            isOne = value;
        }
    }

    private void Start()
    {
        if (!isInicialize)
        {
            particalRobot = GetComponentInParent<Animation>().gameObject;
            isInicialize = true;
            if (MessageSystemGameBlock.IsInicializeRobot)
                particalRobot.SetActive(false);
            else
                MessageSystemGameBlock.IsInicializeRobot = true;
        }
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "MainParent" && !isOne)
        {
            isOne = true;
            particalRobot.GetComponent<Animation>().Play();
        }
    }

    private void OnDestroy()
    {
        isInicialize = false;
    }

    private void OnDisable()
    {
        isOne = false;
    }
}
