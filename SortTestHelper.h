//
// Created by wangzy on 2018/2/1.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <iomanip>
//#include <ctime>
using namespace std;

namespace SortTestHelper {
    //生成有n个元素的随机数组,每个元素的随机范围为[rangeL,rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];
        //设置随机种子为time
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    //创建一个近乎有序的数组
    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        //设置随机种子
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        //判断是否排序
        assert(isSorted(arr, n));
        cout << sortName << " : " << setiosflags(ios::fixed) << setprecision(5)
             << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        return;
    }

    //拷贝整型数组
    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        //std中的copy
        copy(a, a + n, arr);
        return arr;
    }
}

#endif //SELECTIONSORT_SORTTESTHELPER_H
