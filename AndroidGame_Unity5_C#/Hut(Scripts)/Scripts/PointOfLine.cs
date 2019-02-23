using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PointOfLine : MonoBehaviour {

    [SerializeField] float min, max;
    [SerializeField] GameObject line,settingPanel,check;
    int isPress = 0;
    delegate void ChangeVolume();
    ChangeVolume[] volume = new ChangeVolume[2];
    RectTransform rec;
    float pressDown, pressUp;
    static float currentVolume = 0;
    AudioSource source;
    static float maxVol;

    private void Start()
    {
        isPress = 0;
        pressDown = 0;
        pressUp = 0;
        currentVolume = 0;

        source = GetComponent<AudioSource>();
        maxVol = source.volume;
        rec = GetComponent<RectTransform>();
        volume[0] = () => { };
        volume[1] = () =>
        {
            pressUp = Input.mousePosition.x;
            float offset = pressUp - pressDown;
            float delta = 1.2f;
            float futurePos = rec.localPosition.x + offset * delta;
            if (futurePos >= min && futurePos <= max)
            {
                rec.localPosition += new Vector3(offset * delta, 0, 0);
            }
            pressDown = pressUp;
        };
        rec.localPosition = new Vector3(max, rec.localPosition.y, rec.localPosition.z);

        if (PlayerPrefs.HasKey("Volume"))
        {
            float vol = PlayerPrefs.GetFloat("Volume");
            TapToExit.SetupVolume(vol);
            Conecting.Volume = vol;

            float range = max - min;
            float soundVolume = range * vol;
            rec.localPosition = new Vector3(min + soundVolume, rec.localPosition.y, rec.localPosition.z);
        }
        else
        {
            TapToExit.SetupVolume(1);
            PlayerPrefs.SetFloat("Volume", 1);
            Conecting.Volume = 1;
        }
        if (PlayerPrefs.HasKey("Music"))
        {
            Conecting.Music = PlayerPrefs.GetInt("Music");
            StartCoroutine(CheckBoxMusic.box[Conecting.Music]());
            if (PlayerPrefs.GetInt("Music") == 1)
            {
                check.SetActive(true);
                line.SetActive(true);
            }
            // Так должно быть(без else)
        }
        else
        {
            Conecting.Music = 1;
            check.SetActive(true);
            line.SetActive(true);
            PlayerPrefs.SetInt("Music",1);
        }
    }

    private void OnMouseDown()
    {
        isPress = 1;
        pressDown = Input.mousePosition.x;
    }

    private void OnMouseUp()
    {
        currentVolume = (rec.transform.localPosition.x - min) / (max - min);
        Conecting.Volume = currentVolume;
        TapToExit.SetupVolume(currentVolume);
        TapToSettings.SetupVolume(currentVolume);
        MessageSystemMainScreen.SetupVolume(currentVolume);
        PlayerPrefs.SetFloat("Volume", currentVolume);
        PlayClip();
        isPress = 0;
    }

    void Update ()
    {
        volume[isPress]();
	}

    void PlayClip()
    {
        source.volume = maxVol * currentVolume;
        source.Play();
    }
}
