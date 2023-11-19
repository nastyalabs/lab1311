#include "TQueue.h"
#include "TPriorityQueue.h"

void main() {
/*---------------------------------------------Queue------------------------------------------------------*/
	TQueue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	std::cout << q << std::endl;

	int a1 = q.pop();
	int a2 = q.pop();

	std::cout << q << std::endl << a1 << " " << a2 << std::endl;

/*---------------------------------------------Priority Queue------------------------------------------------------*/
	TPriorityQueue<int> pq;
	pq.push(1, 0);
	pq.push(2, 1);
	pq.push(3, 0);
	pq.push(4, 2);
	pq.push(5, 0);
	pq.push(6, 0);

	std::cout << pq << std::endl;

	std::cout << pq << " | " << pq.pop() << std::endl;

	std::cout << pq << " | " << pq.pop() << std::endl;

	std::cout << pq << " | " << pq.pop() << std::endl;

	std::cout << pq << " | " << pq.pop() << std::endl;

	std::cout << pq << " | " << pq.pop() << std::endl;

	std::cout << pq << " | " << pq.pop() << std::endl;

	if (false) { //otval danger
		std::cout << pq << " | " << pq.pop() << std::endl;
	}

}