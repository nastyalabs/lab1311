#include "TQueue.h"
#include "TPriorityQueue.h"
#include "TStackQueue.h"
#include <iostream>

int main() {
	// queue
	TQueue<int> simple_q;
	simple_q.push(1);
	simple_q.push(2);
	simple_q.push(3);
	std::cout << simple_q << std::endl; // 1 2 3
	simple_q.pop();
	std::cout << simple_q << std::endl; // 2 3
	simple_q.push(1);
	std::cout << simple_q << std::endl; // 2 3 1
	std::cout << simple_q.top() << std::endl << std::endl; // 2

	// priority queue
	TPriorityQueue<int> priority_q(4);
	priority_q.push(1, 4); // value, priority
	priority_q.push(2, 3);
	priority_q.push(3, 2);
	priority_q.push(4, 1);
	std::cout << priority_q; // 1 2 3 4 

	std::cout << std::endl;

	std::cout << priority_q.top() << std::endl; // 1
	std::cout << std::endl;
	priority_q.pop();
	std::cout << priority_q; // 2 3 4

	std::cout << std::endl;
	priority_q.push(10, 4);
	priority_q.push(33, 0);
	priority_q.push(14, 2);
	std::cout << priority_q; // 10 2 3 14 4 33


	//4
	int smallestEl = priority_q.top().value;
	TPriorityQueue<int> temp(priority_q);
	while (!temp.isEmpty()) {
		if (smallestEl > temp.top().value) {
			smallestEl = temp.top().value;
		}
		temp.pop();
	}
	std::cout << std::endl << "Smallest elem: " << smallestEl << std::endl << std::endl; // 2

	//3 stack-based queue
	TStackQueue<int> stack_queue;
	stack_queue.Push(1);
	stack_queue.Push(2);
	stack_queue.Push(3);
	std::cout << stack_queue << std::endl; // 1 2 3
	stack_queue.Pop();
	std::cout << stack_queue << std::endl; // 2 3
	stack_queue.Push(1);
	std::cout << stack_queue << std::endl; // 2 3 1
	std::cout << stack_queue.Top() << std::endl << std::endl; // 2

	return 0;
}