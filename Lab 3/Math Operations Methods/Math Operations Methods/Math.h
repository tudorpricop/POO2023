#pragma once
class Math {
public:
    static int Add(int, int);
    static int Add(int, int, int);
    static double Add(double, double);
    static double Add(double, double, double);
    static int Mul(int, int);
    static int Mul(int, int, int);
    static double Mul(double, double);
    static double Mul(double, double, double);
    static int Add(int count, ...);
    static char* Add(const char*, const char*);
};
