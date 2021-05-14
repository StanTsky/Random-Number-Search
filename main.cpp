/*
--------------------------------------------------------------------
* Name:       Stan Turovsky
* Class:      Advanced C++
* Files:      main.cpp
* Purpose:    Random number search
--------------------------------------------------------------------
*/

// Preprocessor directives
#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int numbers[], int size)
{
	for (int pass = 0; pass < size; pass++)
		for (int i = 0; i < size - 1; i++)
			if (numbers[i] > numbers[i + 1])
			{
				int temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
}

int linearSearch(int numbers[], int size, int key)
{
	for (int i = 0; i < size; i++)
		if (numbers[i] == key)
			return i;

	return -1;
}

int sortedSearch(int numbers[], int size, int key)
{
	// if the last number in the array is smaller than the key,
	// then the key will not be present
	if (numbers[size - 1] >= key)
		for (int i = 0; i < size; i++)
			if (numbers[i] == key)
				return i;

	return -1;
}

int binarySearch(int numbers[], int size, int key)
{
	if (numbers[0] > key || numbers[size - 1] < key) //optimization
		return -1;

	int lowIndex = 0;
	int highIndex = size - 1;

	while (lowIndex <= highIndex)
	{
		int midIndex = (lowIndex + highIndex) / 2;
		if (key == numbers[midIndex])
			return midIndex;
		else if (key < numbers[midIndex])
			highIndex = midIndex - 1;
		else
			lowIndex = midIndex + 1;
	}
	return -1;
}

// main function
int main()
{
	const int SIZE = 100;
	int numbers[SIZE];

	srand((unsigned)time(0));

	for (int i = 0; i < SIZE; i++)
		numbers[i] = rand() % 500;

	for (int i = 0; i < SIZE; i++)
		cout << numbers[i] << " ";
	cout << endl;

	cout << "\nLINEAR SEARCH TEST\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 1000;
		int index = linearSearch(numbers, SIZE, key);
		if (index == -1)
			cout << key << " not found." << endl;
		else
			cout << key << " found at index " << index << endl;
	}

	// SORT THE DATA!
	bubbleSort(numbers, SIZE);

	for (int i = 0; i < SIZE; i++)
		cout << numbers[i] << " ";
	cout << endl;

	cout << "\nSORTED SEARCH TEST\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 1000;
		int index = sortedSearch(numbers, SIZE, key);
		if (index == -1)
			cout << key << " not found." << endl;
		else
			cout << key << " found at index " << index << endl;
	}
	cout << endl;

	cout << "\nBINARY SEARCH TEST\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 1000;
		int index = binarySearch(numbers, SIZE, key);
		if (index == -1)
			cout << key << " not found." << endl;
		else
			cout << key << " found at index " << index << endl;
	}

	// Leave this stuff at the end.
	cout << endl;
	// system("pause");
	return 0;
}