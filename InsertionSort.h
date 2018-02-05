//
// Created by wangzy on 2018/2/2.
//

#ifndef SELECTIONSORT_INSERTIONSORT_H
#define SELECTIONSORT_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        //判断插入位置
        //循环条件:当当前位置比前面有序序列 当前位置小的话 循环继续
        //而对比选择排序来说,选择排序每次需要遍历到最后一个元素  理论上来说 插入排序更快
        //插入排序需要优化 swap交换需要3次赋值
        T e = arr[i];
        int j;  //j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}

//对arr[left,...,right]范围的数组进行插入排序
template<typename T>
void insertSort(T arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        //判断插入位置
        //循环条件:当当前位置比前面有序序列 当前位置小的话 循环继续
        //而对比选择排序来说,选择排序每次需要遍历到最后一个元素  理论上来说 插入排序更快
        //插入排序需要优化 swap交换需要3次赋值
        T e = arr[i];
        int j;  //j保存元素e应该插入的位置
        for (j = i; j > left && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}

#endif //SELECTIONSORT_INSERTIONSORT_H
