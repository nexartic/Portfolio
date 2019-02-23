using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FinishEducation : MonoBehaviour {

    private void OnMouseDown()
    {
        OkEducationPanel.Resume();
        PlayerPrefs.SetInt("FirstStart", 1);
        FirstStart.EnableMenuAndQuestion();
        FirstStart.SetActiveStopCollider(false);
    }
}
