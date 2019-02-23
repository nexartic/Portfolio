using UnityEngine;
using System.Collections;

public class TapToSettings : MonoBehaviour {
    [SerializeField] GameObject tools;
    [SerializeField] GameObject settingsPanel;
    Animation anim;
    public static bool isOpenSettings;
    CircleCollider2D circle;
    static AudioSource source;
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
        isOpenSettings = false;
        source = GetComponent<AudioSource>();
        maxVolume = source.volume;
        anim = tools.GetComponent<Animation>();
        circle = GetComponent<CircleCollider2D>();
        saveVolume = maxVolume * PlayerPrefs.GetFloat("Volume");
        isInicialised = true;
    }
    private void OnMouseDown()
    {
        if (!isOpenSettings && circle.isActiveAndEnabled)
        {
            anim["ScrollSettings"].speed = 1;
            anim["ScrollSettings"].time = 0;// время внутри анимации с которого начинается проигрывание
            // получается что для того чтобы проиграть анимацию назад нужно установить время на конец, а вперед в значение 0
            // однако эти строки должны быть именно в этих скобках , а не ниже
            StartCoroutine(ScrollOpen());
            isOpenSettings = true;
            source.Play();
        }
        else
        {
           StartCoroutine(Close());
        }
    }
    IEnumerator ScrollOpen()
    {
        settingsPanel.SetActive(true);
        circle.enabled = false;
        anim.Play("ScrollSettings");
        yield return new WaitForSeconds(anim.GetClip("ScrollSettings").length);
        circle.enabled = true;
    }
    IEnumerator ScrollClose()
    {
        circle.enabled = false;
        anim.Play("ScrollSettings");
        yield return new WaitForSeconds(anim.GetClip("ScrollSettings").length);
        settingsPanel.SetActive(false);
        circle.enabled = true;
    }

    public IEnumerator Close()
    {
        if (Management.IsOpenManagement)
        {
          yield return StartCoroutine(CloseManag());
        }
        anim["ScrollSettings"].speed = -1;
        anim["ScrollSettings"].time = anim.GetClip("ScrollSettings").length;
        StartCoroutine(ScrollClose());
        isOpenSettings = false;
        source.Play();
    }

    IEnumerator CloseManag()
    {
        float time = 0;
        ButtonsManagement.PlayManag(ref time);
        yield return new WaitForSeconds(time);
        Management.IsOpenManagement = false;
    }

    public static void SetupVolume(float volume)
    {
        source.volume = maxVolume * volume;
    }

    public static void DisactiveVolume()
    {
        saveVolume = source.volume;
        source.volume = 0;
    }

    public static void ActivateVolume()
    {
        source.volume = saveVolume;
    }

    public static void SetDefaultValue()
    {
        isInicialised = false;
    }
}
