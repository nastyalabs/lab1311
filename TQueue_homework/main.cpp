#include "TQueue.hpp"
#include "TPriorityQueue.hpp"

void main() {
	/*---------------------------------------------Queue------------------------------------------------------*/
	TQueue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	std::cout << "Queue: " << q << std::endl;

	int a1 = q.pop();
	int a2 = q.pop();

	std::cout << "Queue without first and second elements: " << q << std::endl;
	std::cout << "First popped element: " << a1 << "; " << std::endl;
	std::cout << "Second popped element: " << a2 << std::endl << std::endl;
	/*---------------------------------------------Priority Queue------------------------------------------------------*/
	TPriorityQueue<int> pq;
	pq.push(1, 0);
	pq.push(2, 1);
	pq.push(3, 0);
	pq.push(4, 2);
	pq.push(5, 0);
	pq.push(6, 0);

	std::cout << "Priority queue: " << pq << std::endl;

	std::cout << "Pop priority 2: " << pq << " Was popped: " << pq.pop() << std::endl;

	std::cout << "Pop priority 1: " << pq << " Was popped:  " << pq.pop() << std::endl;

	std::cout << "Pop priority 0: " << pq << " Was popped:  " << pq.pop() << std::endl;

	std::cout << "Pop priority 0: " << pq << " Was popped:  " << pq.pop() << std::endl;

	std::cout << "Pop priority 0: " << pq << " Was popped:  " << pq.pop() << std::endl;

	std::cout << "Pop priority 0: " << pq << " Was popped:  " << pq.pop() << std::endl;
}