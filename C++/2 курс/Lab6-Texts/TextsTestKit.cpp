#include <gtest/gtest.h>
#include "TText.h"
#include "tdatacom.h"
#include <iostream>

TEST(TText, can_create_text)
{
	ASSERT_NO_THROW(TText txt);
}

TEST(TText, can_create_text_with_str)
{
    string str = "String";
    TTextLink link(str);

    TTextLink::InitMemSystem(1);
    TText txt(&link);

    txt.GoFirstLink();

    EXPECT_EQ(txt.GetLine(), str);
}

TEST(TText, can_add_downLine)
{
	string str = "String";
    TTextLink::InitMemSystem(2);
    TText txt;

    txt.GoFirstLink();
    txt.InsDownLine(str);
    txt.GoDownLink();

    EXPECT_EQ(txt.GetLine(), str);
}


TEST(TText, error_when_downLink_null)
{

    TTextLink::InitMemSystem(2);
    TText T;


    T.GoFirstLink();
    EXPECT_EQ(T.GoDownLink(), TextNoDown);
}

TEST(TText, can_not_go_prev_when_it_is_null)
{
    TTextLink::InitMemSystem(2);
    TText T;

    T.GoFirstLink();
    EXPECT_EQ(T.GoPrevLink(), TextNoPrev);
}

TEST(TText, can_del_down_line)
{
    string str1 = "String1";
    string str2 = "String2";
    string str3 = "String3";
    TTextLink::InitMemSystem(4);
    TText txt;

    txt.GoFirstLink();
    txt.InsDownLine(str1);
    txt.GoDownLink();
    txt.InsDownLine(str2);
    txt.InsDownLine(str3);
    txt.GoDownLink();
    txt.DelDownLine();
    txt.GoFirstLink();
    txt.GoDownLink();

    EXPECT_EQ(txt.GetLine(), str1);
}

TEST(TText, can_del_down_section)
{
    string sec1 = "section 1";
    string sec2 = "section 2";
    string sec3 = "section 3";
    string str1 = "String 1";
    string str2 = "String 2";
    TTextLink::InitMemSystem(6);
    TText txt;

    txt.GoFirstLink();
    txt.InsDownLine(sec1);
    txt.GoDownLink();
    txt.InsDownLine(sec3);
    txt.InsDownLine(sec2);
    txt.GoDownLink();
    txt.InsDownLine(str2);
    txt.InsDownLine(str1);
    txt.DelDownSection();
    txt.GoFirstLink();
    txt.GoDownLink();
    txt.GoDownLink();


    EXPECT_EQ(txt.GoDownLink(), TextNoDown);
}

TEST(TText, can_del_next_line)
{
    string sec1 = "section 1";
    string str1 = "String 1";
    string str2 = "String 3";
    string str3 = "String 2";
    TTextLink::InitMemSystem(5);
    TText txt;

    txt.GoFirstLink();
    txt.InsDownLine(sec1);
    txt.GoDownLink();
    txt.InsDownSection(str1);
    txt.GoDownLink();
    txt.InsNextLine(str2);
    txt.InsNextLine(str3);
    txt.DelNextLine();
    txt.GoFirstLink();
    txt.GoDownLink();
    txt.GoDownLink();


    EXPECT_EQ(txt.GetLine(), str1);
}