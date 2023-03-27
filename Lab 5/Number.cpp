#include "Number.h"
#include <iostream>
#include <cstring>
using namespace std;

// aux function 
int ConvertToBase10(const char* value) {
    int result = 0;
    int power = 1;
    int len = strlen(value);
    for (int i = len - 1; i >= 0; i--) {
        result += ((int)value[i] - '0') * power;
        power *= 10;
    }
    return result;
}


Number::Number(const char* value, int base)
{
    // Allocate memory for the value string
    size_t len = strlen(value);
    this->value = new char[len + 1];

    strcpy(this->value,value);

    // Set the base member to the input base value
    this->base = base;
}

// copy constructor
Number::Number(const Number& other)
{
    // Allocate memory for the value string
    size_t len = strlen(other.value);
    this->value = new char[len + 1];

    strcpy(this->value, other.value);

    this->base = other.base;
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
        delete[] value;
        value = nullptr;
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

Number operator+(const Number& n1, const Number& n2)
{
    // make copy of our numbers
    Number c1 = n1;
    Number c2 = n2;

    int newBase = max(c1.base, c2.base);

    c1.SwitchBase(10);
    c2.SwitchBase(10);

    int sum = ConvertToBase10(c1.value) + ConvertToBase10(c2.value);

    int nrDigits = 0;
    int auxSum = sum;

    while (auxSum)
    {
        auxSum /= 10;
        nrDigits++;
    }


    // Allocate memory for the character array
    char* str = new char[nrDigits + 1];

    // Convert each digit to its ASCII character representation
    for (int i = nrDigits - 1; i >= 0; i--) {
        str[i] = sum % 10 + '0';
        sum /= 10;
    }

    // Add a null terminator to the end of the character array
    str[nrDigits] = '\0';

    Number t3(str, 10);
    t3.SwitchBase(newBase);

    delete[] str; // deallocate the output array when done

    return t3;
}

Number operator+(const Number& n1, int n2)
{
    // make copy of our numbers
    Number c1 = n1;

    int newBase = max(c1.base, 10);

    c1.SwitchBase(10);

    int sum = ConvertToBase10(c1.value) + n2;

    int nrDigits = 0;
    int auxSum = sum;

    while (auxSum)
    {
        auxSum /= 10;
        nrDigits++;
    }

    // Allocate memory for the character array
    char* str = new char[nrDigits + 1];

    // Convert each digit to its ASCII character representation
    for (int i = nrDigits - 1; i >= 0; i--) {
        str[i] = sum % 10 + '0';
        sum /= 10;
    }

    // Add a null terminator to the end of the character array
    str[nrDigits] = '\0';

    Number t3(str, 10);
    t3.SwitchBase(newBase);

    delete[] str; // deallocate the output array when done

    return t3;
}

Number operator+(int n1, const Number& n2)
{
    // make copy of our numbers
    Number c1 = n2;

    int newBase = max(c1.base, 10);

    c1.SwitchBase(10);

    int sum = ConvertToBase10(c1.value) + n1;

    int nrDigits = 0;
    int auxSum = sum;

    while (auxSum)
    {
        auxSum /= 10;
        nrDigits++;
    }

    // Allocate memory for the character array
    char* str = new char[nrDigits + 1];

    // Convert each digit to its ASCII character representation
    for (int i = nrDigits - 1; i >= 0; i--) {
        str[i] = sum % 10 + '0';
        sum /= 10;
    }

    // Add a null terminator to the end of the character array
    str[nrDigits] = '\0';

    Number t3(str, 10);
    t3.SwitchBase(newBase);

    delete[] str; // deallocate the output array when done

    return t3;
}

Number operator-(const Number& n1, const Number& n2)
{
    // make copy of our numbers
    Number c1 = n1;
    Number c2 = n2;

    int newBase = max(c1.base, c2.base);

    c1.SwitchBase(10);
    c2.SwitchBase(10);

    int dif = ConvertToBase10(c1.value) - ConvertToBase10(c2.value);

    int nrDigits = 0;
    int auxDif = dif;

    while (auxDif)
    {
        auxDif /= 10;
        nrDigits++;
    }

    // Allocate memory for the character array
    char* str = new char[nrDigits + 1];

    // Convert each digit to its ASCII character representation
    for (int i = nrDigits - 1; i >= 0; i--) {
        str[i] = dif % 10 + '0';
        dif /= 10;
    }

    // Add a null terminator to the end of the character array
    str[nrDigits] = '\0';

    Number t3(str, 10);
    t3.SwitchBase(newBase);

    delete[] str; // deallocate the output array when done

    return t3;
}

Number operator-(const Number& n1, int n2)
{
    // make copy of our numbers
    Number c1 = n1;

    int newBase = max(c1.base, 10);

    c1.SwitchBase(10);

    int dif = ConvertToBase10(c1.value) - n2;

    int nrDigits = 0;
    int auxDif = dif;

    while (auxDif)
    {
        auxDif /= 10;
        nrDigits++;
    }

    // Allocate memory for the character array
    char* str = new char[nrDigits + 1];

    // Convert each digit to its ASCII character representation
    for (int i = nrDigits - 1; i >= 0; i--) {
        str[i] = dif % 10 + '0';
        dif /= 10;
    }

    // Add a null terminator to the end of the character array
    str[nrDigits] = '\0';

    Number t3(str, 10);
    t3.SwitchBase(newBase);

    delete[] str; // deallocate the output array when done

    return t3;
}

Number operator-(int n1, const Number& n2)
{
    // make copy of our numberss
    Number c2 = n2;

    int newBase = max(10, c2.base);

    c2.SwitchBase(10);

    int dif = n1 - ConvertToBase10(c2.value);

    int nrDigits = 0;
    int auxDif = dif;

    while (auxDif)
    {
        auxDif /= 10;
        nrDigits++;
    }

    // Allocate memory for the character array
    char* str = new char[nrDigits + 1];

    // Convert each digit to its ASCII character representation
    for (int i = nrDigits - 1; i >= 0; i--) {
        str[i] = dif % 10 + '0';
        dif /= 10;
    }

    // Add a null terminator to the end of the character array
    str[nrDigits] = '\0';

    Number t3(str, 10);
    t3.SwitchBase(newBase);

    delete[] str; // deallocate the output array when done

    return t3;
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
        exit (0);
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
    return strlen(value);
}

int Number::GetBase() const
{
    return base;
}