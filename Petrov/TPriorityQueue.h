#pragma once
#include "TQueue.h"

template <class T>
class elem {
public:
	T value;
	int priority;
};

template <class T>
class TPriorityQueue : public TQueue<elem<T>> {
private:
	elem<T>* pMem;
	size_t begin, end, size;
public:

	TPriorityQueue(int sz) : size(sz), begin(0), end(0) {
		if (sz < 1) {
			throw std::length_error("Queue size should be grater 0");
		}
		this->pMem = new elem<T>[sz];
	}

	TPriorityQueue() : TPriorityQueue(5) {}

	void push(elem<T> el) {
		if (end == size - 1) {
			elem<T>* tmp = new elem<T>[int(size * 1.5)];

			for (size_t i = 0; i < size; i++) {
				if (pMem[begin + i].priority >= 0) {
					tmp[i] = pMem[begin + i];
				}
			}

			delete[] pMem;
			pMem = tmp;
		}
		pMem[end] = el;
		end++;
	}

	void push(T el, int pr) {
		if (end == size - 1) {
			elem<T>* tmp = new elem<T>[int(size * 1.5)];

			for (size_t i = 0; i < size; i++) {
				if (pMem[begin + i].priority >= 0) {
					tmp[i] = pMem[begin + i];
				}
			}

			delete[] pMem;
			pMem = tmp;
		}
		pMem[end].value = el;
		pMem[end].priority = pr;
		end++;
	}

	T pop() {
		if (isEmpty()) {
			throw std::length_error("Queue is empty");
		}
		elem<T>* prioritied = &pMem[begin];
		for (size_t i = 0; i < (end - begin); i++) {

			if (pMem[i].priority > prioritied->priority) {
				prioritied = &pMem[i];
			}

		}
		prioritied->priority = -1;  //-1 priority means removed element

		return prioritied->value;
	}

	bool isEmpty() {
		for (size_t i = 0; i < end - begin; i++) {
			if (pMem[i].priority >= 0) return false;
		}
		return true;
	}

	template <typename U>
	friend std::ostream& operator<<(std::ostream&, TPriorityQueue<U>);
};

template <class T>
std::ostream& operator<<(std::ostream& out, TPriorityQueue<T> q) {

	for (size_t i = 0; i < (q.end - q.begin); i++) {
		if (q.pMem[q.begin + i].priority >= 0) {
			out << q.pMem[q.begin + i].value << " ";
		}
	}
	return out;

}