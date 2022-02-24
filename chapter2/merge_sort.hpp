//
//  merge_sort.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/11.
//

#ifndef merge_sort_hpp
#define merge_sort_hpp

#include <stdio.h>
#include <vector>

template <typename T>
void mergeSort(std::vector<T>& arr);

template <typename T>
void sort(std::vector<T>& arr, int low, int high);

template <typename T>
void merge(std::vector<T>& arr, int low, int mid, int high);

void mergeSortTest();

#endif /* merge_sort_hpp */
