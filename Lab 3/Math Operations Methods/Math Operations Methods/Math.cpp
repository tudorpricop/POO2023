#include "Math.h"
#include <cstdarg>
#include <cstring>
#pragma warning(disable:4996)

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

double Math::Add(double a, double b) {
    return a + b;
}

double Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

double Math::Mul(double a, double b) {
    return a * b;
}

double Math::Mul(double a, double b, double c) {
    return a * b * c;
}

int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* a, const char* b) {
    if (!a || !b) {
        return nullptr;
    }

    const size_t lenA = strlen(a);
    const size_t lenB = strlen(b);
    char* result = new char[lenA + lenB + 1];
    strcpy(result, a);
    strcat(result, b);
    return result;
}
