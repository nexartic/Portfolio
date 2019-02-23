using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
public class ChangeScene : MonoBehaviour {

    [SerializeField] GameObject frame;
    [SerializeField] int number;

    public void GoToNewScene()
    {
        frame.SetActive(true);
        TapToExit.SetDefaultValue();
        TapToSettings.SetDefaultValue();
        LoadToPlayingScene.progress(number);
    }
}
