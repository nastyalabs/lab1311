#pragma once
#include <iostream>
#include <limits>
using namespace std;

template<class T>
class TQueue {
private:
    T* queue;
    int size;
    int begin;
    int end;
public:
    TQueue(int s) : size(s), begin(0), end(0) {
        queue = new T[size];
    }

    TQueue(const TQueue<T>& other) : size(other.size), begin(other.begin), end(other.end) {
        queue = new T[size];
        for (int i = 0; i < size; i++) {
            queue[i] = other.queue[i];
        }
    }

    ~TQueue() {
        delete[] queue;
    }

    void push(T el) {
        if ((end + 1) % size == begin) {
            throw overflow_error("Queue is full");
        }
        queue[end] = el;
        end = (end + 1) % size;
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T el = queue[begin];
        begin = (begin + 1) % size;
        return el;
    }

    bool isEmpty() {
        return begin == end;
    }

    friend ostream& operator<<(ostream& os, const TQueue<T>& q) {
        if (q.isEmpty()) {
            os << "Queue is empty";
        }
        else {
            for (int i = q.begin; i != q.end; i = (i + 1) % q.size) {
                os << q.queue[i] << " ";
            }
        }
        return os;
    }
    T findMinElement(const TQueue<T>& q) {
        if (q.isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T minElement = q.begin();

        for (int i = q.begin + 1; i != q.end; i = (i + 1) % q.size) {
            minElement = min(minElement, q.queue[i]);
        }
        return minElement;
    }
};