#include <iostream>
#include "MergeSort.h"
#include <cassert>

int main() {

    // Test 1: vector de numere pozitive
    std::vector<int> numbers = { 3, 2, 8, 1, 9 };
    mergeSort(numbers, 0, numbers.size() - 1);
    assert(numbers == std::vector<int>({ 1, 2, 3, 8, 9 }));

    // Test 2: vector de caractere
    std::vector<char> characters = { 'd', 'b', 'a', 'c' };
    mergeSort(characters, 0, characters.size() - 1);
    assert(characters == std::vector<char>({ 'a', 'b', 'c', 'd' }));

    // Test 3: vector gol
    std::vector<int> emptyVec = {};
    mergeSort(emptyVec, 0, emptyVec.size() - 1);
    assert(emptyVec.empty());

    // Test 4: vector cu un singur element
    std::vector<int> singleElementVec = { 60 };
    mergeSort(singleElementVec, 0, singleElementVec.size() - 1);
    assert(singleElementVec == std::vector<int>({ 60 }));

    // Test 5: vector cu un 2 elemente ordonate deja
    std::vector<int> numbers2 = { 1, 3 };
    mergeSort(numbers2, 0, numbers2.size() - 1);
    assert(numbers2 == std::vector<int>({1, 3}));

    // Test 6: vector cu un 2 elemente ordonate deja dar descrescator
    std::vector<int> numbers3 = { 5, 1 };
    mergeSort(numbers3, 0, numbers3.size() - 1);
    assert(numbers3 == std::vector<int>({ 1, 5 }));

    // Test 7: vector cu un sir de numere palindrom si duplicate
    std::vector<int> numbers4 = { 3, 2, 1, 2, 3 };
    mergeSort(numbers4, 0, numbers4.size() - 1);
    assert(numbers4 == std::vector<int>({ 1, 2, 2, 3, 3 }));

    // Test 8: vector cu un sir de numere negative
    std::vector<int> numbers5 = { -5, 2, -1, 0, -3 };
    mergeSort(numbers5, 0, numbers5.size() - 1);
    assert(numbers5 == std::vector<int>({ -5, -3, -1, 0, 2 }));

    // Test 9: vector cu un sir de numere negative
    std::vector<int> numbers6 = { 1, 2, 1, 2, 1, 2 };
    mergeSort(numbers6, 0, numbers6.size() - 1);
    assert(numbers6 == std::vector<int>({ 1, 1, 1, 2, 2, 2 }));

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}