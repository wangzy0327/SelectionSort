#include <iostream>
#include <string>
//#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "Student.h"
#include "BubbleSort.h"
#include "MergeSort.h"

using namespace std;


//    int a[10] = {2,3,1,4,10,5,7,8,9,6};
//    selectionSort(a,10);
//    for(int i = 0;i < 10;i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
//
//    //浮点数
//    float b[10] = {2.4,3.4,1.4,4.4,10.4,5.4,7.4,8.4,9.4,6.4};
//    selectionSort(b,10);
//    for(int i = 0;i < 10;i++)
//        cout<<b[i]<<" ";
//    cout<<endl;
//
//
//    //字符串
//    string c[10] = {"A","B","D","Z","C","F","H","U","P","I"};
//    selectionSort(c,10);
//    for(int i = 0;i < 10;i++)
//        cout<<c[i]<<" ";
//    cout<<endl;
//
//    //Student
//    Student d[4] = {{"D",100},{"B",95},{"C",90},{"A",95}};
//    selectionSort(d,4);
//    for(int i = 0;i < 4;i++)
//        cout<<d[i];
//    cout<<endl;
int main() {
    int n = 50000;
//    int *arr = SortTestHelper::generateRandomArray(n,0,n);
//    int *arr2 = So rtTestHelper::copyIntArray(arr,n);
    //只有两百个元素不在他本来应该在的位置
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);
//    selectionSort(arr,n);
    //将打印提炼为一个函数
//    SortTestHelper::printArray(arr,n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);

    //释放内存
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}