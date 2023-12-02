#pragma once
#include <iostream>

template <class T>
class TQueue {
private:
	T* pMem;
	size_t begin, end, size;
public:
	TQueue(int sz) : size(sz), begin(0), end(0) {
		if (sz < 1) {
			throw std::length_error("Queue size should be grater 0");
		}
		this->pMem = new T[sz];
	}

	TQueue() : TQueue(5) {}

	void push(T elem) {
		if (end == size-1) {
			T* tmp = new T[int(size * 1.5)];

			for (size_t i = 0; i < size; i++) {
				tmp[i] = pMem[begin + i];
			}

			delete[] pMem;
			pMem = tmp;
		}
		pMem[end] = elem;
		end++;
	}

	T pop() {
		if (isEmpty()) {
			throw std::length_error("Queue is empty");
		}
		return pMem[begin++];
	}

	bool isEmpty() {
		return end - begin == 0;
	}

	template <typename U>
	friend std::ostream& operator<<(std::ostream&, TQueue<U>);
};

template <class T>
std::ostream& operator<<(std::ostream& out, TQueue<T> q) {

	for (size_t i = 0; i < (q.end - q.begin); i++) {
		out << q.pMem[q.begin + i] << " ";
	}
	return out;

}

