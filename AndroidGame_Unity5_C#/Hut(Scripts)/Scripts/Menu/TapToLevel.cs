using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TapToLevel : MonoBehaviour {

    static GameObject numberLevel;
    static Text numberLevelText;
    Vector3 pressDown, pressUp;
    [SerializeField]GameObject select;
    static GameObject lastSelect;
    int Lvl;

    private void Start()
    {
        Lvl = name[name.Length - 1] - '0';
        if (PlayerPrefs.HasKey("Level"))// instance current level
        {
            int numberLevel = PlayerPrefs.GetInt("Level");
            if (name[name.Length - 1] == numberLevel + '0')
            {

                MessageSystemGameBlock.LEVEL = numberLevel;
                select.SetActive(true);
                lastSelect = select;
            }

        }
        else
        {
            if (Lvl == 1)
            {
                MessageSystemGameBlock.LEVEL = 1;
                select.SetActive(true);
                lastSelect = select;
            }
        }

        numberLevel = GameObject.Find("Interface/Hint/ParentNumberLevel/NumberLevel/Text");
        numberLevelText = numberLevel.GetComponent<Text>();
    }

    private void OnMouseDown()
    {
        pressDown = Input.mousePosition;
    }

    private void OnMouseUp()
    {
        pressUp = Input.mousePosition;
        if (OpenedLevels.OpenedLevel[Lvl] && pressUp == pressDown && !select.activeInHierarchy)
        {
            select.SetActive(true);
            if (lastSelect != null)
            {
                lastSelect.SetActive(false);
            }
            lastSelect = select;
            MessageSystemGameBlock.LEVEL = Lvl;
            PlayerPrefs.SetInt("Level", MessageSystemGameBlock.LEVEL);
            SetNumberLevel();
            Hint.PlayClip();
        }
    }

    public static void SetNumberLevel()
    {
        numberLevelText.text = MessageSystemGameBlock.LEVEL.ToString();
    }

    public void SelectForEducation()
    {
        select.SetActive(true);
        if (lastSelect != null)
        {
            lastSelect.SetActive(false);
        }
        lastSelect = select;
        MessageSystemGameBlock.LEVEL = Lvl;
        PlayerPrefs.SetInt("Level", MessageSystemGameBlock.LEVEL);
        SetNumberLevel();
    }
}
