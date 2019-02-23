using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerZone : MonoBehaviour {

    static SliderJoint2D slide;
    readonly static float anchorBrian = -81f, anchorEva = -85.4f, anchorZak = -97.71f;
    readonly static float speedEva = 0.4f, speedOther = 0.5f;
    static bool isOutside;
    static DelegateStorage storageVoid = new DelegateStorage();
    private delegate void Waiting();
    private static Waiting waiting;

    public static bool IsOutside
    {
        get
        {
            return isOutside;
        }

        set
        {
            isOutside = value;
        }
    }

    private void Start()
    {
        isOutside = false;

        slide = GetComponent<SliderJoint2D>();
        waiting = new Waiting(StartWait);
        storageVoid.InstMemory("float", 1, 3);

        
        storageVoid["0","0"] = (p) =>
        {
            slide.anchor = new Vector2(0, anchorBrian);
            return speedOther;
        };
        storageVoid["0", "1"] = (p) =>
        {
            slide.anchor = new Vector2(0, anchorEva);
            return speedEva;
        };
        storageVoid["0", "2"] = (p) =>
        {
            slide.anchor = new Vector2(0, anchorZak);
            return speedOther;
        };
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject == MessageSystemPlayingScene.Player && collision.gameObject.activeInHierarchy)
        {
            isOutside = true;
            MoveToPlayerZone();
        }
    }

    public static void MoveToPlayerZone()
    {
        waiting();
    }

    void StartWait()
    {
        StartCoroutine(Wait());
    }

    IEnumerator Wait()
    {
        while (MessageSystemPlayingScene.inPingPong)
            yield return null;
        float motorSpeed;
        int index = (int)MessageSystemPlayingScene.Hash[MessageSystemPlayingScene.Player.name];
        motorSpeed = (float)storageVoid["0", index.ToString()]();

        var motor = slide.motor;
        motor.motorSpeed = motorSpeed;
        slide.motor = motor;
        MessageSystemPlayingScene.Player.SetActive(true);
        slide.connectedBody = MessageSystemPlayingScene.Player.gameObject.GetComponent<Rigidbody2D>();
        MessageSystemGameBlock.SetPlayingConstraints();
    }

    public static void SetNoneRigid()
    {
        slide.connectedBody = null;
    }
}
