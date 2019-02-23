using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UndergoTraining : MonoBehaviour {

    float newSize = 1.1f;
    [SerializeField] GameObject level_1;

    private void OnMouseDown()
    {
        transform.localScale = new Vector3(newSize, newSize, 1);
        OpenMenu.PressAtMenu();
        FirstStart.SetActiveStopCollider(true);
        FirstStart.DisableMenuAndQuestion();
        PlayerPrefs.DeleteKey("FirstStart");
        level_1.GetComponent<TapToLevel>().SelectForEducation();
    }

    private void OnMouseUp()
    {
        transform.localScale = new Vector3(1, 1, 1);
    }
}
