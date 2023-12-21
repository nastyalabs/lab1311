#pragma once
#ifndef __STACK_H__
#define __STACK_H__
#pragma once
const int MaxStackSize = 100;
#include <stdexcept>
#include <exception>
template <class T>
class TStack
{
   
    T* pMem;
    size_t sz;
    size_t reserved;
public:
    TStack<T>() {
        reserved = 100;
        pMem = new T[reserved];
        sz = 0;
        
    }
    TStack<T>(size_t s) {
        if (s <= 3) {
            throw std::invalid_argument("Size should be greater than three");
        }
        reserved = s;
        sz = 0;
        pMem = new T[s];
       
    }
    TStack<T>(const TStack& st) {
        sz = st.sz;
        reserved = st.reserved;
        pMem = new T[reserved];
        for (size_t i = 0; i < sz; i++) {
            pMem[i] = st.pMem[i];
        }
        
    }
    ~TStack<T>() {

        delete[] pMem;
        pMem = nullptr;
        
    }
    void push(T el)
    {
        if (sz == reserved) {
            reserved = sz * 1.3;
            T* copy = new T[reserved];
            for (size_t i = 0; i < sz; i++) {
                copy[i] = pMem[i];
            }
            delete[] pMem;
            pMem = copy;

        }
        pMem[sz] = el;
        sz++;

       
    }
    T top() const
    {
        if (sz == 0) {
            throw "Stack is empty";
        }
        return pMem[sz - 1];
       
    }
    void cltop() {
        if (sz == 0) {
            throw "Stack is empty";
        }
        sz--;
        
    }
    bool isFull()
    {

        return(sz == reserved);
      
    }
    bool isEmpty()  const noexcept
    {
        return(sz == 0);
       
    }
    size_t size()  const noexcept
    {
        return sz;
    }
    bool operator!=(TStack<T>& other) {
        if (sz != other.sz) {
            return true;
        }
        if (reserved != other.reserved) {
            return true;
        }
        for (size_t i = 0; i < sz; i++) {
            if (pMem[i] != other.pMem[i]) {
                return true;
            }
        }
        return false;

    }
    TStack<T>& operator=(const TStack& other) {

        if (reserved != other.reserved) {
            reserved = other.reserved;
            delete[] pMem;
            pMem = new T[reserved];
        }
        sz = other.sz;
        for (size_t i = 0; i < sz; i++) {
            pMem[i] = other.pMem[i];
        }

        return *this;
    }
};

#endif
