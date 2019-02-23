using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WaitingScreen : MonoBehaviour {


    public delegate void Wait(GameObject obj);
    public static Wait wait;

    private void Start()
    {
        wait = new Wait(StartWaiting);
    }

    void StartWaiting(GameObject obj)
    {
        StartCoroutine(Waiting(obj));
    }

    IEnumerator Waiting(GameObject obj)
    {
        float timer = 0;
        while (timer < 1.8f)
        {
            if(obj.activeInHierarchy)
                yield break;
            timer += Time.deltaTime;
            yield return null;
        }
        if (!obj.activeInHierarchy)
        {
            obj.SetActive(true);
        }
    }
}
