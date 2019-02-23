using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NextLevel : MonoBehaviour {

    Animator anim;
    static bool isPressed;

    public static bool IsPressed
    {
        get
        {
            return isPressed;
        }

        set
        {
            isPressed = value;
        }
    }

    private void Start()
    {
        isPressed = false;
        anim = GetComponent<Animator>();
    }

    private void OnMouseDown()
    {
        isPressed = true;
        anim.speed = 1;
        anim.SetBool("Disactive", true);
    }

    IEnumerator Wait(float time)
    {
        anim.speed = 0;
        yield return new WaitForSeconds(time);
        anim.speed = 1;
    }

    public void Disactive()
    {
        gameObject.SetActive(false);
    }
}
