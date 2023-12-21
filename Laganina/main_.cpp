#include "tqueue.h"
#include"tqueue_priority.h"
#include"tqueue_stack.h"

int min(const TQueue_stack<int>& q) {
	TQueue_stack<int> buffer = q;
	int m = buffer.pop();
	while (!buffer.isEmpty()) {
		int buf = buffer.pop();
		if (buf < m) {
			m = buf;
		}
	}
	return m;
}
int main() {
	TQueue <int> q1;

	std::cout << q1;
	std::cout << q1.size() << std::endl;
	std::cout << q1.is_empty() << std::endl;
	for (int i = 0; i < 5; i++) {
		q1.push(i);
	}
	TQueue<int> q(q1);
	std::cout << q << std::endl;
	std::cout << q1 << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << q1.pop() << " ";
	}
	
	TQueue <int> q2(3);
	std::cout << q2 << std::endl;
	q2 = q;
	std::cout << q;
	TQueue_priority <double> q3;
	std::cout << q3 << std::endl;
	std::pair<double, int>a(2.0, 0);
	std::pair<double, int>b(3.0, 1);
	std::pair<double, int>c(4.0, 2);
	q3.push(b);
	q3.push(c);
	q3.push(a);
	std::cout << q3 << std::endl;
	for (size_t i = 0; i < 3; i++) { std::cout << q3.pop() << "    "<<std::endl; }
	TQueue_stack<int> qs;
	std::cout << qs.size() << std::endl;
	qs.push(3);
	std::cout << qs.pop() << std::endl;
	for (int i = 0; i < 5; i++) {
		qs.push(i);
	}

	int m= min(qs);
	std::cout << m << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << qs.pop() << "   ";
	}
	std::cout << qs.isFull() << std::endl;
	std::cout << qs.isEmpty() << std::endl;

}