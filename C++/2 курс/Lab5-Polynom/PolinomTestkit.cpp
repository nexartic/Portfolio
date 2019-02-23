#include <gtest/gtest.h>
#include "Polinom.h"
#include "Monom.h"

TEST(TDatLink, can_create_link)
{
	ASSERT_NO_THROW(TDatLink a);
}

TEST(TDatLink, can_set_next_link)
{
	TDatLink a;
	TDatLink* b = new TDatLink();
	ASSERT_NO_THROW(a.SetNextLink(b));
}

TEST(TDatList, new_list_is_empty)
{
	TDatList a;
	EXPECT_TRUE(a.IsEmpty());
}

TEST(TDatList, lenght_new_list_equel_0)
{
	TDatList a;
	EXPECT_EQ(a.GetListLength(), 0);
}

TEST(TDatList, new_list_is_ended)
{
	TDatList a;
	EXPECT_TRUE(a.IsListEnded());
}

TEST(TDatList, cant_set_unexisting_pos)
{
	TDatList a;
	ASSERT_ANY_THROW(a.SetCurrentPos(2));
}

TEST(TDatList, cant_ins_empty_link)
{
	TDatList a;
	ASSERT_ANY_THROW(a.InsFirst());
}

TEST(TDatList, cant_del_first_when_the_list_is_empty)
{
	TDatList a;
	ASSERT_ANY_THROW(a.DelFirst());
}


TEST(TDatList, cant_del_curr_when_the_list_is_empty)
{
	TDatList a;
	ASSERT_ANY_THROW(a.DelCurrent());
}

TEST(TDatList, can_ins_first_in_empty_list)
{
	TMonom* m = new TMonom;
	TDatList a;
	ASSERT_NO_THROW(a.InsFirst(m->GetCopy()));
}

TEST(TDatList, can_ins_last_in_empty_list)
{
	TMonom* m = new TMonom;
	TDatList a;
	ASSERT_NO_THROW(a.InsLast(m->GetCopy()));
}

TEST(TDatList, curr_pos_changes_after_ins)
{
	TMonom* m = new TMonom;
	TDatList a;
	a.InsFirst(m->GetCopy());
	EXPECT_EQ(a.GetCurrentPos(), 0);
}

TEST(TDatList, list_is_not_empty_after_ins)
{
	TMonom* m = new TMonom;
	TDatList a;
	a.InsFirst(m->GetCopy());
	EXPECT_FALSE(a.IsEmpty());
}

TEST(TDatList, can_go_next)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(m->GetCopy());
	EXPECT_EQ(a.GoNext(), 0);
}

TEST(TDatList, curr_pos_ink_when_go_next)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(m->GetCopy());
	a.GoNext();
	EXPECT_EQ(a.GetCurrentPos(), 1);
}

TEST(TDatList, curr_pos_is_zero_after_reset)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	a.Reset();
	EXPECT_EQ(a.GetCurrentPos(), 0);
}

TEST(TDatList, cant_go_next_when_pcurr_doesnt_exist)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	a.GoNext();
	ASSERT_ANY_THROW(a.GoNext());
}

TEST(TDatList, current_pos_increaces_when_ins_first)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	EXPECT_EQ(a.GetCurrentPos() + 1, a.GetListLength());
}

TEST(TDatList, curr_pos_stays_when_ins_last)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(m->GetCopy());
	EXPECT_EQ(a.GetCurrentPos() , 0);
}

TEST(TDatList, can_del_list)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	ASSERT_NO_THROW(a.DelList());
}

TEST(TDatList, deleted_list_len_is_zero)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	a.DelList();
	EXPECT_EQ(a.GetListLength(), 0);
}

TEST(TDatList, deleted_list_curr_pos_is_neg)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	a.DelList();
	EXPECT_EQ(a.GetCurrentPos(), -1);
}

TEST(TDatList, can_get_dat_value)
{
	TMonom* m = new TMonom;
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	ASSERT_NO_THROW(a.GetDatValue());
}

TEST(TDatList, cant_get_dat_value_from_incorrect_link)
{
	TMonom* m = new TMonom;
	TDatList a;
	ASSERT_ANY_THROW(a.GetDatValue());
}

TEST(TDatList, get_dat_value_is_correct)
{
	TDatList a;
	TMonom* m = new TMonom[5];
	for (int i = 0; i < 5;i++)
	{
		m[i].SetCoeff(i);
		m[i].SetIndex(i);
		a.InsFirst(m[i].GetCopy());
	}
	a.SetCurrentPos(2);
	TMonom* tmp =  (TMonom*)a.GetDatValue();
	EXPECT_TRUE(m[2] == *tmp);
}

//THeadRing

TEST(THeadRing, can_create_list)
{
	ASSERT_NO_THROW(THeadRing a);
}

TEST(THeadRing, new_list_is_empty)
{
	THeadRing a;
	EXPECT_TRUE(a.IsEmpty());
}

TEST(THeadRing, new_list_has_zero_len)
{
	THeadRing a;
	EXPECT_EQ(a.GetListLength(), 0);
}

TEST(THeadRing, new_list_has_neg_curr_pos)
{
	THeadRing a;
	EXPECT_LT(a.GetCurrentPos(), 0);
}

TEST(THeadRing, new_list_is_ended)
{
	THeadRing a;
	EXPECT_TRUE(a.IsListEnded());
}

TEST(THeadRing, cant_del_curr_when_the_list_is_empty)
{
	THeadRing a;
	ASSERT_ANY_THROW(a.DelCurrent());
}

TEST(THeadRing, can_ins_first_in_empty_list)
{
	TMonom* m = new TMonom;
	THeadRing a;
	ASSERT_NO_THROW(a.InsFirst(m->GetCopy()));
}

TEST(THeadRing, can_ins_last_to_empty_list)
{
	TMonom* m = new TMonom;
	THeadRing a;
	ASSERT_NO_THROW(a.InsLast(m->GetCopy()));
}

TEST(THeadRing, can_ins_curr_to_empty_list)
{
	TMonom* m = new TMonom;
	THeadRing a;
	ASSERT_NO_THROW(a.InsCurrent(m->GetCopy()));
}



TEST(THeadRing, list_len_changes_after_ins)
{
	TMonom* m = new TMonom;
	THeadRing a;
	a.InsFirst(m->GetCopy());
	EXPECT_EQ(a.GetListLength(), 1);
}

TEST(THeadRing, curr_pos_changes_after_ins)
{
	TMonom* m = new TMonom;
	THeadRing a;
	a.InsFirst(m->GetCopy());
	EXPECT_EQ(a.GetCurrentPos(), 0);
}

TEST(THeadRing, list_is_not_empty_after_ins)
{
	TMonom* m = new TMonom;
	THeadRing a;
	a.InsFirst(m->GetCopy());
	EXPECT_FALSE(a.IsEmpty());
}

TEST(THeadRing, curr_pos_increaces_when_ins_first)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	EXPECT_EQ(a.GetCurrentPos() + 1, a.GetListLength());
}

TEST(THeadRing, curr_pos_stays_when_ins_last)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsLast(m->GetCopy());
	EXPECT_EQ(a.GetCurrentPos(), 0);
}


TEST(THeadRing, can_go_next)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsLast(m->GetCopy());
	EXPECT_EQ(a.GoNext(), 0);
}

TEST(THeadRing, curr_pos_inc_when_go_next)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsLast(m->GetCopy());
	a.GoNext();
	EXPECT_EQ(a.GetCurrentPos(), 1);
}

TEST(THeadRing, list_can_be_ended)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	EXPECT_TRUE(a.GoNext());
	EXPECT_TRUE(a.IsListEnded());
}

TEST(THeadRing, list_is_cycled)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	a.GoNext();
	EXPECT_EQ(a.GetCurrentPos(), -1);
	a.GoNext();
	EXPECT_EQ(a.GetCurrentPos(), 0);
}

TEST(THeadRing, can_get_dat_value)
{
	TMonom* m = new TMonom;
	THeadRing a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(m->GetCopy());
	ASSERT_NO_THROW(a.GetDatValue());
}

TEST(THeadRing, cant_get_dat_value_from_incorrect_link)
{
	TMonom* m = new TMonom;
	THeadRing a;
	ASSERT_ANY_THROW(a.GetDatValue());
}

TEST(THeadRing, get_dat_value_is_correct)
{
	THeadRing a;
	TMonom* m = new TMonom[5];
	for (int i = 0; i < 5;i++)
	{
		m[i].SetCoeff(i);
		m[i].SetIndex(i);
		a.InsFirst(m[i].GetCopy());
	}
	a.SetCurrentPos(2);
	TMonom* tmp = (TMonom*)a.GetDatValue();
	EXPECT_TRUE(m[2] == *tmp);
}

TEST(TPolinom, can_create_new_poly)
{
	ASSERT_NO_THROW(TPolinom a);
}

TEST(TPolinom, can_create_filled_poly)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	ASSERT_NO_THROW(TPolinom a(monoms, 1));
}

TEST(TPolinom, can_create_copied_poly)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	TPolinom a(monoms, 1);
	ASSERT_NO_THROW(TPolinom b(a));
}

TEST(TPolinom, can_set_polynom)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	TPolinom a(monoms, 1);
	TPolinom b;
	ASSERT_NO_THROW(b = a);
}

TEST(TPolinom, can_add_empty_polynom)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	TPolinom a(monoms, 1);
	TPolinom b;
	ASSERT_NO_THROW(b = a+b);
}

TEST(TPolinom, created_poly_is_correct)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	TPolinom a(monoms, 1);
	PTMonom m = new TMonom(5, 5);
	EXPECT_TRUE(*m == *a.GetMonom());
}

TEST(TPolinom, copy_poly_is_correct)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	TPolinom a(monoms, 1);
	TPolinom b(a);
	EXPECT_TRUE(*b.GetMonom() == *a.GetMonom());
}

TEST(TPolinom, set_poly_is_correct)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	TPolinom a(monoms, 1);
	TPolinom b = a;
	EXPECT_TRUE(*b.GetMonom() == *a.GetMonom());
}

TEST(TPolinom, can_add_poly)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	int monoms2[1][2];
	monoms2[0][0] = 25;
	monoms2[0][1] = 25;
	TPolinom a(monoms, 1);
	TPolinom b(monoms2, 1);
	ASSERT_NO_THROW(b = a + b);
}

TEST(TPolinom, added_poly_is_correct)
{
	int monoms[1][2];
	monoms[0][0] = 5;
	monoms[0][1] = 5;
	int monoms2[1][2];
	monoms2[0][0] = 25;
	monoms2[0][1] = 25;
	TPolinom a(monoms, 1);
	TPolinom b(monoms2, 1);
	b = a + b;
	PTMonom m = new TMonom(5, 5);
	PTMonom m2 = new TMonom(25, 25);
	b.Reset();
	EXPECT_TRUE(*m == *b.GetMonom());
	b.GoNext();
	EXPECT_TRUE(*m2 == *b.GetMonom());
}
