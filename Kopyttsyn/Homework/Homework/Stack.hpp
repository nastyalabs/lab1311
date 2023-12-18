#pragma once
template<class T>
class Stack {
private:
    T* stack;
    int size;
    int top;
public:
    Stack(int s) : size(s), top(-1) {
        stack = new T[size];
    }

    Stack(const Stack<T>& other) : size(other.size), top(other.top) {
        stack = new T[size];
        for (int i = 0; i <= top; i++) {
            stack[i] = other.stack[i];
        }
    }

    ~Stack() {
        if (stack != nullptr) {
            delete[] stack;
        }
    }

    void push(T el) {
        if (top == size - 1) {
            throw overflow_error("Stack is full");
        }
        stack[++top] = el;
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return stack[top--];
    }

    T gettop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return stack[top];
    }

    void clear() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    int getSize() {
        return size;
    }
    T peek(int n) {
        if (n < 0 || n > top) {
            throw out_of_range("Index out of range");
        }
        return stack[n];
    }

    void reverse() {
        T* temp = new T[size];
        for (int i = 0, j = top; i <= top; i++, j--) {
            temp[i] = stack[j];
        }
        delete[] stack;
        stack = temp;
    }
}; 







































































//template<typename T>
//class TDynamicStack {
//	int top;
//	size_t memSize;
//	T* pMem;
//public:
//	TDynamicStack(const TDynamicStack& tmp) = delete;
//	TDynamicStack operator = (const TDynamicStack& tmp) = delete;
//	TDynamicStack(TDynamicStack&& tmp) = delete;
//	TDynamicStack& operator=(TDynamicStack&& tmp) = delete;
//	TDynamicStack() : top(-1), memSize(1), pMem(new T[memSize]) {}
//	~TDynamicStack() { delete[] pMem; }
//	size_t size() const { return top + 1; }
//	bool isEmpty() const { return top == -1; }
//	T Pop() { 
//		if (isEmpty()) {
//			throw std::out_of_range("Stack Underflow"); 
//		}
//		return pMem[top--]; 
//	}
//	void Push(const T& val) {
//		if (top == memSize - 1) {
//			T* tmpMem = new T[memSize * 2];
//			std::copy(pMem, pMem + memSize, tmpMem);
//			delete[] pMem;
//			pMem = tmpMem;
//			memSize *= 2;
//		}
//		pMem[++top] = val;
//	
//	}
//
//	const T& Top() const {
//		if (isEmpty()) {
//			throw std::out_of_range("Stack Underflow");
//		}
//		return pMem[top];
//	}
//};