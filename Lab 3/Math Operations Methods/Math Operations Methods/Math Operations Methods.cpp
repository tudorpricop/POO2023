#include "Math.h"
#include <iostream>

int main() {
    // Example for Add(int, int) method
    std::cout << "Add(3, 5) = " << Math::Add(3, 5) << std::endl;

    // Example for Add(int, int, int) method
    std::cout << "Add(4, 6, 8) = " << Math::Add(4, 6, 8) << std::endl;

    // Example for Add(double, double) method
    std::cout << "Add(1.5, 2.5) = " << Math::Add(1.5, 2.5) << std::endl;

    // Example for Add(double, double, double) method
    std::cout << "Add(1.5, 2.5, 3.5) = " << Math::Add(1.5, 2.5, 3.5) << std::endl;

    // Example for Mul(int, int) method
    std::cout << "Mul(3, 5) = " << Math::Mul(3, 5) << std::endl;

    // Example for Mul(int, int, int) method
    std::cout << "Mul(4, 6, 8) = " << Math::Mul(4, 6, 8) << std::endl;

    // Example for Mul(double, double) method
    std::cout << "Mul(1.5, 2.5) = " << Math::Mul(1.5, 2.5) << std::endl;

    // Example for Mul(double, double, double) method
    std::cout << "Mul(1.5, 2.5, 3.5) = " << Math::Mul(1.5, 2.5, 3.5) << std::endl;

    // Example for Add(int, ...) method
    std::cout << "Add(5, 1, 2, 3, 4, 5) = " << Math::Add(5, 1, 2, 3, 4, 5) << std::endl;

    // Example for Add(const char*, const char*) method
    char* result = Math::Add("OOP, ", "tasks");
    if (result != nullptr) {
        std::cout << result << std::endl;
        delete[] result;
    }
    else {
        std::cout << "Both or one of the two given strings are nullptr." << std::endl;
    }

    return 0;
}
