using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour {

    static int score = 0;
    float scoreSpeed;
    [SerializeField] Text record;
    [SerializeField] Text scoreFail;
    static Text scoreFailPanel;
    static Text saveRecord;
    int intRecord;
    static bool stopScore;
    [SerializeField] Text scoreText;
    static Text staticScoreText;
    public delegate void IncreezeScore();
    public static IncreezeScore increeze;
    public static IncreezeScore stop;

    public static bool StopScore
    {
        get
        {
            return stopScore;
        }

        set
        {
            stopScore = value;
        }
    }

    private void Start()
    {
        score = 0;
        scoreSpeed = 0;
        stopScore = false;

        if (!PlayerPrefs.HasKey("Record"))
            PlayerPrefs.SetInt("Record", 0);
        staticScoreText = scoreText;
        record.text = PlayerPrefs.GetInt("Record").ToString();
        intRecord = int.Parse(record.text);
        increeze = new IncreezeScore(StartCor);
        stop = new IncreezeScore(StopCor);
        saveRecord = record;
        scoreFailPanel = scoreFail;
    }

    public void StartCor()
    {
        StartCoroutine(Increezescore());
    }

    public void StopCor()
    {
        int record = int.Parse(scoreText.text);
        if (PlayerPrefs.GetInt("Record") < record)
            PlayerPrefs.SetInt("Record", record);
        stopScore = true;
    }

    IEnumerator Increezescore()
    {
        scoreSpeed = (1 / MessageSystemGameBlock.Speed) * 1.1f;
        yield return new WaitForSeconds(scoreSpeed);
        if (!stopScore)
        {
            score += MessageSystemGameBlock.LEVEL;
            scoreText.text = score.ToString();
            if (intRecord < score)
                record.text = score.ToString();
            StartCoroutine(Increezescore());
        }
    }

    public static void NULLScoreText()
    {
        staticScoreText.text = "0";
    }

    public static void SetDefaultRecord()
    {
        saveRecord.text = PlayerPrefs.GetInt("Record").ToString();
        stopScore = false;
    }

    public static void SetScoreFailPanel()
    {
        scoreFailPanel.text = score.ToString();
    }
        
}
