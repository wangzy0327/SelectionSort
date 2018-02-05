//
// Created by wangzy on 2018/2/5.
//

#ifndef SELECTIONSORT_MERGESORT_H
#define SELECTIONSORT_MERGESORT_H

#include <iostream>
#include "InsertionSort.h"

//将arr[l,...,mid]和arr[mid+1,...,r]两部分进行归并
template<typename T>
void __merge(T arr[], int left, int mid, int right) {
    T aux[right - left + 1];
    for (int i = left; i <= right; i++)
        aux[i - left] = arr[i];
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
        //先进行数组下标合法性的判断
        if (i > mid) {
            arr[k] = aux[j - left];
            j++;
        } else if (j > right) {
            arr[k] = aux[i - left];
            i++;
        }
            //如果i在[left,mid],并且j在[mid+1,right]中,然后进行数组合并
        else if (aux[i - left] < aux[j - left]) {
            arr[k] = aux[i - left];
            i++;
        } else {
            arr[k] = aux[j - left];
            j++;
        }
    }

}

//递归使用归并排序,对arr[l,...,r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int left, int right) {
//    if(left >= right)
//        return;
    //当拆分到非常小的片段时,使用插入排序效率高
    if (right - left >= 15) {
        insertSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    __mergeSort(arr, left, mid);
    __mergeSort(arr, mid + 1, right);
    if (arr[mid] > arr[mid + 1])
        __merge(arr, left, mid, right);
}

//自顶向下的归并排序
template<typename T>
void mergeSortUB(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

//自底向上的归并排序Bottom-to-Up
template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz) {
        for (int i = 0; i + sz < n; i += sz + sz) {
            //对arr[i...i+sz-1]和arr[i+sz...i+sz+sz-1]进行排序
            __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}

#endif //SELECTIONSORT_MERGESORT_H
