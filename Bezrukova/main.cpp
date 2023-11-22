#include "QuePriority.h"
#include "tqueue.h"

int main() {
	TQueue<int> queue1(5);
	for (int i = 0; i < 5; i++) {
		queue1.Push(i);
	}
	cout << "queue: ";
	for (int i = 0; i < 5; i++) {
		cout << queue1.Pop() << " ";
	}

	TQueuePriority<int> queue2(3);
	queue2.Push({ 1,3 });
	queue2.Push({ 2,4 });
	queue2.Push({ 3,3 });
	cout << "\n" << "queue with priority: ";
	for (int i = 0; i < 3; i++) {
		cout << queue2.Pop() << " ";
	}
}
