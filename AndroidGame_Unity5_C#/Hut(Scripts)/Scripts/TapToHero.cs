using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TapToHero : MonoBehaviour {

    static float multy = 1;
    readonly static float brianSpeed = 5.2f, evaSpeed = 4.4f, zakSpeed = 6,backgroundSpeed = 3,brianBack = 1,evaBack = 0.9f,zakBack = 1.1f;
    static DelegateStorage storageVoid = new DelegateStorage();
    readonly float deltaSpeed = 1f/((Screen.width /(float)Screen.height) / (1280f / 720f));


    private void Start()
    {
        multy = 1;
        storageVoid.InstMemory("void", 3, 3);

        storageVoid[0, 0] = (a) =>
        {
            Animation anim = (Animation)a;
            anim.Play("CrossBrian");
        };
        storageVoid[0, 1] = (a) =>
        {
            Animation anim = (Animation)a;
            anim.Play("CrossEva");
        };
        storageVoid[0, 2] = (a) =>
        {
            Animation anim = (Animation)a;
            anim.Play("CrossZak");
        };
        storageVoid[1, 0] = (p) =>
        {
            MessageSystemGameBlock.Speed = brianSpeed * multy / deltaSpeed;
            MessageSystemGameBlock.BackgroundSpeed = backgroundSpeed * brianBack / deltaSpeed;
        };
        storageVoid[1, 1] = (p) =>
        {
            MessageSystemGameBlock.Speed = evaSpeed * multy / deltaSpeed;
            MessageSystemGameBlock.BackgroundSpeed = backgroundSpeed * evaBack / deltaSpeed;
        };
        storageVoid[1, 2] = (p) =>
        {
            MessageSystemGameBlock.Speed = zakSpeed * multy / deltaSpeed;
            MessageSystemGameBlock.BackgroundSpeed = backgroundSpeed * zakBack / deltaSpeed;
        };
        storageVoid[2, 0] = (p) =>
        {
            MessageSystemPlayingScene.BackgroundSpeed = backgroundSpeed * brianBack /deltaSpeed;
            MessageSystemPlayingScene.Speed = brianSpeed /deltaSpeed;
        };
        storageVoid[2, 1] = (p) =>
        {
            MessageSystemPlayingScene.BackgroundSpeed = backgroundSpeed * evaBack / deltaSpeed;
            MessageSystemPlayingScene.Speed = evaSpeed / deltaSpeed;
        };
        storageVoid[2, 2] = (p) =>
        {
            MessageSystemPlayingScene.BackgroundSpeed = backgroundSpeed * zakBack / deltaSpeed;
            MessageSystemPlayingScene.Speed = zakSpeed / deltaSpeed;
        };

    }


    public static float Multy
    {
        get
        {
            return multy;
        }
        
        set
        {
            multy = value;
        }
    }

    private void OnMouseDown()
    {
        if(!MessageSystemPlayingScene.IsStart)
           Hint.PlayClip();
        if (!StopCollider.IsCollision)
        {
            InstantiateSpeed(gameObject.name);
            MessageSystemPlayingScene.SelectHero(gameObject);
        }
    }

    IEnumerator PauseCross( int n)
    {
        Animation anim = GetComponent<Animation>();
        anim.Play("ReduceCircle");
        yield return new WaitForSeconds(anim.GetClip("ReduceCircle").length);
        storageVoid[0, n](anim);
    }

    public static void InstantiateSpeed(string name)
    {
        
        if (MessageSystemPlayingScene.IsStart)
        {

            storageVoid[1, (int)MessageSystemPlayingScene.Hash[name]]();
            MessageSystemGameBlock.BackgroundSpeed *= multy;
        }
        else
        {
            storageVoid[2, (int)MessageSystemPlayingScene.Hash[name]]();
        }
    }
}
