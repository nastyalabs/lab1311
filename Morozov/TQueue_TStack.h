//
// Created by egorm on 25.12.2023.
//

#ifndef QUEUE_LAB1311_TQUEUE_TSTACK_H
#define QUEUE_LAB1311_TQUEUE_TSTACK_H

#include "TStack.h"
#include <iostream>

using namespace std;

template<class T>
class TQueue_TStack {
private:
    TStack<T> stack;
public:
    TQueue_TStack() {
//        stack = new TStack<T>();
    }

    TQueue_TStack(const TStack<T> &stack) {
        this->stack = stack;
    }

    TQueue_TStack(const TQueue_TStack<T> &queueTStack) {
        this->stack = queueTStack.stack;
    }

    void push(T el) {
        stack.push(el);
    }

    T pop() {
        TStack<T> new_stack;
        while (!stack.isEmpty()) {
            new_stack.push(stack.pop());
        }
        T res = new_stack.pop();
        while (!new_stack.isEmpty()) {
            stack.push(new_stack.pop());
        }
        return res;
    }

    bool isEmpty() {
        return stack.isEmpty();
    }

    int size() {
        return stack.getSize();
    }

    T front() {
        TStack<T> new_stack;
        while (!stack.isEmpty()) {
            new_stack.push(stack.pop());
        }
        T res = new_stack.top();
        while (!new_stack.isEmpty()) {
            stack.push(new_stack.pop());
        }
        return res;
    }

    T back() {
        return stack.top();
    }

};


#endif //QUEUE_LAB1311_TQUEUE_TSTACK_H
