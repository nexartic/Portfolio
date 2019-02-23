using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ButtonsManagement : MonoBehaviour {

    static Animation anim;
    [SerializeField] Sprite[] press;
    Sprite defaultSprite;
    [SerializeField] GameObject[] buttons;
    [SerializeField] Sprite[] defaultSpt;

    private void Start()
    {
        anim = GetComponentInParent<Animation>();
        if (PlayerPrefs.HasKey("Management"))
        {
            if (name == "Swipe")
            {
                defaultSprite = defaultSpt[1];
                if (PlayerPrefs.GetInt("Management") == 0)
                    GetComponent<Image>().sprite = press[0];
            }
            else
            {
                defaultSprite = defaultSpt[0];
                if (PlayerPrefs.GetInt("Management") == 1)
                    GetComponent<Image>().sprite = press[1];
            }
        }
    }

    private void OnMouseDown()
    {
        TapToExit.PlayClip();
        if (name == "Swipe")
        {
            Conecting.Management = 0;
        }
        else
        {
            Conecting.Management = 1;
        }
        GetComponent<Image>().sprite = press[Conecting.Management];
        if(PlayerPrefs.HasKey("Management"))
           buttons[Conecting.Management].GetComponent<Image>().sprite = defaultSprite;
        PlayerPrefs.SetInt("Management", Conecting.Management);
    }

    private void OnMouseUp()
    {
        Management.IsOpenManagement = false;
        Management.SetActiveCollider(true);
        StartCoroutine(Close());
    }

     IEnumerator Close()
    {
        anim["Management"].speed = -1;
        anim["Management"].time = anim["Management"].length;
        anim.Play("Management");
        yield return new WaitForSeconds(anim["Management"].length);
    }

    public static void PlayManag(ref float time)
    {
        time = anim["Management"].length;
        anim["Management"].speed = -1;
        anim["Management"].time = anim["Management"].length;
        anim.Play("Management");
    }
}
