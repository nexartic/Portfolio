using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SelectOtherPanel : MonoBehaviour {

    [SerializeField] GameObject otherPanel;

    private void OnMouseDown()
    {
        Hint.PlayClip();
        otherPanel.SetActive(true);
        gameObject.SetActive(false);
    }
}
