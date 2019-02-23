using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Localizer : MonoBehaviour {

    [SerializeField] GameObject score, record, nextLevel, scoreFailPanel;
    [SerializeField] GameObject[] Levels;
    [SerializeField] Sprite[] nextLevelSprite;
    [SerializeField] GameObject[] track;
    [SerializeField] GameObject[] education;

	void Start () {
        if (Conecting.Language == 0)//Russian
        {
            score.GetComponent<Text>().text = "Счёт:";
            scoreFailPanel.GetComponent<Text>().text = "Счёт:";
            record.GetComponent<Text>().text = "Рекорд:";
            nextLevel.GetComponent<SpriteRenderer>().sprite = nextLevelSprite[0];
            for (int i = 0; i < 5; i++)
            {
                Levels[i].GetComponent<Text>().text = "Уровень " + i;
                Levels[i].GetComponent<Text>().resizeTextMaxSize = 45;
            }
            for (int i = 1; i <= track.Length; i++)
            {
                Text txt = track[i - 1].GetComponent<Text>();
                txt.fontSize = 55;
                txt.text = "Мелодия " + i.ToString(); 
            }
            education[0].GetComponent<Text>().text = "Понятно";
            education[1].GetComponent<Text>().text = "Завершить обучение";
            education[2].GetComponent<Text>().text = "Пройти обучение";
        }
        else
        {
            score.GetComponent<Text>().text = "Score:";
            scoreFailPanel.GetComponent<Text>().text = "Score:";
            record.GetComponent<Text>().text = "Record:";
            nextLevel.GetComponent<SpriteRenderer>().sprite = nextLevelSprite[1];
            for (int i = 0; i < 5; i++)
            {
                Levels[i].GetComponent<Text>().text = "Level " + i;
            }

            for (int i = 1; i <= track.Length; i++)
            {
                Text txt = track[i - 1].GetComponent<Text>();
                txt.fontSize = 60;
                txt.text = "Music " + i.ToString();
            }

            education[0].GetComponent<Text>().text = "OK";
            education[1].GetComponent<Text>().text = "Сomplete training";
            education[2].GetComponent<Text>().text = "Undergo training";
        }
	}
}
