//
//  heap_sort.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/5/3.
//

#include "heap_sort.hpp"

#include <vector>

#include "utils.hpp"

template <typename T>
void heapSort(std::vector<T>& arr) {
    int N = (int)arr.size();
    for (int i = N / 2 - 1; i >= 0; --i)
        sink(arr, N, i);
    while (N > 0) {
        std::swap(arr[0], arr[N-1]);
        --N;
        sink(arr, N, 0);
    }
}


void heapSortTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 1000; ++i) {
        arr.push_back(rand() % 100);
    }
    printVec(arr);
    heapSort(arr);
    printVec(arr);
    std::cout << isSorted(arr) << std::endl;
}
