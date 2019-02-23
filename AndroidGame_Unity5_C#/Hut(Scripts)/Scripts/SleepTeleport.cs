using System.Collections;
using System.Collections.Generic;
using UnityEngine;




public class SleepTeleport : MonoBehaviour {
    [SerializeField] GameObject greyTeleport;
    static GameObject grey;
    static SpriteRenderer[] quarters;
    public delegate void TeleportSleep();
    public static TeleportSleep teleport;

    private void Start()
    {
        grey = greyTeleport;
        quarters = grey.GetComponentsInChildren<SpriteRenderer>();
        teleport = new TeleportSleep(StartSleepTeleport);
    }

    public  void StartSleepTeleport()
    {
        StartCoroutine(Sleep());
    }

    public  IEnumerator Sleep()
    {
        if (Conecting.Management == 1)
            GetComponent<CircleCollider2D>().enabled = false;
        grey.SetActive(true);
        float time = 7;
        for (int i = 0; i < 4; i++)
        {
            yield return new WaitForSeconds(time / 4);
            quarters[i].enabled = false;
        }
        if (Conecting.Management == 0)
        {
            Animation anim = grey.GetComponent<Animation>();
            anim.Play("GreyTeleportDisable");
            yield return new WaitForSeconds(anim["GreyTeleportDisable"].length);
        }
        else
            GetComponent<CircleCollider2D>().enabled = true;
        MessageSystemPlayingScene.IsTeleport = false;
        grey.SetActive(false);
        foreach (SpriteRenderer sp in quarters)
        {
            sp.color = Color.white;
            sp.enabled = true;
        }
    }
}
