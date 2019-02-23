using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameBlock : MonoBehaviour {

    GameObject block;
    SpriteRenderer portalRight;
    bool isActive;
    float extents = -1;
    float center = -1;
    int countUsing = 0;
    int indexMass;
    new string name;

    public void SetValue(GameObject obj,int index)
    {
        block = obj;
        indexMass = index;
        if (IsPortal())
        {
            SetName();
            SetRight();
        }
    }

    public void ChangeLayerRight(int layer)
    {
        portalRight.sortingOrder = layer;
    }

    public void SetActiveFull(bool val)
    {
        isActive = val;
        block.SetActive(val);
    }

    public void SetActive(bool val)
    {
        isActive = val;
    }

    public GameObject GetGameObject()
    {
        return block;
    }

    public void CalculateDelta()
    {
        BoxCollider2D[] buf = block.GetComponentsInChildren<BoxCollider2D>();

        foreach (BoxCollider2D box in buf)
        {
            if (box.CompareTag("DownEarth"))
            {
                extents = box.bounds.extents.x;
                center = box.bounds.center.x;
                break;
            }
        }
    }

    public int Layer
    {
        set
        {
            block.layer = value;
        }
    }

    public string Tag
    {
        get
        {
            return block.tag;
        }
        set
        {
            block.tag = value;
        }
    }

    public float Extents
    {
        get
        {
            return extents;
        }
    }

    public bool IsActive
    {
        get
        {
            return isActive;
        }
    }

    public float Center
    {
        get
        {
            return center;
        }

        set
        {
            center = value;
        }
    }

    public int CountUsing
    {
        get
        {
            return countUsing;
        }

        set
        {
            countUsing = value;
        }
    }

    public string Name
    {
        get
        {
            return block.name;
        }

        set
        {
            block.name = value;
        }
    }

    public int IndexMass
    {
        get
        {
            return indexMass;
        }

        set
        {
            indexMass = value;
        }
    }

    public string InvertName
    {
        get
        {
            return name;
        }

        set
        {
            name = value;
        }
    }

    bool IsPortal()
    {
        if (block.name[0] == 'B' && block.name[1] == 'a' || block.name[0] == 'P' && block.name[1] == 'o')
            return true;
        return false;
    }

    void SetName()
    {
        for (int i = block.name.Length - 1; block.name[i] != '_'; i--)
            name += block.name[i];
    }

    void SetRight()
    {
        foreach (SpriteRenderer ren in block.GetComponentsInChildren<SpriteRenderer>())
            if (ren.CompareTag("Right"))
            {
                portalRight = ren;
                break;
            }
    }
}
