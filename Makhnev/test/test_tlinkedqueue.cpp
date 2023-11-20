#include "linkedqueue.h"
#include <iostream>
#include <gtest.h>

TEST(Queue, can_create_queu)
{
	ASSERT_NO_THROW(Queue<int> queue);
}
TEST(Queue, cant_pop_empty_queue)
{
	Queue<int> queue;
	ASSERT_ANY_THROW(queue.Pop());
}
TEST(Queue, cant_top_empty_queue)
{
	Queue<int>	queue;
	ASSERT_ANY_THROW(queue.Top());
}
TEST(Queue, can_push_element)
{
	Queue<int> queue;
	queue.Push(-1);
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(Queue, can_push_many_elements)
{
	Queue<int> queue;
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
	ASSERT_NO_THROW(queue.Push(-1));
}
TEST(Queue, is_pushed_elements_correct)
{
	Queue<int> queue;
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
TEST(LinkedList, can_add_element)
{
	TSingleLinkedList<int> list(0);
	ASSERT_NO_THROW(list.Add(1));
}
TEST(LinkedList, is_added_element_correct)
{
	TSingleLinkedList<int> list(0);
	list.Add(1);
	EXPECT_EQ(1, list.At(1));
}
TEST(LinkedList, can_remove_first_element)
{
	TSingleLinkedList<int> list(0);
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Remove(0);
	//std::cout << list;
	ASSERT_NO_THROW(list.Remove(0));
}
TEST(LinkedQueue, can_push_element)
{
	TLinkedQueue<int> list;
	ASSERT_NO_THROW(list.Push(8));
}
TEST(LinkedQueue, can_push_many_elements)
{
	TLinkedQueue<int> list;
	list.Push(1);
	list.Push(2);
	list.Push(3);
	list.Push(4);
	list.Push(5);
	list.Push(6);
	list.Push(7);
	ASSERT_NO_THROW(list.Push(8));
}
TEST(LinkedQueue, can_pop_element)
{
	TLinkedQueue<int> list;
	list.Push(1);
	list.Push(2);
	list.Push(3);
	list.Push(4);
	list.Push(5);
	list.Push(6);
	list.Push(7);
	ASSERT_NO_THROW(list.Pop());
}
TEST(LinkedQueue, can_pop_many_elements)
{
	TLinkedQueue<int> list;
	list.Push(1);
	list.Push(2);
	list.Push(3);
	list.Push(4);
	list.Push(5);
	list.Push(6);
	list.Push(7);
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	ASSERT_NO_THROW(list.Pop());
}