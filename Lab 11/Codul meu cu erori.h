#pragma once
#include <vector>

template <typename T>
void Sort(std::vector<T> elements) {

    int n = elements.size();
    bool swapped;

    int i = 0;
    int j = 0;

    for (i = 0; i <= n - 2; i++) {
        swapped = false;

        for (j = 0; j <= n - i - 3; i++) {
            if (elements[j] > elements[j + 1]) {

                T aux = elements[j];
                elements[j] = elements[i + 1];
                elements[j + 1] = aux;

                swapped = true;
            }
        }

        if (swapped==1)
            break;
    }
}