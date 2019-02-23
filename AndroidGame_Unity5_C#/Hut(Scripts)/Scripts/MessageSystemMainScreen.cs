using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class MessageSystemMainScreen : MonoBehaviour {

   
    static GameObject[] character = new GameObject[3];

    static GameObject exitPanel;
    static Animation anim;
    static GameObject controllerBlockScreen;
    static AudioSource audioSource;
    static float  max;
    static float saveVolume;

    private  void Start()
    {
        audioSource = GetComponent<AudioSource>();
        saveVolume = audioSource.volume;
        max = GetComponent<AudioSource>().volume;
        character[0] = GameObject.Find("MainScreen/Interface/Zak/Zak");
        character[1] = GameObject.Find("MainScreen/Interface/Brian/Brian");
        character[2] = GameObject.Find("MainScreen/Interface/Eva/Eva");

        exitPanel = GameObject.Find("MainScreen/Interface/ExitPanel");
        anim = exitPanel.GetComponent<Animation>();
        controllerBlockScreen = GameObject.Find("MainScreen/Interface/ControlerBlockScreen"); 
    }
   
    public static void OpenExitPanel()
    {
        controllerBlockScreen.SetActive(true);
        exitPanel.SetActive(true);
        anim["OpenExitPanel"].time = 0;
        anim["OpenExitPanel"].speed = 1;
        anim.Play("OpenExitPanel");
    }
    public static void CloseExitPanel()
    {
        anim["OpenExitPanel"].time = anim.GetClip("OpenExitPanel").length;
        anim["OpenExitPanel"].speed = -1;
        anim.Play("OpenExitPanel");
    }

    public static void SetupVolume(float vol)
    {
        audioSource.volume = max * vol;
    }

    public static void ActivateVolume()
    {
        audioSource.volume = saveVolume;
    }

    public static void DisactiveVolume()
    {
        saveVolume = audioSource.volume;
        audioSource.volume = 0;
    }
}
