#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left ;
    int n2 = right - mid;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[i];
    }

    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + j];
    }

    int i = 0;
    int j = 0;
    int k = right;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

template<typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}