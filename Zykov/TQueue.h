#pragma once
#include <iostream>

#define MAX_QUEUE_SIZE 1000
#define EXP_COEF 1.5

template <class T>
class TQueue {
protected:
	T* pMem;
	size_t _size;
	int end;
	int begin;

public:
	TQueue(int n = 2);
	TQueue(const TQueue<T>& obj);
	TQueue(TQueue<T>&& obj) noexcept;

	~TQueue() { delete[] pMem; }

	void pop();
	void push(T el);

	T top() const;

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	template <class K>
	friend std::ostream& operator<<(std::ostream& ostr, const TQueue<K>& obj);
};

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TQueue<T>& obj) {
	for (size_t i = obj.begin; i <= obj.end; i++) {
		ostr << obj.pMem[i] << std::endl;
	}
	return ostr;
}

template <class T>
TQueue<T>::TQueue(int n) {
	if (n > MAX_QUEUE_SIZE || n < 1) throw std::length_error("Invalid queue size!");
	pMem = new T[n];
	begin = 0;
	end = -1;
	_size = n;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& obj) {
	this->end = obj.end;
	this->_size = obj._size;
	this->begin = obj.begin;
	this->pMem = new T[obj._size];

	for (size_t i = begin; i <= end; i++) {
		this->pMem[i] = obj.pMem[i];
	}
}

template <class T>
TQueue<T>::TQueue(TQueue<T>&& obj) noexcept {
	this->pMem = obj.pMem;
	obj.pMem = nullptr;

	this->end = obj.end;
	this->_size = obj._size;
	this->begin = obj.begin;
}

template <class T>
void TQueue<T>::pop() {
	if (end < begin) throw std::length_error("Queue is empty!");
	begin++;
}

template <class T>
void TQueue<T>::push(T el) {
	if (end + 1 == _size) {

		T* tmp = new T[_size];
		for (size_t i = begin; i <= end; i++) {
			tmp[i - begin] = pMem[i];
		}
		delete[] pMem;

		pMem = new T[(size_t)(_size * EXP_COEF) + 1];
		for (size_t i = 0; i <= end - begin; i++) {
			pMem[i] = tmp[i];
		}

		_size = (size_t)(_size * EXP_COEF) + 1;
		end -= begin;
		begin = 0;
	}
	end++;
	pMem[end] = el;
}

template <class T>
T TQueue<T>::top() const {
	if (end < begin) throw std::length_error("Queue is empty!");
	return pMem[begin];
}

template <class T>
size_t TQueue<T>::size() const noexcept {
	return _size;
}

template <class T>
bool TQueue<T>::isEmpty() const noexcept {
	return (end < begin);
}
