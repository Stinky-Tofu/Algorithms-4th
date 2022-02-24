//
//  heap_sort.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/5/3.
//

#ifndef heap_sort_hpp
#define heap_sort_hpp

#include <stdio.h>
#include <vector>

template <typename T>
void swim(std::vector<T>& arr, std::size_t k) {
    while (k > 0 && arr[k] > arr[(k - 1) / 2]) {
        std::swap(arr[k], arr[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

template <typename T>
void sink(std::vector<T>& arr, std::size_t N, std::size_t k) {
    while (2 * k + 1 < N) {
        std::size_t j = 2 * k + 1;
        if (j + 1 < N && arr[j] < arr[j+1]) ++j;
        if (arr[k] >= arr[j]) break;
        std::swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void heapSort(std::vector<T>& arr);

void heapSortTest();

#endif /* heap_sort_hpp */
