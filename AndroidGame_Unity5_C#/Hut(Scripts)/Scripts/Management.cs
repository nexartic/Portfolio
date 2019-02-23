using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Management : MonoBehaviour {

    static bool isOpenManagement;
    float newSize = 0.8f;
    static GameObject I;

    private void Start()
    {
        isOpenManagement = false;
        if (!PlayerPrefs.HasKey("Management"))
            PlayerPrefs.SetInt("Management", 1);
        Conecting.Management = PlayerPrefs.GetInt("Management");
        I = gameObject;
    }

    public static bool IsOpenManagement
    {
        get
        {
            return isOpenManagement;
        }

        set
        {
            isOpenManagement = value;
        }
    }

    private void OnMouseDown()
    {
        TapToExit.PlayClip();
        transform.localScale = new Vector3(newSize, newSize, 1);
    }

    private void OnMouseUp()
    {
        transform.localScale = Vector3.one;
        IsOpenManagement = true;
        Animation anim = GetComponent<Animation>();
        anim["Management"].speed = 1;
        anim["Management"].time = 0;
        GetComponent<Animation>().Play("Management");
        SetActiveCollider(false);
    }

    public static void SetActiveCollider(bool val)
    {
        I.GetComponent<BoxCollider2D>().enabled = val;
    }
}
