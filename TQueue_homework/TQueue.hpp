#pragma once
#include <iostream>

template <class T>
class TQueue {
private:
	T* pMem;
	size_t start, end, size;

public:
	TQueue(int sz) {
		if (sz < 1) {
			throw std::length_error("Queue size should be greater than 0");
		}
		this->size = sz;
		this->start = 0;
		this->end = 0;
		this->pMem = new T[sz];
	}

	TQueue() {
		this->size = 5;
		this->start = 0;
		this->end = 0;
		this->pMem = new T[5];
	}

	void push(T el) {
		if (end == size - 1) {
			T* tmp = new T[int(size * 1.5)];

			for (size_t i = 0; i < size; i++) {
				tmp[i] = pMem[start + i];
			}
			delete[] pMem;	
			pMem = tmp;
		}
		pMem[end] = el;
		end++;
	}

	T pop() {
		if (isEmpty()) {
			throw std::length_error("Queue is empty");
		}
		return pMem[start++];
	}

	bool isEmpty() {
		return end - start == 0;
	}

	template <class T>
	friend std::ostream& operator<<(std::ostream&, TQueue<T>);
};

template <class T>
std::ostream& operator<<(std::ostream& out, TQueue<T> q) {
	out << "{";
	for (size_t i = 0; i < (q.end - q.start); i++) {
		if (i != q.end - 1) {
			out << q.pMem[q.start + i] << "; ";
		}
		else {
			out << q.pMem[q.end - 1];
		}
	}
	out << "}";
	return out;
}