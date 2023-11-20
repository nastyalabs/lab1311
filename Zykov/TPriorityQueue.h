#pragma once
#include "TQueue.h"

template <class T>
struct el {
	T value;
	int priority;

	template <class K>
	friend std::ostream& operator<<(std::ostream& ostr, const el<K>& obj);

	~el() {}
};

template <class T>
std::ostream& operator<<(std::ostream& ostr, const el<T>& obj) {
	ostr << obj.value;
	return ostr;
}

template <class T>
class TPriorityQueue : public TQueue<el<T>> {
private:
	using TQueue<el<T>>::pMem;
	using TQueue<el<T>>::_size;
	using TQueue<el<T>>::begin;
	using TQueue<el<T>>::end;
public:
	TPriorityQueue(int n = 2) : TQueue<el<T>>(n) {};
	TPriorityQueue(const TPriorityQueue<T>& obj) : TQueue<el<T>>(obj) {};
	TPriorityQueue(TPriorityQueue<T>&& obj) : TQueue<el<T>>(obj) {};

	~TPriorityQueue() { delete[] pMem; }

	void push(el<T> el);
	void push(T val, int pr);

	template <class K>
	friend std::ostream& operator<<(std::ostream& ostr, const TPriorityQueue<K>& obj);
};

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TPriorityQueue<T>& obj) {
	for (size_t i = obj.begin; i <= obj.end; i++) {
		ostr << obj.pMem[i] << std::endl;
	}
	return ostr;
}

template <class T>
void TPriorityQueue<T>::push(el<T> elem) {
	if (end + 1 == _size) {
		el<T>* tmp = new el<T>[_size];
		for (size_t i = begin; i <= end; i++) {
			tmp[i - begin] = pMem[i];
		}
		delete[] pMem;

		pMem = new el<T>[(size_t)(_size * EXP_COEF) + 1];
		for (size_t i = 0; i <= end - begin; i++) {
			pMem[i] = tmp[i];
		}

		_size = (size_t)(_size * EXP_COEF) + 1;
		end -= begin;
		begin = 0;
	}

	int i = begin;
	while (i <= end && elem.priority <= pMem[i].priority) { i++; }
	if (i > end) { pMem[i] = elem; end++; }
	else {
		el<T>* tmp = new el<T>[end - i + 2];
		tmp[0] = elem;
		for (size_t j = 1; j < end - i + 2; j++) {
			tmp[j] = pMem[i + j - 1];
		}
		for (size_t j = i; j <= end + 1; j++) {
			pMem[j] = tmp[j - i];
		}
		end++;
	}
}

template <class T>
void TPriorityQueue<T>::push(T val, int pr) {
	el<T> elem;
	elem.value = val;
	elem.priority = pr;
	push(elem);
}