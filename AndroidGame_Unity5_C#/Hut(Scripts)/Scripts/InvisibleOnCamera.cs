using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InvisibleOnCamera : MonoBehaviour {

    static bool isVisiblePlayer;

    private void Start()
    {
        isVisiblePlayer = true;
    }

    private void OnBecameVisible()
    {
        isVisiblePlayer = true;
    }

    private void OnBecameInvisible()
    {
        isVisiblePlayer = false;
        StartCoroutine(CheckOnVisible());
    }

    

    IEnumerator CheckOnVisible()
    {
        yield return new WaitForSeconds(Time.deltaTime * 2);

        if (InvisibleCollider.IsOut && !DeadLine.IsDeadLine && !isVisiblePlayer)
        {
            DeadLine.IsDeadLine = true;
            DeadLine.DeathAfterDeadLine();
        }

    }
}
