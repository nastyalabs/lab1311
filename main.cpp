#include <iostream>
#include "TQueue.h"

int main()
{
	std::cout << "Queue default\n";
	TQueue<int> qu1(3);
	qu1.push(5);
	qu1.push(3);
	qu1.push(6);
	qu1.push(7);
	std::cout << qu1 << std::endl;
	qu1.pop();
	std::cout << qu1 << std::endl;
	TQueuePr<int> quPr1;

	std::cout << "Queue with priority\n";
	TQueuePr<int> quPr2(3, 3);
	quPr2.push(1, 0);
	quPr2.push(2, 2);
	quPr2.push(3, 0);
	quPr2.push(4, 2);
	quPr2.push(5, 1);
	std::cout << quPr2 << std::endl;
	quPr2.pop();
	std::cout << quPr2 << std::endl;
	return 0;
}