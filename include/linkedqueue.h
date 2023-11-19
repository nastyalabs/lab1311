#pragma once
#include <stdexcept>
#include <ostream>
#include "queuewithoutrealocation.h"
#include "tsinglelinkedlist.h"

template <typename T>
class TLinkedQueue 
{
	TSingleLinkedList<Queue<T>> list;
	TLinkedQueue& operator=(const TLinkedQueue&) = delete;
	TLinkedQueue(const TLinkedQueue&) = delete;
public:
	TLinkedQueue() {}
	void Push(const T& element);
	void Pop();
	T& Top();
	const T& Top() const
	{
		list.Last().Top();
	}
	bool IsEmpty() 
	{
		return list.IsEmpty();
	}
};

template<typename T>
inline void TLinkedQueue<T>::Push(const T& element)
{
	if (list.IsEmpty())
	{
		list.Add(Queue<T>(5));
	}
	if (list.Last().IsFull())
	{
		list.Add(Queue<T>(5));
	}
	list.Last().Push(element);
}

template<typename T>
inline void TLinkedQueue<T>::Pop()
{
	if (list.At(0).IsEmpty())
	{
		list.Remove();
	}
	list.At(0).Pop();
}

template<typename T>
inline T& TLinkedQueue<T>::Top()
{
	return list.Last().Top();
}
