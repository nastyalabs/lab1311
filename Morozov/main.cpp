#include <iostream>
#include <queue>
#include "TQueue.h"
#include "TQueue_TStack.h"
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

    //Очередь на стеке (TStack) класс T должен переопределять оператор '<'
    TPriority_queue<int> queueTStack;
    queueTStack.push(10); //10
    queueTStack.push(20);//20 10
    queueTStack.push(30); //30 20 10
    cout<<queueTStack.back()<<endl;  //10 O(1) Минимальный элемент приоритетной очереди
    cout<<queueTStack.pop()<<endl; //30
    cout<<queueTStack.pop()<<endl; //20
    return 0;
}
