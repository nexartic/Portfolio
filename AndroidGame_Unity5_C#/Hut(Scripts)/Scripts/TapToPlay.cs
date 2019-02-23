using UnityEngine;
using System.Collections;

public class TapToPlay : MonoBehaviour {

    const byte size = 2;
    [SerializeField] GameObject[] buttons;
    Animation[] anim = new Animation[size];
    [SerializeField] GameObject mainScreen;
    [SerializeField] GameObject tools;
    TapToSettings setting;

    float changeScale = 1.1f;


    private void Start()
    {
        setting = tools.GetComponent<TapToSettings>();
        for (int i = 0; i < size; i++)
        {
            anim[i] = buttons[i].GetComponent<Animation>();
        }
    }
    private void OnMouseDown()
    {
        TapToExit.PlayClip();
         transform.localScale = new Vector3(changeScale, changeScale, changeScale);
    }
    private void OnMouseUp()
    {
            transform.localScale = new Vector3(1, 1, 1);
            StartCoroutine(StartGame());
    }

    IEnumerator StartGame()
    {
        float lenght = GetComponent<Animation>().GetClip("ReduceButton").length;
        GetComponent<Animation>().Play("ReduceButton");
        yield return new WaitForSeconds(lenght);
        if (TapToSettings.isOpenSettings)
        {
            yield return StartCoroutine(setting.Close());
        }
        foreach (Animation anm in anim)
        {
            anm.Play("ReduceButton");
            yield return new WaitForSeconds(lenght);
        }
        mainScreen.GetComponent<Animator>().SetBool("start", true);
    }
}
