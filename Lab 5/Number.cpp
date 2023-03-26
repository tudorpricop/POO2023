#include "Number.h"
#include <iostream>
using namespace std;

Number::Number(const char* value, int base)
{

}

// copy constructor
Number::Number(const Number& other)
{
}

// move constructor
Number::Number(Number&& other) noexcept
{
	value = other.value;
	base = other.base;
	other.value = nullptr;
	other.base = 0;
}

Number::~Number()
{
}

// move assignment operator
Number& Number::operator=(Number&& other) noexcept
{
	if (this != &other) {
		delete[] value;
		value = other.value;
		base = other.base;
		other.value = nullptr;
		other.base = 0;
	}
	return *this;
}


bool Number::operator<(const Number& other) const
{
	return false;
}

bool Number::operator>(const Number& other) const
{
	return false;
}

bool Number::operator<=(const Number& other) const
{
	return false;
}

bool Number::operator>=(const Number& other) const
{
	return false;
}

bool Number::operator==(const Number& other) const
{
	return false;
}

bool Number::operator!=(const Number& other) const
{
	return false;
}

char Number::operator[](int index) const
{
	return 0;
}

Number& Number::operator--()
{
	// TODO: insert return statement here
}

Number Number::operator--(int)
{
	return Number();
}

void Number::Print() const
{
	cout << value << " (base " << base << ")" << endl;
}

void Number::SwitchBase(int newBase)
{
    // Check if the new base is within the valid range
    if (newBase < 2 || newBase > 16) {
        std::cout << "Error: invalid base specified!" << std::endl;
        return;
    }

    // Convert the current value to a decimal number
    int decimalValue = 0;
    int power = 1;
    for (int i = strlen(value) - 1; i >= 0; i--) {
        int digitValue;
        if (value[i] >= '0' && value[i] <= '9') {
            digitValue = value[i] - '0';
        }
        else if (value[i] >= 'A' && value[i] <= 'F') {
            digitValue = value[i] - 'A' + 10;
        }
        else if (value[i] >= 'a' && value[i] <= 'f') {
            digitValue = value[i] - 'a' + 10;
        }
        else {
            std::cout << "Error: invalid character in number!" << std::endl;
            return;
        }
        decimalValue += digitValue * power;
        power *= base;
    }

    // Convert the decimal value to the new base
    char buffer[32];
    int bufferIndex = 0;
    while (decimalValue > 0) {
        int remainder = decimalValue % newBase;
        char digit;
        if (remainder < 10) {
            digit = remainder + '0';
        }
        else {
            digit = remainder - 10 + 'A';
        }
        buffer[bufferIndex++] = digit;
        decimalValue /= newBase;
    }
    if (bufferIndex == 0) {
        buffer[bufferIndex++] = '0';
    }
    buffer[bufferIndex] = '\0';

    // Reverse the buffer string
    for (int i = 0, j = bufferIndex - 1; i < j; i++, j--) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    // Update the object's state
    base = newBase;
    delete[] value;
    value = new char[bufferIndex + 1];
    strcpy(value, buffer);
}

int Number::GetDigitsCount() const
{
	return 0;
}

int Number::GetBase() const
{
	return 0;
}

Number operator+(const Number& n1, const Number& n2)
{
    return Number();
}

Number operator+(const Number& n1, int n2)
{
    return Number();
}

Number operator+(int n1, const Number& n2)
{
    return Number();
}

Number operator-(const Number& n1, const Number& n2)
{
    return Number();
}

Number operator-(const Number& n1, int n2)
{
    return Number();
}

Number operator-(int n1, const Number& n2)
{
    return Number();
}
