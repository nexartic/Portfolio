using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ReverseMainParent : MonoBehaviour {

    [SerializeField] GameObject[] parent;
    [SerializeField] GameObject mainParent;
    static GameObject staticMainParent;
    static GameObject[] parents;

	void Start () {
        parents = new GameObject[parent.Length];
        for (int i = 0; i < parent.Length; i++)
            parents[i] = parent[i];

        staticMainParent = mainParent;
	}

    public static void ReverseParent()
    {
        foreach (RectTransform rec in parents[1].GetComponentsInChildren<RectTransform>())
            if (rec.gameObject.layer == 8)
                rec.gameObject.transform.SetParent(parents[3].transform);
        foreach (RectTransform rec in parents[0].GetComponentsInChildren<RectTransform>())
            if (rec.gameObject.layer == 13)
                rec.gameObject.transform.SetParent(parents[2].transform);

        staticMainParent.transform.localPosition = Vector3.zero;

        foreach (RectTransform rec in parents[3].GetComponentsInChildren<RectTransform>())
            if (rec.gameObject.layer == 8)
                rec.gameObject.transform.SetParent(parents[1].transform);
        foreach (RectTransform rec in parents[2].GetComponentsInChildren<RectTransform>())
            if (rec.gameObject.layer == 13)
                rec.gameObject.transform.SetParent(parents[0].transform);
    }
}
