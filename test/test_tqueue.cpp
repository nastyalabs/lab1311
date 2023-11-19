#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queu)
{
	ASSERT_NO_THROW(TQueue<int> queue);
}
TEST(TQueue, cant_pop_empty_queue)
{
	TQueue<int> queue;
	ASSERT_ANY_THROW(queue.Pop());
}
TEST(TQueue, cant_top_empty_queue)
{
	TQueue<int>	queue;
	ASSERT_ANY_THROW(queue.Top());
}
TEST(TQueue, can_push_element)
{
	TQueue<int> queue;
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(TQueue, can_push_many_elements)
{
	TQueue<int> queue;
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(TQueue, is_pushed_elements_correct)
{
	TQueue<int> queue;
	queue.Push(10);
	queue.Push(20);
	queue.Push(40);
	EXPECT_EQ(queue.Top(), 10);
	queue.Pop();
	EXPECT_EQ(queue.Top(), 20);
	queue.Pop();
	EXPECT_EQ(queue.Top(), 40);
	queue.Pop();
}
TEST(TQueue, can_queue_copy)
{
	TQueue<int> st;
	st.Push(10);
	st.Push(20);
	st.Push(40);
	ASSERT_NO_THROW(TQueue<int> st2(st));
}