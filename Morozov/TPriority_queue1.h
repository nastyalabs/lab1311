//
// Created by egorm on 25.12.2023.
//

#ifndef QUEUE_LAB1311_TPRIORITY_QUEUE1_H
#define QUEUE_LAB1311_TPRIORITY_QUEUE1_H
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

template <class T>
class PriorityQueue {
public:
    PriorityQueue(std::function<bool(const T&, const T&)> comparator)
            : comparator_(comparator) {}

    bool Empty() const { return elements_.empty(); }
    const T& Top() const {
        if (Empty()) {
            throw std::runtime_error("Queue is empty.");
        }
        return elements_.front();
    }

    void Enqueue(const T& value) {
        elements_.push_back(value);
        SiftUp(elements_.size() - 1);
    }

    T Dequeue() {
        T value = elements_.front();
        elements_.pop_front();
        if (!elements_.empty()) {
            SiftDown(0);
        }
        return value;
    }
private:
    std::vector<T> elements_;
    std::function<bool(const T&, const T&)> comparator_;
    int Parent(int index) const { return (index - 1) / 2; }

    int Left(int index) const { return 2 * index + 1; }
    int Right(int index) const { return 2 * index + 2; }

    void Swap(int a, int b) {
        std::swap(elements_[a], elements_[b]);
        std::iter_swap(elements_.begin() + a, elements_.begin() + b);
    }

    void SiftUp(int index) {
        while (index > 0 && comparator_(elements_[index], elements_[Parent(index)])) {
            Swap(index, Parent(index));
            index = Parent(index);
        }
    }

    void SiftDown(int index) {
        int smallest = index;
        if (Left(index) < elements_.size() && comparator_(elements_[Left(index)], elements_[smallest])) {
            smallest = Left(index);
        }

        if (Right(index) < elements_.size() && comparator_(elements_[Right(index)], elements_[smallest])) {
            smallest = Right(index);
        }

        if (smallest != index) {
            Swap(smallest, index);
            SiftDown(smallest);
        }
    }
};


#endif //QUEUE_LAB1311_TPRIORITY_QUEUE1_H
