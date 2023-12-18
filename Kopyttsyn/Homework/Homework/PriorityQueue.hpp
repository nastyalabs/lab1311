#pragma once
template<class T>
class PriorityQueue : public TQueue<T> {
public:
    PriorityQueue(int s) : TQueue<T>(s) {}

    void pushWithPriority(T el, priority) {
        if (isFull()) {
            throw std::runtime_error("PriorityQueue is full");
        }
        if (priority < 0) {
            throw std::runtime_error("Invalid priority");
        }
        int indexToInsert = 0;
        while (indexToInsert < size && priority <= priorityQueue[indexToInsert].second) {
            indexToInsert++;
        }

        for (int i = size - 1; i >= indexToInsert; i--) {
            priorityQueue[i + 1] = priorityQueue[i];
        }

        priorityQueue[indexToInsert] = std::make_pair(el, priority);
        size++;

    }

    T popWithPriority(int priority) {
    if (isEmpty()) {
       throw std::runtime_error("PriorityQueue is empty");
    }
    if (priority < 0) {
        throw std::runtime_error("Invalid priority");
    }
    int indexToRemove = -1;
    for (int i = 0; i < size; i++) {
        if (priorityQueue[i].second == priority) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        throw std::runtime_error("No element with the specified priority");
    }

    T elementToRemove = priorityQueue[indexToRemove].first;

    for (int i = indexToRemove; i < size - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    size--;

    return elementToRemove;

    }
};