//
// Created by wangzy on 2018/2/2.
//

#ifndef SELECTIONSORT_BUBBLESORT_H
#define SELECTIONSORT_BUBBLESORT_H

#include <iostream>

template<typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

#endif //SELECTIONSORT_BUBBLESORT_H
