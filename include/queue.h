#pragma once
#include "stack.h"

template <typename T>
class TQueue : public IDataStrucure<T>
{
    TStack<T> left;
    TStack<T> right;
    void Transfer();
public:
    TQueue() : left(), right() {}
    TQueue(const TQueue<T>& queue) : left(queue.left), right(queue.right) {}
    void Push(const T& elem);
    T& Top();
    bool IsEmpty() const;
    size_t Size() const;
    void Pop();
    friend std::ostream& operator<< (std::ostream& stream, const TQueue<T> queue) {
        stream << queue.left;
        TStack<T> current(queue.right);
        while (!current.IsEmpty()) {
            stream << current.Top() << '\n';
            current.Pop();
        }
        return stream;
    }
};

template<typename T>
inline void TQueue<T>::Transfer() {
    if (right.IsEmpty()) {
        if (left.IsEmpty()) throw std::out_of_range("TQueue is empty");
        while (!left.IsEmpty()) {
            right.Push(left.Top());
            left.Pop();
        }
    }
}

template<typename T>
inline void TQueue<T>::Push(const T& elem)
{
    left.Push(elem);
}

template<typename T>
inline T& TQueue<T>::Top()
{
    Transfer();
    return right.Top();
}

template<typename T>
inline bool TQueue<T>::IsEmpty() const
{
    return left.IsEmpty() && right.IsEmpty();
}

template<typename T>
inline size_t TQueue<T>::Size() const
{
    return left.Size() + right.Size();
}

template<typename T>
inline void TQueue<T>::Pop()
{
    Transfer();
    right.Pop();
}

