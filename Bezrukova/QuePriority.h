#pragma once
#include <utility>
#include <iostream>

using namespace std;

template <typename T>
class TQueuePriority {
private:
	pair<T, int>* array;
	size_t sz;
	int begin;
	int end;
public:
	TQueuePriority() {
		sz = 2;
		begin = 0;
		end = 0;
		array = new pair<T, int>[sz];
	}
	TQueuePriority(size_t n) {
		sz = n;
		begin = 0;
		end = 0;
		array = new pair<T, int>[sz];
	}
	//TQueuePriority(const TQueuePriority& que) {
	//	sz = que.sz;
	//	begin = que.begin;
	//	end = que.end;
	//	array = new pair<T, int>[sz];
	//	for (int i = 0; i < que.end; i++) {
	//		array[i] = que.array[i]; 
	//	}
	//}
	bool isEmpty();
	void Push(pair<T, int> elem);
	T Pop();
	TQueuePriority& operator=(const TQueuePriority& que) {
		if (this == &que) {
			throw "assign yourself to yourself";
		}
		if (sz != que.sz) {
			sz = que.sz;
			pair<T, int>* tmp = new pair<T, int>[sz];
			pair<T, int>* p1 = array;
			array = tmp;
			delete[]p1;
		}
		for (int i = 0; i < que.end; i++) {
			array[i] = que.array[i];
		}
		begin = que.begin;
		end = que.end;
		return *this;
	}
	friend ostream& operator<<(ostream& ostr, const TQueuePriority<T>& que) {
		for (int i = 0; i < que.end; i++) {
			ostr << "element: " << que.array[i].first << " ";
			ostr << "priority: " << que.array[i].second << " ";
		}
		return ostr;
	}
	~TQueuePriority() {
		delete[]array;
	}
};

template <typename T>
bool TQueuePriority<T>::isEmpty() {
	if (begin == end) {
		return true;
	}
	return false;
}

template <typename T>
void TQueuePriority<T>::Push(pair<T, int> elem) {
	if (end + 1 == sz) {
		sz = (int)sz * 1, 5;
		pair<T, int>* bufer = new pair<T, int>[sz];
		for (int i = 0; i < end; i++) {
			bufer[i].first = array[i].first;
			bufer[i].second = array[i].second;
		}
		pair<T, int>* p1 = array;
		array = bufer;
		delete[]p1;
	}
	array[end].first = elem.first;
	array[end].second = elem.second;
	end++; 
}

template <typename T>
T TQueuePriority<T>::Pop() {
	if (isEmpty()) {
		throw "queue is Empty";
	}
	int index = begin; 
	int min = array[begin].second; 
	for (int i = begin + 1; i < end; i++) {
		if (array[i].second < min) {
			min = array[i].second;
			index = i;
		}
	}
	T elem = array[index].first;
	pair<T, int>* bufer = new pair<T, int>[sz];
	for (int i = begin; i < index; i++) {
		bufer[i].first = array[i].first;
		bufer[i].second = array[i].second;
	}
	for (int i = index + 1; i < end; i++) {
		bufer[i - 1].first = array[i].first;
		bufer[i - 1].second = array[i].second;
	}
	pair<T, int>* p1 = array;
	array = bufer;
	delete[]p1;
	end--;
	return elem;
}











//class QuePriority : public TQueue<T> {
//private:
//	using TQueue<T>::sz;
//	using TQueue<T>::end;
//	using TQueue<T>::begin;
//	using TQueue<T>::array;
//	int* priority; //массив приоритетов
//public: 
//	QuePriority() :TQueue<T>() {
//		int* ptiority = new int* [sz];
//		for (int i = 0; i < sz; i++) {
//			priority[i] = 0;
//		}
//	}
//	QuePriority(int n) {
//		if (n <= 0) {
//			throw "wrong size";
//		}
//		sz = n;
//		T* array = new T[sz];
//		int* priority = new int[n];
//		for (int i = 0; i < sz; i++) {
//			priority[i] = 0;
//		}
//		begin = 0;
//		end = 1;
//	}
//	void Push(T elem, int prior);
//	T Pop();
//	QuePriority& operator=(const QuePriority& a) {
//		if (this == &a) {
//			return *this;
//		}
//		if (sz != a.sz) {
//			T* p1 = new T[a.sz];
//			int* p2 = new int[a.sz];
//			delete[]array;
//			delete[]priority;
//			sz = a.sz;
//			array = p1;
//			priority = p2;
//		}
//		for (int i = 0; i < a.end; i++) {
//			priority[i] = a.priority[i];
//			array[i] = a.array[i];
//		}
//		begin = a.begin;
//		end = a.end;
//		return *this;
//	}
//	using TQueue<T>:: isEmpty;
//	~QuePriority() {
//		delete[] array;
//		delete[] priority;
//	}
//};
//
//template<typename T>
//void QuePriority<T>::Push(T elem, int prior) {
//	if (end == sz - 1) {
//		sz = (int)sz * 1, 5;
//		T* tmp = new T[sz];
//		int* tmp2 = new int[sz];
//		for (int i = 0; i < end; i++) {
//			tmp[i] = array[i];
//			tmp2[i] = priority[i];
//		}
//		delete[]array;
//		T* array = tmp;
//		delete[]priority;
//		int* priority = tmp2;
//	}
//	int flag = end;
//	for (int i = end-1; i >= 0; i--) {
//		if (prior == priority[i]) {
//			flag = i+1;//позиция, на которую нужно поставить элемент
//			break;
//		}
//		if (prior > priority[i]) {
//			flag--;
//		}
//		else break;
//	}
//	T* bufer1 = new T[sz];
//	int* bufer2 = new int[sz];
//	for (int i = 0; i < flag; i++) {
//		bufer2[i] = priority[i];
//		bufer1[i] = array[i];
//	}
//	bufer2[flag] = prior;
//	bufer1[flag] = elem;
//	for (int i = flag; i < end; i++) {
//		bufer2[i + 1] = priority[i];
//		bufer1[i + 1] = array[i];
//	}
//	delete[]priority;
//	int* priority = bufer2;
//	delete[]array;
//	T* array = bufer1;
//	end++;
//}
//
//
//template <typename T>
//T QuePriority<T>::Pop() {
//	if (isEmpty()) {
//		throw "queue is empty";
//	}
//	T elem = array[begin];
//	T* bufer1 = new T[sz];
//	int* bufer2 = new int[sz];
//	for (int i = begin + 1; i < end; i++) {
//		bufer1[i - 1] = array[i];
//		bufer2[i - 1] = priority[i];
//	}
//	delete[]array;
//	array = bufer1;
//	delete[]priority;
//	priority = bufer2;
//	end--;
//	return elem;
//}