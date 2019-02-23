using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EventEnemy : MonoBehaviour {

    [SerializeField] GameObject Enemy;
    RectTransform[] buf = new RectTransform[6];
    RobotDead robDead;

    private void Start()
    {
        if (name == "Robot")
            robDead = GetComponentInChildren<RobotDead>();
        if(name == "ParticalRobot")
        {
            int count = 0;
            foreach (RectTransform rec in Enemy.GetComponentsInChildren<RectTransform>())
                if (!rec.CompareTag("Partical"))
                {
                    buf[count++] = rec;
                }
            if (MessageSystemGameBlock.IsInicializeRobot)
                gameObject.SetActive(false);
            else
                MessageSystemGameBlock.IsInicializeRobot = true;
        }
        if (name == "EnemyPartical")
        {
            int count = 0;
            foreach (RectTransform rec in GetComponentsInChildren<RectTransform>())
            {
                if (rec.CompareTag("Partical"))
                    buf[count++] = rec;
            }
            gameObject.SetActive(false);
        }
    }

    public void DisableEnemy()
	{
		gameObject.SetActive (false);
	}

    public void DisableCollider()
    {
        Enemy.GetComponent<BoxCollider2D>().enabled = false;
        if (name == "Robot")
            GetComponent<CircleCollider2D>().enabled = false;
        if (name == "Enemy")
            GetComponent<BoxCollider2D>().enabled = false;
    }

    public void RestoreRobot()
    {
        RectTransform[] bufRecTrans = GetComponentsInChildren<RectTransform>();
        for (int i = 1; i < 7; i++)
        {
            if (!bufRecTrans[i].CompareTag("Partical"))
            {
                MessageSystemGameBlock.CopyRecTransform(bufRecTrans[i], buf[i - 1]);
                bufRecTrans[i].GetComponent<Image>().color = Color.white;
            }
        }
        RobotBody.IsOne = false;
        gameObject.SetActive(false);
    }

    public void RestoreEnemy()
    {
        MessageSystemGameBlock.CopyRecTransform(buf[2], buf[0]);
        buf[1].GetComponent<Image>().color = Color.white;
        buf[2].GetComponent<SpriteRenderer>().color = Color.white;
        buf[3].GetComponent<SpriteRenderer>().color = Color.white;
        for (int i = 1; i < 4; i++)
            buf[i].gameObject.SetActive(true);
        buf[2].GetComponent<Rigidbody2D>().simulated = true;
        buf[2].GetComponent<PolygonCollider2D>().enabled = true;
        gameObject.SetActive(false);
    }
    public void RobotDeathAfterEvaStrike()
    {
        robDead.Death();
    }

    public void EnemyDeath()
    {
        Enemy.SetActive(true);
        gameObject.SetActive(false);
    }

    private void OnDestroy()
    {
        if (name == "ParticalRobot")
            RestoreRobot();
        if (name == "EnemyPartical")
            RestoreEnemy();
    }
}
