using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Home : MonoBehaviour {

    float newSize;
    [SerializeField] float defaultSize;

    private void Start()
    {
        newSize = defaultSize / 1.2f;
    }

    private void OnMouseDown()
    {
        Hint.PlayClip();
        transform.localScale = new Vector3(newSize, newSize, 1);
    }

    private void OnMouseUp()
    {
        transform.localScale = new Vector3(defaultSize, defaultSize, 1);
        MessageSystemPlayingScene.SetDefaultVal();
        SceneManager.LoadScene(1);
    }
}
