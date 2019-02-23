using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeadLine : MonoBehaviour {

    static bool isDeadLine;

    public static bool IsDeadLine
    {
        get
        {
            return isDeadLine;
        }

        set
        {
            isDeadLine = value;
        }
    }

    private void Start()
    {
        isDeadLine = false;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Player") && !isDeadLine)
        {
            isDeadLine = true;
            MessageSystemPlayingScene.GeneralyPartOfDeath();
            MessageSystemPlayingScene.AutoSelectNextCharacter();
            MessageSystemGameBlock.StartGame();
            MessageSystemPlayingScene.InBodyColider = false;
        }
    }

    public static void DeathAfterDeadLine()
    {
        MessageSystemPlayingScene.GeneralyPartOfDeath();
        MessageSystemPlayingScene.AutoSelectNextCharacter();
        MessageSystemGameBlock.StartGame();
        MessageSystemPlayingScene.InBodyColider = false;
    }
}
