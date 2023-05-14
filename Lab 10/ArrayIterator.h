#pragma once

template<class T>
class ArrayIterator {

public:

	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** Ptr; // pointer la pointer la obiecte de tipul T*

	ArrayIterator();
	ArrayIterator& operator++ ();
	ArrayIterator& operator-- ();
	bool operator== (ArrayIterator<T>&);
	bool operator!=(ArrayIterator<T>&);
	T* GetElement();

};

template<class T>
ArrayIterator<T>::ArrayIterator() : Current(0), Ptr(nullptr) {}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
	++Current;
	return *this;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
	--Current;
	return *this;
}

template<class T>
bool ArrayIterator<T>::operator==( ArrayIterator<T>& other)
{
	return Ptr == other.Ptr && Current == other.Current;
}


template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T>& other)
{
	return !(*this == other);
}

template<class T>
T* ArrayIterator<T>::GetElement()
{
	if (Ptr == nullptr || *Ptr == nullptr || Current < 0)
	{
		return nullptr;
	}
	return *Ptr + Current;
}