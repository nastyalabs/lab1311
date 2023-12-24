#pragma once
#include "TQueue.hpp"

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
	size_t start, end, size;

public:
	TPriorityQueue(int sz) {
		if (sz < 1) {
			throw std::length_error("Queue size should be greater than 0");
		}
		this->size = sz;
		this->start = 0;
		this->end = 0;
		this->pMem = new elem<T>[sz];
	}

	TPriorityQueue() {
		this->size = 5;
		this->start = 0;
		this->end = 0;
		this->pMem = new elem<T>[5];
	}

	void push(elem<T> el) {
		if (end == size - 1) {
			elem<T>* tmp = new elem<T>[int(size * 1.5)];

			for (size_t i = 0; i < size; i++) {
				if (pMem[start + i].priority >= 0) {
					tmp[i] = pMem[start + i];
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
				if (pMem[start + i].priority >= 0) {
					tmp[i] = pMem[start + i];
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
		elem<T>* prioritied = &pMem[start];
		for (size_t i = 0; i < (end - start); i++) {
			if (pMem[i].priority > prioritied->priority) {
				prioritied = &pMem[i];
			}
		}
		prioritied->priority = -1;  //-1 priority means removed element

		return prioritied->value;
	}

	bool isEmpty() {
		for (size_t i = 0; i < end - start; i++) {
			if (pMem[i].priority >= 0) return false;
		}
		return true;
	}

	template <class T>
	friend std::ostream& operator<<(std::ostream&, TPriorityQueue<T>);
};

template <class T>
std::ostream& operator<<(std::ostream& out, TPriorityQueue<T> q) {
	out << "{";
	for (size_t i = 0; i < (q.end - q.start); i++) {
		if (i != q.end - 1) {
			if (q.pMem[q.start + i].priority >= 0) {
				out << q.pMem[q.start + i].value << "; ";
			}
		}
		else {
			if (q.pMem[q.start + i].priority >= 0) {
				out << q.pMem[q.end - 1].value;
			}
		}
	}
	out << "}";
	return out;
}