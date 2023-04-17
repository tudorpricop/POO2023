#include <iostream>

float operator"" _Kelvin(unsigned long long int x)
{
    int kelvin = (int)x;
    float celsius = kelvin - 273.15f;
    return celsius;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
    int fahrenheit = (int)x;
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

int main() {

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    std::cout << a << " " << b;

    return 0;

}