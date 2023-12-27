//
// Created by egorm on 25.12.2023.
//

#ifndef QUEUE_LAB1311_TQUEUE_TSTACK_H
#define QUEUE_LAB1311_TQUEUE_TSTACK_H

#include "TStack.h"
#include <iostream>

using namespace std;

template<class T>
class TPriority_queue {
private:
    TStack<T> stack1;
    TStack<T> stack2;
public:
    TPriority_queue(){}

    TPriority_queue(const TPriority_queue<T> &queueTStack) {
        this->stack1 = queueTStack.stack1;
        this->stack2 = queueTStack.stack2;
    }

    void push(T el) {
        while (!stack1.isEmpty()) {
            T elem = stack1.top();
            if (elem < el) {
                stack2.push(stack1.pop());
            } else {
                break;
            }
        }
        stack2.push(el);
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    T pop() {
        while (!stack1.isEmpty()){
            stack2.push(stack1.pop());
        }
        T el = stack2.pop();
        while (!stack2.isEmpty()){
            stack1.push(stack2.pop());
        }
        return el;
    }

    bool isEmpty() {
        return stack1.isEmpty();
    }

    int size() {
        return stack1.getSize();
    }

    T front() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        T res = stack2.top();
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        return res;
    }
    // Минимальный элемент очереди
    T back() {
        return stack1.top();
    }

};


#endif //QUEUE_LAB1311_TQUEUE_TSTACK_H
