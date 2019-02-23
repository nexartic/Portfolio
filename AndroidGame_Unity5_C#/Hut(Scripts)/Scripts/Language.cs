using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Language : MonoBehaviour {

    [SerializeField] Sprite[] lang;
    [SerializeField] GameObject exitQuestion;
    [SerializeField] GameObject[] exitButtons;

    private void Start()
    {
        if (PlayerPrefs.HasKey("Language"))
        {
            Conecting.Language = PlayerPrefs.GetInt("Language");
            GetComponent<Image>().sprite = lang[Conecting.Language];
        }
        else
        {
            PlayerPrefs.SetInt("Language",0);
            Conecting.Language = PlayerPrefs.GetInt("Language");
            GetComponent<Image>().sprite = lang[Conecting.Language];
        }
        SetLanguage();
    }

    private void OnMouseDown()
    {
        TapToExit.PlayClip();
        Conecting.Language = 1 - Conecting.Language;
        GetComponent<Image>().sprite = lang[Conecting.Language];
        PlayerPrefs.SetInt("Language", Conecting.Language);
        SetLanguage();
    }

    void SetLanguage()
    {
        if (Conecting.Language == 0)
        {
            exitQuestion.GetComponent<Text>().text = "Вы точно \nхотите выйти ?";
            exitButtons[0].GetComponent<Text>().text = "Нет";
            exitButtons[1].GetComponent<Text>().text = "Да";
        }
        else
        {
            exitQuestion.GetComponent<Text>().text = "Are you sure \nwant to exit ?";
            exitButtons[0].GetComponent<Text>().text = "No";
            exitButtons[1].GetComponent<Text>().text = "Yes";
        }
    }
}
