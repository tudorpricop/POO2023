#include "Number.h"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

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

Number::Number(int n) {
    int tmp = n;
    int count = 0;
    while (tmp > 0) {
        tmp /= 10;
        count++;
    }
    this->value = new char[count + 1];
    this->value[count] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        this->value[i] = (n % 10) + '0';
        n /= 10;
    }
    this->base = 10;
}

Number::Number(const char* s) {
    int len = strlen(s);
    this->value = new char[len + 1];
    this->value[len] = '\0';
    for (int i = 0; i < len; i++) {
        this->value[i] = s[i];
    }
    this->base = 10;
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

// copy assignment operator
void Number::operator = (const Number& copy)
{
    if (this->value != nullptr)
    {
        delete[] this->value;
        this->value = nullptr;
    }
    this->value = new char[strlen(copy.value) + 1];
    memcpy(this->value, copy.value, strlen(copy.value) + 1);
    this->base = copy.base;
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

void Number::operator = (int num)
{
    int temp = num;
    int digitCount = 0;

    // Count the number of digits in the integer
    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }

    // Allocate memory for the character array
    delete[] value;
    value = new char[digitCount + 1];

    // Convert the integer to a character array
    temp = num;
    for (int i = digitCount - 1; i >= 0; i--) {
        value[i] = '0' + temp % 10;
        temp /= 10;
    }

    // Add a null terminator at the end of the character array
    value[digitCount] = '\0';

    base = 10;
}

void Number:: operator = (const char* string)
{
    delete[] value;
    value = new char[strlen(string) + 1];
    memcpy(value, string, strlen(string) + 1);
    base = 10;
}

void Number::operator+=(const Number& obj)
{
    Number aux = (*this) + obj;
    *this = aux;
}

void Number::operator-=(const Number& obj)
{
    Number aux = (*this) - obj;
    *this = aux;
}

void Number::operator+=(int x)
{
    *this = (*this) + x;
}

void Number::operator-=(int x)
{
    *this = (*this) - x;
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

bool Number::operator==(const Number& other) const
{
    Number aux2 = other, aux1 = (*this);
    aux1.SwitchBase(10);
    aux2.SwitchBase(10);

    return (strcmp(aux1.value, aux2.value) == 0);

}

bool Number::operator<(const Number& other) const
{
    // If bases are different, switch to the larger base first
    if (base != other.base)
    {
        int largerBase = (base > other.base) ? base : other.base;
        Number tmp1 = *this, tmp2 = other;
        tmp1.SwitchBase(largerBase);
        tmp2.SwitchBase(largerBase);
        return (tmp1 < tmp2);
    }

    // Compare the numbers digit by digit
    int n = strlen(value), m = strlen(other.value);
    if (n < m)
        return true;
    if (n > m)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (value[i] < other.value[i])
            return true;
        if (value[i] > other.value[i])
            return false;
    }
    return false; // the numbers are equal
}


bool Number::operator>(const Number& other) const
{
    // If bases are different, switch to the larger base first
    if (base != other.base)
    {
        int largerBase = (base > other.base) ? base : other.base;
        Number tmp1 = *this, tmp2 = other;
        tmp1.SwitchBase(largerBase);
        tmp2.SwitchBase(largerBase);
        return (tmp1 > tmp2);
    }

    // Compare the numbers digit by digit
    int n = strlen(value), m = strlen(other.value);
    if (n > m)
        return true;
    if (n < m)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (value[i] > other.value[i])
            return true;
        if (value[i] < other.value[i])
            return false;
    }
    return false; // the numbers are equal
}

bool Number::operator<=(const Number& other) const
{
    return (*this < other) || (*this == other);
}

bool Number::operator>=(const Number& other) const
{
    return (*this > other) || (*this == other);
}

bool Number::operator!=(const Number& other) const
{
    Number aux2 = other, aux1 = (*this);
    aux1.SwitchBase(10);
    aux2.SwitchBase(10);

    if (strlen(aux2.value) != strlen(aux1.value)) {
        return true;
    }

    for (int i = 0; i < strlen(aux2.value); i++) {
        if (aux1[i] != aux2[i]) {
            return true;
        }
    }

    return false;
}

char Number::operator[](int index) const
{
    if (index >= strlen(value)) {
        cout << "Error: invalid position in the number" << std::endl;
        exit(0);
    }

    return value[index];
}

void Number::operator--()
{
    if (value == nullptr || strlen(value) == 0)
    {
        cout << "Error: invalid -- on current number!" << std::endl;
        exit(0);
    }

    // Remove the most significant digit
    char* newValue = new char[strlen(value)];
    strcpy(newValue, value + 1);
    delete[] value;
    value = newValue;
    newValue = nullptr;
}

void Number::operator--(int)
{
    int len = strlen(value);

    if (len == 1 && value[0] == '0')
    {
        cout << "Error: invalid -- on current number!" << std::endl;
        exit(0);
    }

    char* newValue = new char[len];
    strncpy(newValue, value, len - 1); // copy all but last digit to new array
    newValue[len - 1] = '\0'; // add null terminator
    delete[] value; // deallocate old value
    value = newValue; // assign new value to member variable
    newValue = nullptr;
}

void Number::Print() const
{
	cout << value << " (base " << base << ")" << endl;
}

void Number::SwitchBase(int newBase)
{
    // Check if the new base is within the valid range
    if (newBase < 2 || newBase > 16) {
        cout << "Error: invalid base specified!" << std::endl;
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