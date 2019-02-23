using UnityEngine;
using System.Collections;

public class TapToExit : MonoBehaviour {

    float changeScale = 0.8f;
    [SerializeField] GameObject tools;
    [SerializeField] GameObject manager;
    static AudioSource clip;
    TapToSettings setting;
    static float maxVolume;
    static float saveVolume;
    static bool isInicialised;

    public static bool IsInicialised
    {
        get
        {
            return isInicialised;
        }
    }

    private void Start()
    {
        setting = tools.GetComponent<TapToSettings>();
        clip = GetComponent<AudioSource>();
        maxVolume = clip.volume;
        saveVolume = maxVolume * PlayerPrefs.GetFloat("Volume");
        isInicialised = true;
    }

    private void OnMouseDown()
    {
        transform.localScale = new Vector3(changeScale, changeScale, changeScale);
    }
    private void OnMouseUp()
    {
        ADS.ShowUnityAds();
        transform.localScale = new Vector3(1, 1, 1);
        StartCoroutine(Open());
    }

    IEnumerator Open()
    {
        if (TapToSettings.isOpenSettings)
        {
            yield return StartCoroutine(setting.Close());
            manager.GetComponent<BoxCollider2D>().enabled = true;
        }
        MessageSystemMainScreen.OpenExitPanel();
        PlayClip();
    }

    public static void PlayClip()
    {
        clip.Play();
    }

    public static void SetupVolume(float volume)
    {
        clip.volume = maxVolume * volume;
    }

    public static void DisactiveVolume()
    {
        saveVolume = clip.volume;
        clip.volume = 0;
    }

    public static void ActivateVolume()
    {
        clip.volume = saveVolume;
    }

    public static void SetDefaultValue()
    {
        isInicialised = false;
    }
}
