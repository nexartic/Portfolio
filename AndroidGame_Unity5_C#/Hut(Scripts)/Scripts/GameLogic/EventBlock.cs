using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EventBlock : MonoBehaviour {

    float bufSpeed;
    Animator anim;
    static Animator staticAnim;
    static float timeNeedles;
    static float timeBlade;

    public static float TimeNeedles
    {
        get
        {
            return timeNeedles;
        }

        set
        {
            timeNeedles = value;
        }
    }

    public static float TimeBlade
    {
        get
        {
            return timeBlade;
        }

        set
        {
            timeBlade = value;
        }
    }

    private void Start()
    {
        timeNeedles = 0;
        timeBlade = 0;
        anim = gameObject.GetComponent<Animator>();
        bufSpeed = anim.speed;
        staticAnim = anim;
    }

    IEnumerator PauseBlade()
    {   
        anim.speed = 0;
        yield return new WaitForSeconds(timeBlade);
        anim.speed = bufSpeed;
    }

    IEnumerator PauseNeedles()
    {
        anim.speed = 0;
        yield return new WaitForSeconds(timeNeedles);
        anim.speed = bufSpeed;
    }

    public static void RestorSpeed()
    {
        staticAnim.speed = 1;
    }
}
