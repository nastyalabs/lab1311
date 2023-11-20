#pragma once
#include <stdexcept>
#include <ostream>

template <typename T>
class TSingleLinkedList
{
	class Node
	{
	public:
		Node(const T& _value) : value(_value), next(nullptr) {}
		T value;
		Node* next;
	};
	Node& operator=(const Node&) = delete;
	Node* first;
	Node* last;
public:
	//void Link(TSingleLinkedList* next) {
	//	this->next = next;
	//}
	TSingleLinkedList() {
		first = nullptr;
		last = nullptr;
	}
	TSingleLinkedList(const T& element)
	{
		first = new Node(element);
		last = first;
	}
	void Add(const T& value);
	void Remove(size_t num = 0);
	bool IsEmpty() const
	{
		return !first;
	}
	~TSingleLinkedList();
	T& At(size_t num = 0);
	T& Last()
	{
		return last->value;
	}
	const T& Last() const
	{
		if (!first) throw std::out_of_range("list is over");
		return last->value;
	}
	const T& At(size_t num = 0) const;
	friend std::ostream& operator<< (std::ostream& stream, const TSingleLinkedList<T>& list) {
		stream << list.first->value << '\n';
		Node* current = list.first;
		while (current = current->next) {
			stream << current->value;
		}
		return stream;
	}
};

template<typename T>
inline void TSingleLinkedList<T>::Add(const T& value) {
	if (!first)
	{
		first = new Node(value);
		last = first;
	}
	else {
		last->next = new Node(value);
		last = last->next;
	}
}

template<typename T>
inline void TSingleLinkedList<T>::Remove(size_t num) {
	if (!first) throw std::out_of_range("list is over");
	Node* current = first;
	Node* prev = nullptr;
	while (num > 0)
	{
		prev = current;
		if ((current = current->next) == nullptr) throw std::out_of_range("list is over");
		num--;
	}
	Node* next = current->next;
	if (prev != nullptr) prev->next = next;
	else
	{
		first = next;
	}
	delete current;
	if (!first) last = nullptr;
}

template<typename T>
inline TSingleLinkedList<T>::~TSingleLinkedList() {
	if (first == last) {
		delete first;
	}
	else {
		Node* prev = first;
		while (Node* current = prev->next)
		{
			delete prev;
			prev = current;
		}
		delete prev;
	}
}

template<typename T>
inline T& TSingleLinkedList<T>::At(size_t num) {
	if (!first) throw std::out_of_range("list is over");
	Node* current = first;
	while (num > 0)
	{
		if ((current = current->next) == nullptr) throw std::out_of_range("list is over");
		num--;
	}
	return current->value;
}

template<typename T>
inline const T& TSingleLinkedList<T>::At(size_t num) const {
	if (!first) throw std::out_of_range("list is over");
	Node* current = first;
	while (num > 0)
	{
		if ((current = current->next) == nullptr) throw std::out_of_range("list is over");
		num--;
	}
	return current->value;
}
