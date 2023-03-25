#include "Sort.h"
#include<iostream>
#include <cstdlib>
#include <initializer_list>
#include <cstdarg>
using namespace std;

Sort::Sort(int count, int min, int max)
{
	this->count = count;

	// Providing a seed value
	srand((unsigned) time(NULL));

	for (int i = 0; i < count; i++)
	{
		// Retrieve a random number between min and max
		int random = min + (rand() % max);
		list[i] = random;
	}
}

Sort::Sort(const initializer_list<int>& input)
{
	// Calculatin and storing the size of the initializer list
	int index = 0;

	for (const auto& number : input)
	{
		list[index] = number;
		index++;
	}
	count = index;
}

Sort::Sort(int count, int v[])
{
	this->count = count;

	for (int j = 0; j < count; j++)
	{
		list[j] = v[j];
	}
}

Sort::Sort(int count, ...)
{
	this->count = count;

	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i)
	{
		list[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* string)
{
	int i = 0; // current position in string
	int j = 0; // current position in list

	// calculate maximum number of integers that can be stored
	int max_ints = sizeof(list) / sizeof(int);

	// loop through string until end is reached or maximum number of integers is reached
	while (i < strlen(string) && j < max_ints) {
		// parse next number
		int num = 0;
		while (string[i] != ',' && string[i] != '\0') {
			num = num * 10 + (string[i] - '0');
			i++;
		}

		// store number in list
		list[j] = num;
		j++;

		// skip comma
		if (string[i] == ',') {
			i++;
		}
	}
	count = j;
}

void Sort::Print()
{
	int count = Sort::GetElementsCount();
	cout << "The array has " << count << " elements: ";
	for (int i = 0; i < count; i++) {
		cout << Sort::GetElementFromIndex(i);
		if (i < count - 1) {
			cout << ", ";
		}
	}
	cout << '\n';
}

void Sort::BubbleSort(bool ascendent)
{
	int n = count;
	bool swapped = true;
	int last_swap = n - 1; // initialize the last swap position to the end of the array

	while (swapped) {
		swapped = false;
		int current_last_swap = 0; // initialize the current last swap position to 0
		for (int i = 1; i <= last_swap; i++) {
			if ((ascendent && list[i - 1] > list[i]) || (!ascendent && list[i - 1] < list[i])) {
				// swap the elements and set swapped to true
				int temp = list[i - 1];
				list[i - 1] = list[i];
				list[i] = temp;
				swapped = true;
				current_last_swap = i - 1; // update the current last swap position
			}
		}
		last_swap = current_last_swap; // update the last swap position
	}
}


void QuickSortAsc(int* list, int left, int right)
{
	int i = left, j = right;
	int pivot = list[(left + right) / 2];

	while (i <= j) {
		while (list[i] < pivot) {
			i++;
		}
		while (list[j] > pivot) {
			j--;
		}
		if (i <= j) {
			std::swap(list[i], list[j]);
			i++;
			j--;
		}
	}

	if (left < j) {
		QuickSortAsc(list, left, j);
	}
	if (i < right) {
		QuickSortAsc(list, i, right);
	}
}

void QuickSortDesc(int* list, int left, int right)
{
	int i = left, j = right;
	int pivot = list[(left + right) / 2];

	while (i <= j) {
		while (list[i] > pivot) {
			i++;
		}
		while (list[j] < pivot) {
			j--;
		}
		if (i <= j) {
			std::swap(list[i], list[j]);
			i++;
			j--;
		}
	}

	if (left < j) {
		QuickSortDesc(list, left, j);
	}
	if (i < right) {
		QuickSortDesc(list, i, right);
	}
}

void Sort::QuickSort(bool ascendent)
{
	if (ascendent) {
		QuickSortAsc(list, 0, count - 1);
	}
	else {
		QuickSortDesc(list, 0, count - 1);
	}
}

void Sort::InsertSort(bool ascendent)
{
	int i, j, key;
	for (i = 1; i < count; i++) {
		key = list[i];
		j = i - 1;
		while (j >= 0 && ((ascendent && list[j] > key) || (!ascendent && list[j] < key))) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}


int Sort::GetElementsCount()
{
	return count;
}


int Sort::GetElementFromIndex(int index)
{
	int temp = list[index];
	return temp;
}