#pragma once
#include <iostream>

using namespace std;

const int MAX_QUEUE_SIZE = 100000000;

template <typename T>
class TQueue {
private:
	int end; // указатель на конец
	int begin; //указатель на начало
	size_t sz;
	T* array;
public:
	TQueue() {
		sz = 2;
		array = new T[sz];
		begin = 0;
		end = 0;
	}
	TQueue(int n) {
		if (n <= 0) {
			throw "wrong size";
		}
		sz = n;
		array = new T[sz];
		begin = 0;
		end = 0;
	}
	~TQueue() {
		if(array) delete[]array;
	}
	void Push(T elem);
	T Pop();
	bool isEmpty();
	TQueue& operator=(const TQueue& a) {
		if (this == &a) {
			throw "assign yourself to yourself";
		}
		if (sz != a.sz) {
			T* p;
			p = new T[a.sz];
			T* p1 = array;
			sz = a.sz;
			array = p;
			delete[] p1;
		}
		for (int i = 0; i < a.end; i++) {
			array[i] = a.array[i];
		}
		begin = a.begin;
		end = a.end;
		return *this;
	}
	friend ostream& operator<<(ostream& ostr, const TQueue<T>& que) {
		for (int i = 0; i < que.end; i++) {
			ostr << que.array[i] << " ";
		}
		return ostr;
	}
};

template<typename T>
void TQueue<T>::Push(T elem) {
	if (end == sz - 1) {
		sz = (int)sz * 1, 5;
		T* tmp;
		tmp = new T[sz];
		for (int i = 0; i < end; i++) {
			tmp[i] = array[i];
		}
		T* p1 = array;
		array = tmp;
		delete[] p1;
	}
	array[end] = elem;
	end++;
}

template<typename T>
bool TQueue<T>::isEmpty() {
	if (end == begin) {
		return true;
	}
	return false;
}

template<typename T>
T TQueue<T>::Pop() {
	if (isEmpty()) {
		throw "queue is empty";
	}
	T elem = array[begin];
	T* bufer;
	bufer = new T[sz];
	for (int i = begin + 1; i < end; i++) {
		bufer[i-1] = array[i];
	}
	T* p1 = array;
	array = bufer;
	delete[]p1;
	end--;
	return elem;
}