#pragma once
#include <iostream>
#include<ostream>
#include <utility>
const int MAX_QUEUE_SIZE = 100000000;
template<class T>
class TQueue {
protected:
	T* pMem;
	size_t sz;
	int end;
	int begin;
public:
	TQueue<T> () {
		sz = 3;
		pMem = new T[sz];
		begin = 0;
		end = 0;
	}
	TQueue<T>(size_t n) {
		sz = n;
		if (n<= 1) {
			throw"size should be greater than 1";
		}
		if (n > MAX_QUEUE_SIZE) {
			throw" too big size";
		}
		pMem = new T[sz];
		begin = 0;
		end = 0;
	}
	TQueue<T>(const TQueue<T>& other) {
		sz = other.sz;
		end = other.end;
		begin = other.begin;
		pMem = new T[sz];
		for (int i = 0; i < sz; i++) {
			pMem[i] = other.pMem[i];
		}
	}
	TQueue<T>& operator=(const TQueue<T>& other) {
		if (&other != this) {
			if (sz != other.sz) {
				sz = other.sz;
				delete[] pMem;
				pMem = new T[sz];
			}
			end = other.end;
			begin = other.begin;
			for (int i = begin; i < end; i++) {
				pMem[i] = other.pMem[i];
			}
		}
		return *this;
	}
	bool is_empty()const noexcept {
		if (end - begin == 0) {
			return 1;
		}
		return 0;
	}
	T pop() {
		if (is_empty()) {
			throw"Is Empty";
		}
		T elem = pMem[begin];
		T* buffer = new T[sz];
		for (size_t i = 1; i < end; i++) {
			buffer[i - 1] = pMem[i];
		}
		delete[] pMem;
		pMem = buffer;
		end--;
		return elem;


	}
	void push(T& el) {
		if (end == sz) {
			int cp = 1.5 * sz;
			T* tmp = new T[cp];
			for (int i = 0; i < sz; i++) {
				tmp[i] = pMem[i];
			}
			sz = cp;
			delete[] pMem;
			pMem = tmp;

		}
		pMem[end] = el;
		end++;
	}
	
	int size()const noexcept {
		return (end-begin);
	}
	
	friend std::ostream& operator<<(std::ostream& os, const TQueue<T>& q) {
		if (q.end - q.begin == 0) { os << "is Empty" << std::endl; }

		int a, b;
		a = q.begin;
		b = q.end;
		for (int i = a + 1; i < b; i++) {
			os << q.pMem[i];
		}
		return os;
	}
	
	~TQueue() {
		if (pMem != nullptr) {
			delete[] pMem;
		}
		pMem = nullptr;
	}
};


/*class Element {
public:
	T el;
	int pr;

};
template <class T>
std::ostream& operator<<(std::ostream& os, const Element<T> el) {
	os << el.el << "," << el.pr;
	return os;
 }*/
/*class TQueue_priority :public TQueue<Element<T>> {
	using TQueue<Element<T>>::pMem;
	using TQueue<Element<T>>::begin;
	using TQueue<Element<T>>::end;
	using TQueue<Element<T>>::sz;
public:

	TQueue_priority<T>() {
		sz = 3;
		pMem = new Element<T>[sz];
		begin = 0;
		end = 0;

	}
	TQueue_priority<T>(size_t n) {
		sz = n;
		if (n <= 1) {
			throw"size should be greater than 1";
		}
		pMem = new Element<T>[sz];
		begin = 0;
		end = 0;

	}
	TQueue_priority<T>(const TQueue_priority<T>& other) {
		sz = other.sz;
		end = other.end;
		begin = other.begin;
		pMem = new Element<T>[sz];
		for (int i = 0; i < sz; i++) {
			pMem[i] = other.pMem[i];
		}


	}
	using TQueue<Element<T>>::push;
	using TQueue<Element <T>>::is_empty;
	TQueue_priority<T>& operator=(const TQueue_priority<T>&  other){
		if (&other != this) {
			if (sz != other.sz) {
				sz = other.sz;
				delete[] pMem;
				pMem = new Element<T>[sz];

			}
			end = other.end;
			begin = other.begin;
			for (int i = begin; i < end; i++) {
				pMem[i] = other.pMem[i];
			}
		}
		return *this;
	}
	T pop() {
		if (is_empty()) {
			throw "Queue is empty";
		}
		size_t ind_min = 0;
		for (size_t i = begin; i < end; i++) {
			if (pMem[i].pr < pMem[ind_min].pr) {
				ind_min = i;
			}
		}
		T elem = pMem[ind_min].el;
		Element<T>* buffer = new Element<T>[sz];
		for (size_t i = 0; i < ind_min; i++) {
			buffer[i] = pMem[i];
		}
		for (size_t i = ind_min; i < end; i++) {
			buffer[i] = pMem[i + 1];
		}
		delete[] pMem;
		pMem = buffer;
		end--;
		return elem;
	}
	template <class U>
	friend  std::ostream& operator<<(std::ostream& os, const TQueue_priority<U>& q);
	~TQueue_priority() {
		delete[] pMem;
		pMem = nullptr;
	}

};

template <class T>

std::ostream& operator<<(std::ostream& os, const TQueue_priority<T>& q) {
	if (q.end - q.begin == 0) { os << "is Empty" << std::endl; }
	for (size_t i = q.begin; i < q.end; i++) {
		os << q.pMem[i].el << "," << q.pMem[i].pr;
	}
	return os;
}*/

