using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckBoxOnMusic : MonoBehaviour {

    [SerializeField] GameObject check;
    [SerializeField] AudioClip clip;
    int numberOperation;

    delegate void InstClip();
    InstClip[] inst = new InstClip[2];

    private void Start()
    {
        numberOperation = 1;
        inst[0] = () => MessageSystemPlayingScene.AddClipToList(clip);
        inst[1] = () => MessageSystemPlayingScene.RemoveClipFromList(clip);
    }

    private void OnMouseDown()
    {
        Hint.PlayClip();
        check.SetActive(!check.activeInHierarchy);
        inst[numberOperation]();
        numberOperation = 1 - numberOperation;
    }
}
