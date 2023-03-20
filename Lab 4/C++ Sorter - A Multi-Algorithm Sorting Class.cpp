#include <iostream>
#include "Sort.h";
using namespace std;

int main()
{
	// Declaring the 5 Sort objects

	// 1. The list with the number of elements in the list, minimum value and maximum value
	Sort list1(15, 1, 500);

	// 2. The list with an initialization list
	Sort list2({5, 10, 3, 5, 1});

	// 3. The list with a vector and number of elements from the vector
    const int numberOfElements = 8;
	int testVector[numberOfElements] = {9, 3, 16, 100, 9, 35, 69, 10};

	Sort list3(numberOfElements, testVector);

	// 4. The list with variadic parameters
	Sort list4(6, 52, 22, 9, 16, 22, 99);

	// 5. The list with a string (each number is separated from the rest of the number with a comma)
	Sort list5("5,19,2,10,5");


	/// Print the objects to be sure that the constructors are called corectly
	cout << "The arrays before being sorted: \n";
	list1.Print();
	list2.Print();
	list3.Print();
	list4.Print();
	list5.Print();

	/// Sort each array
	cout << "\nCalling each sort method on the arrays... \n";

	list1.BubbleSort(true); // ascending
	list2.InsertSort(true); // ascending
	list3.QuickSort(true);  // ascending
	list4.BubbleSort();  // descending
	list5.InsertSort();  // descending

	// Print each array sorted
	cout << "\nPrinting each array sorted: \n";

	list1.Print();
	list2.Print();
	list3.Print();
	list4.Print();
	list5.Print();

	return 0;
}

