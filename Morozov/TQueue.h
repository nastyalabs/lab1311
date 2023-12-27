//
// Created by egorm on 24.12.2023.
//
#include <iostream>
#ifndef QUEUE_LAB1311_TQUEUE_H
#define QUEUE_LAB1311_TQUEUE_H
using namespace std;
template <class T>
class TQueue {
private:
    T* arr;
    int capacity;
    int front_el = 0;
    int rear_el = -1;
    bool isFull(){
        return rear_el>=capacity-1;
    }
public:
    TQueue(){
        arr = new T[10];
        capacity = 10;
    }
    TQueue(int size){
        arr = new T[size];
        this->capacity = size;
    }
    TQueue(const TQueue &tQueue){
        arr = new T[tQueue.capacity*2];
        this->capacity = capacity*2;
        int i = 0;
        while(front_el<=rear_el){
            arr[i] = tQueue[front_el++];
            i++;
        }
    }
    ~TQueue(){
        delete[] arr;
    }
    void push(T el){
        if(isFull()){
            T* new_arr = new T[capacity*2];
            int i = 0;
            while(front_el<=rear_el){
                new_arr[i] = arr[front_el];
                front_el++;
                i++;
            }
            front_el = 0;
            rear_el = i-1;
            delete[]arr;
            arr = new_arr;
        }

        rear_el++;
//        cout<<front_el<<" "<<rear_el<<endl;
        arr[rear_el] = el;
    }
    T pop(){
        if(!isEmpty()) {
            return arr[front_el++];
        }
        throw std::out_of_range("Queue is Empty, the function cannot be executed successfully");
    }
    T front(){
        return arr[front_el];
    }
    T back(){
        return arr[rear_el];
    }
    bool isEmpty(){
        return front_el>rear_el;
    }
    int size(){
//        cout<<rear_el<<" "<<front_el<<endl;
        return rear_el-front_el+1;
    }
};


#endif //QUEUE_LAB1311_TQUEUE_H
