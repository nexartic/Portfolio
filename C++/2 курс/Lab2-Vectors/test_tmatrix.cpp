#include "utmatrix.h"

#include <gtest/gtest.h>

/*TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(6));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5)); 
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5); 

  ASSERT_NO_THROW(TMatrix<int> m1(m)); 
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1); 
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	m = m + m1;
	EXPECT_NE(m, m1); 
}

TEST(TMatrix, can_get_size)
{
  TMatrix <int> mat(10);
  EXPECT_EQ(10, mat.GetSize()); 
}

TEST(TMatrix, can_set_and_get_element)
{
   TMatrix <int> mat(10);
   ASSERT_NO_THROW(mat[0][1] = 10);
   EXPECT_EQ(10, mat[0][1]); 
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	int index = 10;
	TMatrix <int> mat(index);
	ASSERT_ANY_THROW(mat[0][-1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	int index = 10;
	TMatrix <int> mat(index);
	ASSERT_ANY_THROW(mat[index][index] = 0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	int index = 10;
	TMatrix <int> mat(index);
	ASSERT_NO_THROW(mat = mat);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int index = 10;
	TMatrix <int> mat(index),mat1(index);
	ASSERT_NO_THROW(mat = mat1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index+1);
	mat = mat1;
	EXPECT_NE(index, mat.GetSize()); 
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index + 1);
	ASSERT_NO_THROW(mat = mat1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index);
	EXPECT_EQ(mat, mat1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	int index = 10;
	TMatrix <int> mat(index);
	EXPECT_EQ(mat, mat);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	int index = 10;
	TMatrix <int> mat(index),mat1(index+1);
	EXPECT_NE(mat, mat1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index);
	ASSERT_NO_THROW(mat + mat1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index+1);
	ASSERT_ANY_THROW(mat + mat1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index);
	ASSERT_NO_THROW(mat - mat1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	int index = 10;
	TMatrix <int> mat(index), mat1(index + 1);
	ASSERT_ANY_THROW(mat - mat1);
}*/

