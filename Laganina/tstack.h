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
    //T* oleg;
    //T* cursor;
    //size_t sz;
    T* pMem;
    size_t sz;
    size_t reserved;
public:
    TStack<T>() {
        pMem = new T[100];
        reserved = 100;
        sz = 0;
        // sz = 1000;
         //oleg = new T[1000];
        // cursor = oleg;

    }
    TStack<T>(size_t s) {
        if (s <= 3) {
            throw std::invalid_argument("Size should be greater than three");
        }
        reserved = s;
        sz = 0;
        pMem = new T[s];
        //sz= s;
        //oleg = new T[sz];
        //cursor = oleg;
    }
    TStack<T>(const TStack& st) {
        sz = st.sz;
        reserved = st.reserved;
        pMem = new T[reserved];
        for (size_t i = 0; i < sz; i++) {
            pMem[i] = st.pMem[i];
        }
        //sz = st.sz;
        //oleg = new T[sz];
        //for (size_t i = 0; i < sz; i++) {
            //oleg[i] = st.oleg[i];
        //}
        //cursor = oleg + (st.cursor - st.oleg);
    }
    ~TStack<T>() {
        pMem = nullptr;
        delete[] pMem;
        //delete[]oleg;
        //oleg = nullptr;
    }
    void push(T el)
    {
        if (sz == reserved) {
            reserved = sz * 1, 3;
            T* copy = new T[reserved];
            for (size_t i = 0; i < sz; i++) {
                copy[i] = pMem[i];
            }
            delete[] pMem;
            pMem = copy;

        }
        pMem[sz] = el;
        sz++;

        //if (cursor - oleg == sz) {
            //T* copy = new T[sz];
           // for (size_t i = 0; i < sz; i++) {
                //copy[i] = oleg[i];
            //}
            //delete[] oleg;
            //oleg = new T[sz * 1, 3];
            //for (size_t i = 0; i < sz; i++) {
                //oleg[i] = copy[i];
           // }
            //cursor = oleg + sz;
            //sz = sz * 1, 3;
            //delete[] copy;
            //copy = nullptr;
       // }
       // *cursor = el;
       // cursor = cursor + 1;
    }
    T top() const
    {
        if (sz == 0) {
            throw "Stack is empty";
        }
        return pMem[sz - 1];
        //if (cursor == oleg) {
            //throw "Stack is empty";
        //}
        //return *(cursor-1);
    }
    void cltop() {
        if (sz == 0) {
            throw "Stack is empty";
        }
        sz--;
        // if (cursor == oleg) {
            // throw "Stack is empty";
         //}
         //cursor = cursor - 1;
    }
    bool isFull()  const noexcept
    {
        return(sz == reserved);
        // if (cursor - oleg == sz) {
             //return true;
         //return false;
    }
    bool isEmpty()  const noexcept
    {
        return(sz == 0);
        //return (cursor == oleg);
    }
    size_t size()  const noexcept
    {
        return reserved;
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
