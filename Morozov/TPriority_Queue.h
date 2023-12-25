//
// Created by egorm on 25.12.2023.
//

#ifndef QUEUE_LAB1311_TPRIORITY_QUEUE_H
#define QUEUE_LAB1311_TPRIORITY_QUEUE_H

#include <iostream>

using namespace std;

template<class T>
class TPriority_Queue {
private:
    T *arr;
    int capacity = 0;
    int front_el = 0;
    int rear_el = -1;

    bool isFull() {
        return rear_el >= capacity - 1;
    }

public:
    TPriority_Queue() {
        arr = new T[10];
        capacity = 10;
    }

    TPriority_Queue(int size) {
        this->arr = new T[size];
        this->capacity = size;
    }

    TPriority_Queue(const TPriority_Queue<T> &TPriority_Queue) {
        arr = new T[capacity * 2];
        this->capacity = capacity * 2;
        int i = 0;
        while (front_el <= rear_el) {
            arr[i] = TPriority_Queue.arr[front_el++];
            i++;
        }
    }

    ~TPriority_Queue() {
        delete[] arr;
    }

    void push(T el) {
        if (isFull()) {
            T *new_arr = new T[capacity * 2];
            int i = 0;
            while (front_el <= rear_el) {
                new_arr[i] = arr[front_el++];
                i++;
            }
            front_el = 0;
            rear_el = i - 1;
            delete[]arr;
            arr = new_arr;
        }
        int i = front_el;
        while (i <= rear_el) {
            if (el > arr[i]) {
                for (int j = rear_el + 1; j > i; --j) {
                    arr[j] = arr[j - 1];
                }
                break;
            }
            i++;
        }

        arr[i] = el;
        rear_el++;
    }

    T pop() {
        if (!isEmpty()) {
            return arr[front_el++];
        }
        throw std::out_of_range("Queue is Empty, the function cannot be executed successfully");
    }

    T front() {
        return arr[front_el];
    }

    T back() {
//        cout<<rear_el<<" "<<endl;
        return arr[rear_el];

    }

    bool isEmpty() {
        return front_el > rear_el;
    }

    int size() {
        return rear_el - front_el + 1;
    }
};


#endif //QUEUE_LAB1311_TPRIORITY_QUEUE_H
