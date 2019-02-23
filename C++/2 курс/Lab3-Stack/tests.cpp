#include"tstack.h"
#include <gtest\gtest.h>
#include"tformula.h"
TEST(TStack, Respond_system_then_create_stack_with_too_big_size)
 {
	int size = 10;
	TStack st(size), st1(MaxSizeStack + size);
	
		
		EXPECT_NE(DataNoMem, st.GetRetCode());
	EXPECT_EQ(DataNoMem, st1.GetRetCode());
	}
TEST(TStack, check_IsEmpty)
 {
	int size = 10;
	TStack st(size);
	
		
		EXPECT_TRUE(st.IsEmpty());
	}
TEST(TStack, check_IsFull)
 {
	int size = 10;
	TStack st(size);
	
		
		EXPECT_FALSE(st.IsFull());
	
		
		for (int i = 0; i < size; i++)
		 {
		st.Put(i);
		}
	EXPECT_TRUE(st.IsFull());
	}
TEST(TStack, can_put_data_in_empty_stack)
 {
	int size = 10;
	TStack st(size);
	st.Put(size);
	
		
		EXPECT_EQ(size, st.Get());
	}
TEST(TStack, can_not_put_data_in_Full_stack)
 {
	int size = 10;
	TStack st(size);
	for (int i = 0; i < size; i++)
		 {
		st.Put(i);
		}
	
		
		st.Put(size);
	EXPECT_EQ(DataFull, st.GetRetCode());
	}
TEST(TStack, can_get_data_in_full_stack)
 {
	int size = 10;
	TStack st(size);
	for (int i = 0; i < size; i++)
		 {
		st.Put(i);
		}
	
		
		EXPECT_TRUE(st.IsFull());
	int a = st.Get();
	EXPECT_EQ(DataOK, st.GetRetCode());
	}
TEST(TStack, can_not_get_data_in_empty_stack)
 {
	int size = 10;
	TStack st(size);
	int i = st.Get();
	
		
		EXPECT_EQ(DataEmpty, st.GetRetCode());
	}

TEST(TFormula, can_create_right_formula)
 {
	char str[] = "(3+4)";
	TFormula formula(str);
	int const size = 10;
	int mass[size];
	
		
		EXPECT_EQ(0, formula.FormulaChecker(mass, size));
	}
TEST(TFormula, can_colculate)
 {
	char str[] = "(3+9+4-5)";
	TFormula formula(str);
	formula.FormulaConverter();
	EXPECT_DOUBLE_EQ(11.0, formula.FormulaCalculator()); system("pause");
		 }
