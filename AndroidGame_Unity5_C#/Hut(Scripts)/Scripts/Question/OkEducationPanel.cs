using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OkEducationPanel : MonoBehaviour {

    [SerializeField] GameObject educationPanel;
    static GameObject panel;

    private void Start()
    {
        panel = educationPanel;
    }

    private void OnMouseDown()
    {
        Resume();
    }

    public static void Resume()
    {
        MessageSystemPlayingScene.EnableCollider();
        StopCollider.IsCollision = false;
        MessageSystemPlayingScene.IsHit = false;
        MessageSystemGameBlock.StartAfterHit();
        MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 1;
        StopCollider.RestoreConstraints();
        StopCollider.PlayAnimation();
        StopCollider.SetDefaultSortingLayer();
        StopCollider.SetActiveImageButtons(false);
        panel.SetActive(false);
    }
}
