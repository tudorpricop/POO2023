#pragma once
#include <initializer_list>

using namespace std;

class Sort
{
    int count = 500; //default value which will be changed for each object
    int list[500] = {}; //initialize all values to zero using an empty brace-enclosed initializer list

public:

    // 1. The list with the number of elements in the list, minimum value and maximum value
    Sort(int count, int min, int max);

    // 2. The list with an initialization list
    Sort(const initializer_list<int>& input);

    // 3. The list with a vector and number of elements from the vector
    Sort(int count, int v[]);

    // 4. The list with variadic parameters
    Sort(int count, ...);

    // 5. The list with a string (each number is separated from the rest of the number with a comma)
    Sort(const char* string);

    void BubbleSort(bool ascendent = false);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

