#include <iostream>
#include <queue>
#include "TQueue.h"
#include "TQueue_TStack.h"
#include "TPriority_Queue.h"
#include "TPriority_queue1.h"
using namespace  std;
int main() {
    //Очередь на динамическом массиве
    TQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    cout<<queue.size()<<endl; //4;
    cout<<queue.front()<<" "<<queue.back()<<endl; //1 4
    while(!queue.isEmpty()){
        cout<<queue.pop()<<endl; // 1 2 3 4
    }
    cout<<queue.size()<<endl; // 0

    //Очередь на стеке (TStack)
    TQueue_TStack<int> queueTStack;
    queueTStack.push(10);
    queueTStack.push(20);
    queueTStack.push(30);
    cout<<queueTStack.pop()<<endl; // 10
    cout<<queueTStack.size()<<endl; // 2;
    cout<<queueTStack.front()<<" "<<queueTStack.back()<<endl; //20 30
    cout<<queueTStack.isEmpty()<<endl; // false;

    //Приоритетная очередь, для правильной работы класс T должен иметь переопределенный оператор<
    TPriority_Queue<int> priorityQueue;
    priorityQueue.push(4); // Queue - 4
    priorityQueue.push(13); // Queue - 13,4
    priorityQueue.push(10); // Queue - 13,10,4
    cout<<priorityQueue.pop()<<endl; // 13;
    cout<<priorityQueue.front()<<" "<<priorityQueue.back()<<endl; // 10 4
    return 0;
}
