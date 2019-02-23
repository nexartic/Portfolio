#include "utmatrix.h"
#include <gtest/gtest.h>
TEST(TVector,throw_then_create_with_negative_StartIndex)
{
	ASSERT_ANY_THROW(TVector<int> vec(10, -1));
}

TEST(TVector,can_use_triple_operator_plus)
{
	TVector<int> vec(1);
	vec[0] = 0;
	vec = vec + 5 + 4;
	EXPECT_EQ(9, vec[0]);
}
TEST(TVector, vectors_with_different_element_are_not_equal)
{
	int size = 10;
	TVector<int> vec(size), vec1(size);
		for (int j = 0; j < size; j++)
		{
			vec[j] = 0;
			vec1[j] = 0;
		}
		vec[0] = 1;
		EXPECT_NE(vec, vec1); 
}

TEST(TVector,Size_default_vector_equal_10)
{
	TVector<int> vec;
	EXPECT_EQ(10, vec.GetSize()); 
}

TEST(TVector,method_plus_increase_all_element )
{
	int size = 10;
	TVector<int> vec(size);
	for (int j = 0; j < size; j++)
	{
		vec[j] = 0;
	}
	vec = vec + 5;
	for (int j = 0; j < size; j++)
	{
		EXPECT_EQ(vec[j], 5); 
	}
}

TEST(TMatrix, matrix_with_different_element_are_not_equal)
{
	

	int size = 10;
	TMatrix<int> mat(size), mat1(size);
	for(int i = 0;i<size;i++)
	for (int j = i; j < size; j++)
	{
		mat[i][j] = 0;
		mat1[i][j] = 1;
	}
	EXPECT_NE(mat, mat1);
}

TEST(TMatrix,can_use_convert_constructor)
{
	
	int size = 10;
	TMatrix<int> mat(size);
	ASSERT_NO_THROW( TVector<TVector<int>> vec = mat); 
}

TEST(TMatrix,equal_size_then_create_with_convert_constructor)
{
	int size = 10;
	TMatrix<int> mat(size);
	TVector<TVector<int>> vec = mat;
	EXPECT_EQ(vec.GetSize(), mat.GetSize());
}
TEST(TMatrix,matrix_is_equal_then_create_with_convert_constructor )
{
	int size = 10;
	TMatrix<int> mat(size);
	TVector<TVector<int>> vec = mat;
	EXPECT_EQ(vec, mat); 
}

TEST(TMatrix,can_use_triple_operator_plus )
{
	int size = 10;
	TMatrix<int> mat(size),mat1(size),mat2(size),mat3(size);
	for (int i = 0; i<size; i++)
		for (int j = i; j < size; j++)
		{
			mat[i][j] = 0;
			mat1[i][j] = 1;
			mat2[i][j] = 2;
			mat3[i][j] = 3;
		}
	mat = mat + mat1 + mat2;
	EXPECT_EQ(mat, mat3); system("pause");
}