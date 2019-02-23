using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Conecting  {

    static int management = 1;
    static int language = 1;
    static int music = 1;
    static float volume = 1;

    public static int Management
    {
        get
        {
            return management;
        }

        set
        {
            management = value;
        }
    }

    public static int Language
    {
        get
        {
            return language;
        }

        set
        {
            language = value;
        }
    }

    public static int Music
    {
        get
        {
            return music;
        }

        set
        {
            music = value;
        }
    }

    public static float Volume
    {
        get
        {
            return volume;
        }

        set
        {
            volume = value;
        }
    }
}
