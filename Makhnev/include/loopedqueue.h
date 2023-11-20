#pragma once
#include "stack.h"

template <typename T>
class TLoopedQueue : public IDataStrucure<T>
{
	T* pMem;
	size_t size;
	size_t start;
	size_t end;
	bool isFull;
public:
	TLoopedQueue(size_t size = 5);
	void Push(const T& elem);
	T& Top();
	const T& Top() const;
	bool IsEmpty() const;
	size_t Size() const;
	void Pop();
};

template<typename T>
inline TLoopedQueue<T>::TLoopedQueue(size_t size)
{
	this->size = size;
	pMem = new T[size];
	start = 0;
	end = 0;
	isFull = false;
}

template<typename T>
inline void TLoopedQueue<T>::Push(const T& elem)
{
	if (isFull) throw std::out_of_range("Queue is full");
	pMem[end] = elem;
	end = (end + 1) % size;
	if (end == start) isFull = true;
}

template<typename T>
inline T& TLoopedQueue<T>::Top()
{
	if (IsEmpty()) throw std::out_of_range("Queue is empty");
	return pMem[start];
}

template<typename T>
inline const T& TLoopedQueue<T>::Top() const
{
	if (IsEmpty()) throw std::out_of_range("Queue is empty");
	return pMem[start];
}

template<typename T>
inline bool TLoopedQueue<T>::IsEmpty() const
{
	return !isFull && (start == end);
}

template<typename T>
inline size_t TLoopedQueue<T>::Size() const
{
	if (isFull) return size;
	if (end > start)
		return end - start;
	return start - end;
}

template<typename T>
inline void TLoopedQueue<T>::Pop() {
	if (IsEmpty()) throw std::out_of_range("Queue is empty");
	start = (start + 1) % size;
	isFull = false;
}
