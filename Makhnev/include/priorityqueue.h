#pragma once
#include "queue.h"
template <typename T>
class TPriorityQueue
{
	TQueue<T>* queues;
	size_t numOfPriorities;
public:
	TPriorityQueue(size_t numOfPriorities) {
		queues = new TQueue<T>[numOfPriorities]();
		this->numOfPriorities = numOfPriorities;
	}
	~TPriorityQueue()
	{
		delete[] queues;
	}
	void Push(const T& element, size_t priority = 0) {
		if (priority >= numOfPriorities) throw std::out_of_range("incorrect priority");
		queues[priority].Push(element);
	}
	void Pop();
	T& Top();
	bool IsEmpty() {
		for (size_t i = 0; i < numOfPriorities; i++)
		{
			if (!queues[i].IsEmpty()) return false;
		}
		return true;
	}
};

template<typename T>
inline void TPriorityQueue<T>::Pop() {
	size_t priority = numOfPriorities - 1;
	while ((priority != 0) && (queues[priority].IsEmpty()))
		priority--;
	if (queues[priority].IsEmpty()) throw std::out_of_range("prority queue is empty");
	queues[priority].Pop();
}

template<typename T>
inline T& TPriorityQueue<T>::Top() {
	size_t priority = numOfPriorities - 1;
	while ((priority != 0) && (queues[priority].IsEmpty()))
		priority--;
	if (queues[priority].IsEmpty()) throw std::out_of_range("prority queue is empty");
	return queues[priority].Top();
}
