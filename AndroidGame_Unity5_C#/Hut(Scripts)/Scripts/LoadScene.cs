using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class LoadScene : MonoBehaviour {

	// Use this for initialization
	void Start () {
        StartCoroutine(LoadingScene());
	}
    IEnumerator LoadingScene()
    {
        yield return new WaitForSeconds(GetComponent<Animation>().GetClip("Load").length);
        SceneManager.LoadScene(1);
    }
}
