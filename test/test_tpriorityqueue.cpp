#include "priorityqueue.h"
#include <gtest.h>

TEST(TPriorityQueue, can_create_queu)
{
	ASSERT_NO_THROW(TPriorityQueue<int> queue(5));
}
TEST(TPriorityQueue, cant_pop_empty_queue)
{
	TPriorityQueue<int> queue(4);
	ASSERT_ANY_THROW(queue.Pop());
}
TEST(TPriorityQueue, cant_top_empty_queue)
{
	TPriorityQueue<int>	queue(4);
	ASSERT_ANY_THROW(queue.Top());
}
TEST(TPriorityQueue, can_push_element)
{
	TPriorityQueue<int> queue(2);
	queue.Push(-1);
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(TPriorityQueue, can_push_many_elements)
{
	TPriorityQueue<int> queue(4);
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1), 1);
	ASSERT_NO_THROW(queue.Push(-1), 2);
	ASSERT_NO_THROW(queue.Push(-1), 3);
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(TPriorityQueue, is_pushed_elements_correct)
{
	TPriorityQueue<int> queue(2);
	queue.Push(10, 0);
	queue.Push(20, 1);
	queue.Push(40, 1);
	EXPECT_EQ(queue.Top(), 20);
	queue.Pop();
	EXPECT_EQ(queue.Top(), 40);
	queue.Pop();
	EXPECT_EQ(queue.Top(), 10);
	queue.Pop();
}
//TEST(TPriorityQueue, can_queue_copy)
//{
//	TPriorityQueue<int> st(2);
//	st.Push(10);
//	st.Push(20);
//	st.Push(40);
//	ASSERT_NO_THROW(TQueue<int> st2(st));
//}