#pragma once
#include"tqueue.h"
template<class T>
class TQueue_priority :public TQueue<std::pair<T, int>> {
	using TQueue<std::pair<T, int>>::pMem;
	using TQueue<std::pair<T, int>>::begin;
	using TQueue<std::pair<T, int>>::end;
	using TQueue<std::pair<T, int>>::sz;
public:

	TQueue_priority<T>() {
		sz = 3;
		pMem = new std::pair<T, int>[sz];
		begin = 0;
		end = 0;

	}
	TQueue_priority<T>(size_t n) {
		sz = n;
		if (n <= 1) {
			throw"size should be greater than 1";
		}
		if (n >= MAX_QUEUE_SIZE) {
			throw"too big size";
		}
		pMem = new std::pair<T, int>[sz];
		begin = 0;
		end = 0;

	}
	TQueue_priority<T>(const TQueue_priority<T>& other) {
		sz = other.sz;
		end = other.end;
		begin = other.begin;
		pMem = new std::pair<T, int>[sz];
		for (int i = 0; i < sz; i++) {
			pMem[i] = other.pMem[i];
		}


	}
	using TQueue<std::pair<T, int>>::push;
	using TQueue<std::pair<T, int>>::is_empty;
	TQueue_priority<T>& operator=(const TQueue_priority<T>& other) {
		if (&other != this) {
			if (sz != other.sz) {
				sz = other.sz;
				delete[] pMem;
				pMem = new std::pair<T, int>[sz];

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
			if (pMem[i].second < pMem[ind_min].second) {
				ind_min = i;
			}
		}
		T elem = pMem[ind_min].first;
		std::pair<T, int>* buffer = new std::pair<T, int>[sz];
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
		os << q.pMem[i].first << "," << q.pMem[i].second << "  ";
	}
	return os;
}


