#include <iostream>
#include "Array.h"

using namespace std;

int main() {

    try
    {
        Array<int> arr(10);

        // test Add operator
        try {
            arr += 1;
            arr += 2;
            arr += 3;
            arr += 4;
        }
        catch (array_capacity& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }

        // test GetSize
        cout << "Size of array is " << arr.GetSize() << endl;


        // test GetCapacity
        cout << "Capacity of array is " << arr.GetCapacity() << endl;


        // test [] operator
        try {
            cout << "Value of array at index 2 is " << arr[2] << endl;
        }
        catch (index_range& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }

        // test Insert method
        
        try  {
        arr.Insert(2, 10);
        cout << "Value of array at index 2 after insertion is " << arr[2] << endl;
        }
        catch (index_range& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        catch (array_capacity& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }

        // test Delete method
        try {
            arr.Delete(3);
            cout << "Value of array at index 3 after deletion is " << arr[3] << endl;
        }
        catch (index_range& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }


        // test Insert method with array
        Array<int> anotherArr(10);

        try {
            anotherArr += 100;
            anotherArr += 200;
            anotherArr += 300;

            arr.Insert(2, anotherArr);
        }
        catch (array_capacity& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        catch (index_range& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        

        try {
            cout << "Value of array at index 2 after insertion of another array is " << arr[2] << endl;
        }
        catch (index_range& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }

        cout << "Array after inserting an array in it: ";
        /*for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }*/
        ArrayIterator<int> it = arr.GetBeginIterator();
        ArrayIterator<int> end = arr.GetEndIterator();

        for (; it != end; ++it)
        {
            cout << *(it.GetElement()) << " ";
        }

        cout << endl;

        cout << endl;

        // test BinarySearch method with compare function
        
        bool equal = (arr == anotherArr);
        if (equal == true) {
            cout << "The compared arrays are equal!" << endl;
        }
        else {
            cout << "The compared arrays are distinct!" << endl;
        }


        cout << endl;

        // test normal Sort method
        arr.Sort();
        cout << "Using Sort method normal:  ";
        cout << "Sorted array: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // test Sort method with compare function
        arr.Sort(compare);
        cout << "Using Sort method with compare function:  ";
        cout << "Sorted array: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        

        // test Sort method with IntComparator
        IntCompare comp;
        arr.Sort(&comp);
        cout << "Using Sort method with IntComparator:  ";
        cout << "Sorted array: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << endl;

        // test BinarySearch method normal
        int searchElem = 11;
        int index = arr.BinarySearch(searchElem);
        cout << "Using BinarySearch method normal:  ";
        if (index != -1) {
            cout << "Element " << searchElem << " found at index " << index << endl;
        }
        else {
            cout << "Element " << searchElem << " not found in array" << endl;
        }

        // test BinarySearch method with compare function
        searchElem = 300;
        index = arr.Find(searchElem, compare);
        cout << "Using BinarySearch method with compare function:  ";
        if (index != -1) {
            cout << "Element " << searchElem << " found at index " << index << endl;
        }
        else {
            cout << "Element " << searchElem << " not found in array" << endl;
        }

        // test BinarySearch method with IntComparator
        searchElem = 2;
        index = arr.Find(searchElem, &comp);
        cout << "Using BinarySearch method with IntComparator:  ";
        if (index != -1) {
            cout << "Element " << searchElem << " found at index " << index << endl;
        }
        else {
            cout << "Element " << searchElem << " not found in array" << endl;
        }

        cout << endl;

        // test Find method normal 
        searchElem = 4;
        index = arr.Find(searchElem);
        cout << "Using Find method normal:  ";
        if (index != -1) {
            cout << "Element " << searchElem << " found at index " << index << endl;
        }
        else {
            cout << "Element " << searchElem << " not found in array" << endl;
        }

        // test Find method with compare function
        searchElem = 200;
        index = arr.Find(searchElem, compare);
        cout << "Using Find method with compare function:  ";
        if (index != -1) {
            cout << "Element " << searchElem << " found at index " << index << endl;
        }
        else {
            cout << "Element " << searchElem << " not found in array" << endl;
        }

        // test Find method with IntComparator
        searchElem = 1;
        index = arr.Find(searchElem, &comp);
        cout << "Using Find method with IntComparator:  ";
        if (index != -1) {
            cout << "Element " << searchElem << " found at index " << index << endl;
        }
        else {
            cout << "Element " << searchElem << " not found in array" << endl;
        }
        
    }
    catch (capacity_value& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }

    
}