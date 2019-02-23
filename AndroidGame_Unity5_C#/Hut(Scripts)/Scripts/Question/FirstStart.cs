using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirstStart : MonoBehaviour {

    [SerializeField] GameObject menu,question,stopCollider,panel;
    static GameObject _stopCollider,_menu,_question;
    delegate void ChangeNumberOperation();
    static ChangeNumberOperation op;

	void Start () {
        op = new ChangeNumberOperation(StartChangeNumberOperation);
        _stopCollider = stopCollider;
        _menu = menu;
        _question = question;
        if (!PlayerPrefs.HasKey("FirstStart") && Conecting.Management == 1)
        {
            menu.SetActive(false);
            question.SetActive(false);
        }
        else
        {
            panel.SetActive(false);
            stopCollider.SetActive(false);
        }
	}

    public static void SetActiveStopCollider(bool value)
    {
        _stopCollider.SetActive(value);
    }

    public static void EnableMenuAndQuestion()
    {
        _menu.SetActive(true);
        _question.SetActive(true);
        op();
    }

    public static void DisableMenuAndQuestion()
    {
        _menu.SetActive(false);
        _question.SetActive(false);
    }

    void StartChangeNumberOperation()
    {
        StartCoroutine(ChangeNumberOperationMenu());
    }

    IEnumerator ChangeNumberOperationMenu()
    {
        yield return null;
        OpenMenu.NumberOperation = 2;
    }
}
