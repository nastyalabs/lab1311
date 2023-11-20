#pragma once
#include <iostream>
template<typename T>
class TQueue
{
protected:
	T* end;
	T* begin;
	T* array;
	int size;
public:
	TQueue();
	TQueue(int n);
	int Size()
	{
		return size;
	}
	void push(T a);
	T top();
	void pop();
	bool isEmpty();
	~TQueue();
	friend std::ostream& operator<<(std::ostream& out, const TQueue<T>& a)
	{
		for (int i = 0; i < a.end - a.begin; i++)
		{
			out << a.begin[i] << " ";
		}
		return out;
	}
};

template<typename T>
TQueue<T>::TQueue(int n)
{
	if (n <= 0)
	{
		throw std::exception("Wrong size");
	}
	array = new T[n];
	size = n;
	begin = array;
	end = array;
}

template<typename T>
TQueue<T>::TQueue() : TQueue<T>::TQueue(1){}

template<typename T>
void TQueue<T>::push(T a)
{
	if (end - array == size)
	{
		size = size * 2;
		T* tmp = new T[size];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = array[i];
		}
		delete[] array;
		end = tmp + (end - array);
		array = tmp;
		begin = array;
	}
	*end = a;
	end++;
}

template<typename T>
T TQueue<T>::top()
{
	if (end == begin)
	{
		throw std::exception("Queue is empty");
	}
	return begin;
}

template<typename T>
void TQueue<T>::pop()
{
	if (end == begin)
	{
		throw std::exception("Queue is empty");
	}
	begin++;
}

template<class T>
bool TQueue<T>::isEmpty()
{
	if (begin == end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
TQueue<T>::~TQueue()
{
	delete[] array;
}


template<typename T>
class TQueuePr :public TQueue<T>
{
private:
	int amountOfPriority;
	int* arrayOfPriority;
public:
	TQueuePr(int n, int _amountOfPriority) :TQueue<T>(n)
	{
		amountOfPriority = _amountOfPriority;
		arrayOfPriority = new int[_amountOfPriority];
		for (int i = 0; i < amountOfPriority; i++)
		{
			arrayOfPriority[i] = 0;
		}
	}
	TQueuePr():TQueue<T>(), amountOfPriority(3)
	{
		arrayOfPriority = new int[3];
		for (int i = 0; i < amountOfPriority; i++)
		{
			arrayOfPriority[i] = 0;
		}
	}
	void push(T a, int priority)
	{
		if (TQueue<T>::end - TQueue<T>::array == TQueue<T>::size)
		{
			TQueue<T>::size = TQueue<T>::size * 2;
			T* tmp = new T[TQueue<T>::size];
			for (int i = 0; i < (TQueue<T>::end - TQueue<T>::begin); i++)
			{
				tmp[i] = TQueue<T>::array[i + (TQueue<T>::begin - TQueue<T>::array)];
			}
			delete[] TQueue<T>::array;
			TQueue<T>::end = tmp + (TQueue<T>::end - TQueue<T>::begin);
			TQueue<T>::array = tmp;
			TQueue<T>::begin = TQueue<T>::array;
		}

		int beginMove = 0;
		for (int i = 0; i < priority + 1; i++)
		{
			beginMove += arrayOfPriority[i];
		}

		beginMove += (TQueue<T>::begin - TQueue<T>::array);

		int numMove = 0;
		for (int i = priority + 1; i < amountOfPriority; i++)
		{
			numMove += arrayOfPriority[i];
		}

		arrayOfPriority[priority]++;

		for (int i = (TQueue<T>::end - TQueue<T>::array); i > (TQueue<T>::end - TQueue<T>::array) - numMove; i--)
		{
			TQueue<T>::array[i] = TQueue<T>::array[i - 1];
		}
		TQueue<T>::array[beginMove] = a;
		TQueue<T>::end++;
	}

	void pop()
	{
		TQueue<T>::pop();
		int i = 0;
		for( ; arrayOfPriority[i] == 0; i++){}
		arrayOfPriority[i]--;
	}

	~TQueuePr()
	{
		delete[] arrayOfPriority;
	}

};
