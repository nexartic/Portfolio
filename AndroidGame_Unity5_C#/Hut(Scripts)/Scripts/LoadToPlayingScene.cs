using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class LoadToPlayingScene : MonoBehaviour {

    AsyncOperation operation;
    Image img;
    public delegate void progressBar(int number);
    public static progressBar progress;
    [SerializeField] GameObject bar;

    private void Start()
    {
        progress = new progressBar(StartProgressBar);
        img = bar.GetComponent<Image>();

    }

    IEnumerator ProgressBar(int number)
    {
        operation = SceneManager.LoadSceneAsync(number);
        while (true)
        {
            if (!operation.isDone)
                img.fillAmount = operation.progress;
            else
                break;
            yield return null;
        }

        
    }

    public void StartProgressBar(int number)
    {
        StartCoroutine(ProgressBar(number));
    }
}
