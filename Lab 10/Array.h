#pragma once

#include "ArrayIterator.h"
#include "ExeptionsList.h"
#include "Compare.h"

template<class T>
class Array {

private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:

	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray); // constructor de copiere

	T& operator[] (int index); // arunca exceptie daca index este out of range

	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator==(const Array<T>& otherArray);

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();

};

template<class T>
Array<T>::Array() {
	List = nullptr;
	Capacity = 0;
	Size = 0;
}

template<class T>
Array<T>::~Array() {
	if (List != nullptr) {
		for (int i = 0; i < Size; i++) {
			delete List[i];
		}
		delete[] List;
	}
}

template<class T>
Array<T>::Array(int capacity) {
	if (capacity < 0) {
		throw capacity_value();
	}
	List = new T * [capacity];
	for (int i = 0; i < capacity; i++) {
		List[i] = nullptr;
	}
	Capacity = capacity;
	Size = 0;
}

template<class T>
Array<T>::Array(const Array<T>& otherArray) {
	List = new T * [otherArray.Capacity];
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;

	for (int i = 0; i < Size; i++) {
		List[i] = new T(*otherArray.List[i]);
	}
	for (int i = Size; i < Capacity; i++) {
		List[i] = nullptr;
	}
}

template<class T>
T& Array<T>::operator[] (int index) {
	if (index < 0 || index >= Size) {
		throw index_range();
	}
	return *(List[index]);
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newElem) {
	if (Size == Capacity) {
		throw array_capacity();
	}

	List[Size++] = new T(newElem);
	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if (index < 0 || index > Size)
		throw index_range();

	if (Size == Capacity)
		throw array_capacity();

	for (int i = Size; i > index; i--)
		List[i] = List[i - 1];

	List[index] = new T(newElem);
	Size++;

	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if (index < 0 || index > Size)
		throw index_range();

	if (Size + otherArray.Size > Capacity)
		throw array_capacity();

	for (int i = Size + otherArray.Size - 1; i >= index + otherArray.Size; i--)
		List[i] = List[i - otherArray.Size];

	for (int i = 0; i < otherArray.Size; i++)
		List[index + i] = new T(*(otherArray.List[i]));

	Size += otherArray.Size;

	return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	if (index < 0 || index >= Size)
		throw index_range();

	delete List[index];

	for (int i = index; i < Size - 1; i++)
		List[i] = List[i + 1];

	List[Size - 1] = nullptr;
	Size--;

	return *this;
}

template<class T>
bool Array<T>::operator==(const Array<T>& otherArray) {
	if (Size != otherArray.Size) {
		return false;
	}
	for (int i = 0; i < Size; i++) {
		if (*List[i] != *otherArray.List[i]) {
			return false;
		}
	}
	return true;
}

template <class T>
void Array<T>::Sort()
{
	for (int i = 0; i < Size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < Size - i - 1; j++)
		{
			if (*List[j] > *List[j + 1])
			{
				// interschimbam elementele
				T* temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
				swapped = true;
			}
		}
		// daca nu s-a facut nicio interschimbare, array-ul e ordonat
		if (!swapped)
			break;
	}
}

template<class T>
void Array<T>::Sort(int (*compare)(const T&, const T&)) {
	int i, j;
	bool swapped;

	for (i = 0; i < Size - 1; i++) {
		swapped = false;
		for (j = 0; j < Size - i - 1; j++) {
			if (compare(*List[j], *List[j + 1]) > 0) {
				T* temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}


template <class T>
void Array<T>::Sort(Compare* comparator) {
	for (int i = 0; i < Size - 1; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (comparator->CompareElements(List[i], List[j]) > 0) {
				T* temp = List[i];
				List[i] = List[j];
				List[j] = temp;
			}
		}
	}
}

template<class T>
int Array<T>::BinarySearch(const T& elem)
{
	int left = 0;
	int right = Size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (*(List[mid]) == elem) {
			return mid;
		}
		else if (*List[mid] < elem) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	if (Size == 0) {
		return -1;
	}

	int left = 0;
	int right = Size - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (compare(elem, *List[middle]) == 0) {
			return middle;
		}
		else if (compare(elem, *List[middle]) < 0) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	if (Size == 0) {
		return -1;
	}

	int left = 0;
	int right = Size - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (comparator->CompareElements(&elem, List[middle]) == 0) {
			return middle;
		}
		else if (comparator->CompareElements(&elem, List[middle]) < 0) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return -1;
}

template<class T>
int Array<T>::Find(const T& elem) {
	for (int i = 0; i < Size; i++) {
		if (*List[i] == elem) {
			return i;
		}
	}
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&)) {
	for (int i = 0; i < Size; i++) {
		if (compare(*List[i], elem) == 0) {
			return i;
		}
	}
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, Compare* comparator) {
	for (int i = 0; i < Size; i++) {
		if (comparator->CompareElements(List[i], const_cast<T*>(&elem)) == 0) {
			return i;
		}
	}
	return -1;
}


template<class T>
int Array<T>::GetSize()
{
	return Size;
}

template<class T>
int Array<T>::GetCapacity()
{
	return Capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
	ArrayIterator<T> iter;
	iter.Current = 0;
	iter.Ptr = this->List;
	return iter;
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
	ArrayIterator<T> iter;
	iter.Current = this->Size;
	iter.Ptr = this->List;
	return iter;
}