#pragma once
#include <iostream>
#include "TStack.h"

#define MAX_QUEUE_SIZE 1000

template <class T>
class TStackQueue {
private:
	size_t _size;
	TStack<T> s1;
	TStack<T> s2;

public:
	TStackQueue(int n = 2);
	TStackQueue(const TStackQueue<T>& obj);
	TStackQueue(TStackQueue<T>&& obj) noexcept;

	~TStackQueue() {}

	void Pop();
	void Push(T el);

	T Top() const;

	size_t Size() const noexcept;
	bool IsEmpty() const noexcept;

	template <class K>
	friend std::ostream& operator<<(std::ostream& ostr, const TQueue<K>& obj);

};

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TStackQueue<T>& obj) {

	TStackQueue<T> tmp(obj);
	T tmpEl;
	while (!tmp.IsEmpty()) {
		tmpEl = tmp.Top();
		ostr << tmpEl << " ";
		tmp.Pop();
	}

	return ostr;
}

template <class T>
TStackQueue<T>::TStackQueue(int n) {
	if ((n < 1) || (n > MAX_STACK_SIZE)) throw std::length_error("Invalid queue size!");
	_size = n;
	s1 = TStack<T>(_size);
	s2 = TStack<T>(_size);
}

template <class T>
TStackQueue<T>::TStackQueue(const TStackQueue<T>& obj) {
	this->_size = obj._size;
	this->s1 = TStack<T>(obj.s1);
	this->s2 = TStack<T>(obj.s2);
}

template <class T>
TStackQueue<T>::TStackQueue(TStackQueue<T>&& obj) noexcept {
	this->_size = obj._size;
	this->s1 = TStack<T>(obj.s1);
	this->s2 = TStack<T>(obj.s2);
}

template <class T>
void TStackQueue<T>::Pop() {
	if (s1.IsEmpty()) { std::out_of_range("Queue is empty!"); }
	s1.Pop();
}

template <class T>
void TStackQueue<T>::Push(T el) {

	while (!s1.IsEmpty()) {
		s2.Push(s1.Top());
		s1.Pop();
	}

	s1.Push(el);

	while (!s2.IsEmpty()) {
		s1.Push(s2.Top());
		s2.Pop();
	}
}

template <class T>
T TStackQueue<T>::Top() const {
	if (s1.IsEmpty()) { std::out_of_range("Queue is empty!"); }
	return s1.Top();
}

template <class T>
size_t TStackQueue<T>::Size() const noexcept {
	return _size;
}

template <class T>
bool TStackQueue<T>::IsEmpty() const noexcept {
	if (s1.IsEmpty()) return true;
	return false;
}
