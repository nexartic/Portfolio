using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Event : MonoBehaviour {

    public void UpToDown()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsJumpDown", true);
    }
     IEnumerator DownToUp( float time )
    {
        yield return new WaitForSeconds(time);
        MessageSystemPlayingScene.Player.layer = 10;
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsSlipUp", true);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", false);
    }
    public void UpToRun()
    {       
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsSlipDown", false);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsSlipUp", false);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", true);
    }
    public void DizableTeleport()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", false);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsTeleport", false);
    }
    public void DisableHit()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsHit", false);
        MessageSystemPlayingScene.IsHit = true;
    }
    public void EnCol()
    {
        MessageSystemPlayingScene.EnableCollider();
    }
    public void DisCol()
    {
        WaitingScreen.wait(MessageSystemPlayingScene.DisableCollider());
    }
    public void BarrierEvent()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsBarrier", false);
    }
    public void DisableIsDeath()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDeath", false);
        MessageSystemPlayingScene.AnimationDeathIsFinished = false;
    }
    public void EndOfDeath()
    {
        MessageSystemPlayingScene.AnimationDeathIsFinished = true;
    }
    public void DisablePlayer()
    {
        MessageSystemPlayingScene.Player.SetActive(false);
    }
    public void DisableDefaultDeath()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsDefaultDeath", false);
    }
    public void DisableSpeedy()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsSpeedy", false);
    }
    public void DisableRunAgain()
    {
        MessageSystemPlayingScene.Player.GetComponent<Animator>().SetBool("IsRunAgain", false);
    }
    public void JumpBeforBrianHit()
    {
        MessageSystemPlayingScene.IsJump = true;
        PlayerZone.SetNoneRigid();
        MessageSystemGameBlock.SetPlayingConstraints();
        if (!MessageSystemPlayingScene.exitFromPingPong)
        {
            MessageSystemPlayingScene.exitFromPingPong = true;
        }
        if (!MessageSystemPlayingScene.IsDead)
        {
            WaitingScreen.wait(MessageSystemPlayingScene.DisableCollider());
            MessageSystemPlayingScene.Player.GetComponent<Rigidbody2D>().AddForce(new Vector2(0, 9), ForceMode2D.Impulse);
        }
    }
    public void StopGame()
    {
        MessageSystemGameBlock.SaveSpeed();
        MessageSystemGameBlock.StopGame();
    }
    public void StartGame()
    {
        MessageSystemPlayingScene.IsHit = false;
        MessageSystemGameBlock.StartAfterHit();
    }
    public void EvaStrike()
    {
        GameObject obj = MessageSystemGameBlock.ReturnNearestEnemy();
        if(obj)
           obj.GetComponent<Animator>().SetBool("IsDeath", true);
    }
    public void NextCharacter()
    {
        MessageSystemPlayingScene.AutoSelectNextCharacter();
        MessageSystemGameBlock.StartGame();
    }
    public IEnumerator PauseTeleport()
    {
        float time = 1f;
        float bufSpeed = MessageSystemPlayingScene.Player.GetComponent<Animator>().speed;
        MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = 0;
        yield return new WaitForSeconds(time);
        MessageSystemPlayingScene.Player.GetComponent<Animator>().speed = bufSpeed;
    }
    public void SleepTel()
    {
        SleepTeleport.teleport();
    }

    public void EnterToTeleport()
    {
        MessageSystemPlayingScene.Player.tag = "InVisible";
        MessageSystemPlayingScene.SetDefaultConstraints();
    }

    public void ExitFromTeleport()
    {
        if (!PlayerZone.IsOutside)
            MessageSystemPlayingScene.SetDefaultConstraints();
        else
        {
            MessageSystemGameBlock.SetPlayingConstraints();
        }
        MessageSystemPlayingScene.Player.tag = "Player";
    }

    public void SetTagPlayer()
    {
        MessageSystemPlayingScene.Player.tag = "Player";
    }

    IEnumerator EndOfAction()
    {
        yield return null;
        if (Conecting.Management == 0)
        {
            TapToGo.Screen.SetActive(true);
        }
    }
}
