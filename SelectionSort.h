//
// Created by wangzy on 2018/2/2.
//

#ifndef SELECTIONSORT_SELECTIONSORT_H
#define SELECTIONSORT_SELECTIONSORT_H

#include <iostream>
#include <string>

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        //寻找[i,n)区间中的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        //swap 在iostream中  algorithm中也有
        swap(arr[i], arr[minIndex]);
    }
}

#endif //SELECTIONSORT_SELECTIONSORT_H
