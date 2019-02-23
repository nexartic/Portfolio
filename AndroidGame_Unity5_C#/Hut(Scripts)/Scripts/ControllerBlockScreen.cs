using UnityEngine;
using System.Collections;

public class ControllerBlockScreen : MonoBehaviour {
    [SerializeField] GameObject blockScreen;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.name == "ExitPanel")
        {
            blockScreen.SetActive(true);
        }
    }
    private void OnTriggerExit2D(Collider2D other)
    {
        if (other.gameObject.name == "ExitPanel")
        {
            blockScreen.SetActive(false);
            other.gameObject.SetActive(false);
            gameObject.SetActive(false);
        }
    }
}
