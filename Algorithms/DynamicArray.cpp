// ConsoleApplication4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
template <typename T>
class DynamicArray
{

private:
	int expand = 2;
	int capacity = 5;
	int size;
	T* array;
	void Expand()
	{
		capacity = capacity * expand;
		T* temp = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = array[i];
		}
		delete[]array;
		array = temp;
	}
public:
	DynamicArray()
	{
		array = new T[capacity];
		size = 0;
	}
	~DynamicArray()
	{
		delete[]array;
		cout << "array has been deleted" << endl;
	}

	void add(T data) {
		if (size == capacity)
		{
			Expand();
		}
		array[size] = data;
		size++;

	}
	void printGivenIndex(int index)
	{
		if (index <0 || index >= size)
		{
			cout << "There's not such an element" << endl;;

		}
				cout << "Index: " << index << " Data: " << array[index] << endl;	
	}
	void swapData(int index, T data)
	{
		if (index <0 || index >= size)
		{
			cout << "There's not such an element" << endl;

		}
				array[index] = data;
		
	}
	void printArray()
	{
		if (size == 0)
		{
			cout << "there's no array" << endl;
		}
		else
			if (size > 0)
			{
				for (int i = 0; i < size; i++)
				{
					cout << "Index: " << i << " Data: " << array[i] << endl;
				}
			}
	}
	void clearArray()
	{
		size = 0;
		T* temp = new T[capacity];
		delete[]array;
		array = temp;
		cout << "array deleted" << endl;
	}

	void bubbleSort()
	{
		int i, j;
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (array[j] > array[j + 1])
					swap(array[j], array[j + 1]);
	}
};

int main()
{
	DynamicArray<int>* tablica = new DynamicArray<int>();
	clock_t t;
	t = clock();
	for (int i = 0; i < 100; i++)
	{
		int r = rand()  + 2;
		tablica->add(r);
	}
	tablica->printArray();
	tablica->bubbleSort();
	tablica->printArray();
	t = clock() - t;
	cout << ("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);

	return 0;
}
