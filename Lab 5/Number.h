#pragma once
#include <string>

class Number
{
private:
    char* value;
    int base;

public:
    Number(const char* value, int base);
    Number(const Number& other); // copy constructor
    Number(Number&& other) noexcept; // move constructor

    Number(int);
    Number(const char*);

    ~Number();

    void operator=(const Number& other); // copy assignment operator
    Number& operator=(Number&& other) noexcept; // move assignment operator

    void operator = (int);
    void operator = (const char*);
    void operator+= (const Number&);
    void operator-= (const Number&);
    void operator+= (int);
    void operator-= (int);

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator+(const Number& n1, int n2);
    friend Number operator+(int n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, int n2);
    friend Number operator-(int n1, const Number& n2);

    bool operator==(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator!=(const Number& other) const;
    char operator[](int index) const;

    void operator--(); // Prefix decrement
    void operator--(int); // Postfix decrement

    void Print() const;
    void SwitchBase(int newBase);
    int GetDigitsCount() const;
    int GetBase() const;

};
