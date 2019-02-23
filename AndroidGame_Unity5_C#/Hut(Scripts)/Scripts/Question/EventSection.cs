using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EventSection : MonoBehaviour {

    [SerializeField] GameObject swipe;
    [SerializeField] GameObject changeCharacter;
    Animator animChangeCharacter;
    Animator animSwipe;
    int countRecall;



    void Start () {
        countRecall = 0;
        if(swipe != null)
           animSwipe = swipe.GetComponent<Animator>();
        if(changeCharacter != null)
           animChangeCharacter = changeCharacter.GetComponent<Animator>();
	}

    public void SetActiveSwipeAnim(int num)
    {
        animSwipe.speed = num;
    }

    public void Enumerator(int count)
    {
        countRecall++;
        if (countRecall == 2)
        {
            animChangeCharacter.SetInteger("NextPlayer", count);
            animSwipe.SetInteger("NextCircle", count);
            countRecall = 0;
        }
    }

    public void ZakToEnemy()
    {
        animSwipe.SetBool("IsEnemy", true);
    }
}
