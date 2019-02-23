using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DisableEnemy : MonoBehaviour {

    [SerializeField]GameObject Enemy;

    private void OnDisable()
    {
        Enemy.SetActive(true);
    }
}
