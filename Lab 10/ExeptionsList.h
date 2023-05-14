#pragma once
#include <exception>

class capacity_value : public std::exception{
public:
	virtual const char* what() const throw()
	{
		return "Capacity cannot be negative.";
	}
};

class index_range : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Index out of range.";
	}
};

class array_capacity : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Array capacity exceeded.";
	}
};
