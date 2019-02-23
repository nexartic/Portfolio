using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckBoxMusic : MonoBehaviour {

    [SerializeField] GameObject check, line;
    public delegate IEnumerator CheckBox();
    public static CheckBox[] box = new CheckBox[2];

    private void Start()
    {
        box[0] = new CheckBox(DisactiveVol);
        box[1] = new CheckBox(ActivateVol);
    }

    private void OnMouseDown()
    {
        TapToExit.PlayClip();
        check.SetActive(true);
        line.SetActive(true);  // Так должно быть
        Conecting.Music = 1 - Conecting.Music;
        PlayerPrefs.SetInt("Music", Conecting.Music);
        StartCoroutine(box[Conecting.Music]());
    }

    IEnumerator DisactiveVol()
    {
        while (!TapToExit.IsInicialised || !TapToSettings.IsInicialised)
            yield return null;

        MessageSystemMainScreen.DisactiveVolume();
        TapToExit.DisactiveVolume();
        TapToSettings.DisactiveVolume();
        check.SetActive(false);
        line.SetActive(false);
    }

    IEnumerator ActivateVol()
    {
        while (!TapToExit.IsInicialised || !TapToSettings.IsInicialised)
            yield return null;
        MessageSystemMainScreen.ActivateVolume();
        TapToSettings.ActivateVolume();
        TapToExit.ActivateVolume();
    }
}
