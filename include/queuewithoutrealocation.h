#pragma once
#include <stdexcept>

template <typename T>
class Queue
{
	T* pMem;
	size_t size;
	size_t start;
	size_t end;
public:
	Queue(const Queue& queue);
	Queue(const Queue&& queue);
	Queue& operator=(const Queue&& queue);
	Queue& operator=(const Queue& queue);
	Queue(size_t size = 3);

	~Queue() {
		delete[] pMem;
	}
	void Pop() {
		if (end == start) throw std::out_of_range("TQueue is out of range");
		start++;
	}
	T& Top() {
		if (end == start) throw std::out_of_range("TQueue is out of range");
		return pMem[start];
	}
	void Push(const T& element)
	{
		if (end >= size) throw std::out_of_range("TQueue is out of range");
		pMem[end] = element;
		end++;
	}
	bool IsEmpty() const
	{
		return end <= start;
	}
	bool IsFull() const
	{
		return end >= size;
	}
};

template<typename T>
inline Queue<T>::Queue(const Queue& queue)
{
	size_t pos = 0;
	pMem = new T[queue.size];
	for (size_t i = start; i < end; i++)
	{
		pMem[pos] = queue.pMem[i];
		pos++;
	}
	start = 0;
	end = pos;
	size = queue.size;
}

template<typename T>
inline Queue<T>::Queue(const Queue&& queue)
{
	pMem = queue.pMem;
	start = queue.start;
	end = queue.end;
	size = queue.size;
	queue.pMem = nullptr;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>&& queue)
{
	std::swap(pMem, queue.pMem);
	start = queue.start;
	end = queue.end;
	size = queue.size;
	return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue) {
	if (pMem != queue.pMem) {
		size_t pos = 0;
		T* tmp = new T[size];
		delete pMem;
		pMem = tmp;
		for (size_t i = start; i < end; i++)
		{
			pMem[pos] = queue.pMem[i];
			pos++;
		}
		start = 0;
		end = pos;
		size = queue.size;
	}
	return *this;
}

template<typename T>
inline Queue<T>::Queue(size_t size)
{
	pMem = new T[size];
	start = 0;
	end = 0;
	this->size = size;
}
