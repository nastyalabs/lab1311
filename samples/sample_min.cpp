#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

double min(TQueue<double> queue) 
{
	double min;
	min = queue.Top();
	queue.Pop();
	while (!queue.IsEmpty()) 
	{
		double current = queue.Top();
		queue.Pop();
		if (min > current) 
		{
			min = current;
		}
	}
	return min;
}

int main()
{
	std::cout << "Enter queue items. To stop typing, enter something other than a number" << std::endl;
	TQueue<double> queue;
	while (true)
	{
		string current;
		std::cin >> current;
		try
		{
			double num = stod(current);
			queue.Push(num);
		}
		catch (...) {
			break;
		}
	}
	std::cout << "minimum " << min(queue);
	return 0;
}
