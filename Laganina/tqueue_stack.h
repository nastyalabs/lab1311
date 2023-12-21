#pragma once
#include"tstack.h"
template<typename T>
class TQueue_stack {
	size_t sz;
	TStack<T> st1;
	TStack<T> st2;
public:
	TQueue_stack<T>() {
		sz = 4;
		st1 = TStack<T>(sz);
		st2 = TStack<T>(sz);
	}
	TQueue_stack<T>(size_t sz_) {
		sz = sz_;
		st1 = TStack<T>(sz);
		st2 = TStack<T>(sz);
	}
	TQueue_stack<T>(const TStack<T>& other) {
		sz = other.sz;
		st1 = other.st1;
		st2 = other.st2;
	}
	size_t size() {
		return  sz;
	}
	bool isEmpty() {
		return((st1.size() + st2.size()) == 0);
	}
	bool isFull() {
		return(st1.isFull());
	}
	void push(const T& el) {
		st1.push(el);
	}
	T pop() {
		T el;
		if (!st2.isEmpty()) {
			el = st2.top();
			st2.cltop();
		}
		else {
			while (!st1.isEmpty()) {
				st2.push(st1.top());
					st1.cltop();
			}
			el = st2.top();
			st2.cltop();
		}
		return el;
	}

};