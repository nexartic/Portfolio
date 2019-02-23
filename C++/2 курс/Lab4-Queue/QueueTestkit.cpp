#include<gtest\gtest.h>
#include"TQueue.h"
using namespace std;

TEST(TQueue, can_create_obj_with_default_size)
{
	TQueue queue;
	int size = 0;


	while (!queue.IsFull())
	{
		queue.Put(size);
		size++;
	}


	EXPECT_EQ(size, 10);
}

TEST(TQueue, can_check_on_empty_when_only_create)
{
	TQueue queue;

	EXPECT_TRUE(queue.IsEmpty());
}

TEST(TQueue, can_check_on_full_without_cicle)
{
	int size = 20;
	TQueue queue(size);

	for (int i = 0; i < size; i++)
	{
		queue.Put(i);
	}
	EXPECT_TRUE(queue.IsFull());
}

TEST(TQueue, can_check_on_empty_after_full_Get)
{
	int size = 20;
	TQueue queue(size);

	for (int i = 0; i < size; i++)
	{
		queue.Put(i);
	}
	for (int i = 0; i < size; i++)
	{
		queue.Get();
	}

	EXPECT_TRUE(queue.IsEmpty());
}

TEST(TQueue, can_check_on_empty_after_cicle)
{
	int size = 20;
	TQueue queue(size);

	for (int i = 0; i < size; i++)
	{
		queue.Put(i);
	}
	queue.Get();
	queue.Put(0);
	for (int i = 0; i < size; i++)
	{
		queue.Get();
	}


	EXPECT_TRUE(queue.IsEmpty());
}

TEST(TQueue, can_check_on_full_after_cicle)
{
	int size = 20;
	TQueue queue(size);

	for (int i = 0; i < size; i++)
	{
		queue.Put(i);
	}
	queue.Get();
	queue.Put(0);

	EXPECT_TRUE(queue.IsFull());
}

TEST(TQueue, can_get_without_cicle)
{
	int size = 20;
	TQueue queue(size);

	for (int i = 0; i < size; i++)
	{
		queue.Put(i);
	}
	queue.Get();

	EXPECT_EQ(queue.Get(), 19);
}

TEST(TQueue, can_put_with_cicle)
{
	int size = 20;
	TQueue queue(size);

	for (int i = 0; i < size; i++)
	{
		queue.Put(i);
	}
	queue.Get();
	queue.Put(size);

	EXPECT_EQ(size, queue.Get()); system("pause");
}

