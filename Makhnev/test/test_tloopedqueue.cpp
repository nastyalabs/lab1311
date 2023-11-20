#include "loopedqueue.h"
#include <gtest.h>

TEST(TLoopedQueue, can_create_queue)
{
	ASSERT_NO_THROW(TLoopedQueue<int> queue);
}
TEST(TLoopedQueue, cant_pop_empty_queue)
{
	TLoopedQueue<int> queue;
	ASSERT_ANY_THROW(queue.Pop());
}
TEST(TLoopedQueue, cant_top_empty_queue)
{
	TLoopedQueue<int>	queue;
	ASSERT_ANY_THROW(queue.Top());
}
TEST(TLoopedQueue, can_push_element)
{
	TLoopedQueue<int> queue;
	queue.Push(-1);
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(TLoopedQueue, can_push_many_elements)
{
	TLoopedQueue<int> queue;
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(TLoopedQueue, is_pushed_elements_correct)
{
	TLoopedQueue<int> queue;
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
