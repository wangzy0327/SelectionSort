cmake_minimum_required(VERSION 3.8)
project(SelectionSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h Student.h SelectionSort.h InsertionSort.h BubbleSort.h MergeSort.h QuickSort.h)
add_executable(SelectionSort ${SOURCE_FILES})