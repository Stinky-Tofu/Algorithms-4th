//
//  min_pq.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/5/3.
//

#include "min_pq.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "utils.hpp"
#include "heap_sort.hpp"

template <typename T>
void insert(std::vector<T>& arr, const T& val) {
    arr.push_back(val);
    swim(arr, arr.size() - 1);
}

template <typename T>
T delMax(std::vector<T>& arr) {
    assert(!arr.empty());
    T maxVal = arr[0];
    arr[0] = *(arr.end()-1);
    arr.erase(arr.end()-1);
    sink(arr, arr.size(), 0);
    return maxVal;
}

void minPQTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 100; ++i) {
        arr.push_back(rand() % 100);
    }
    std::vector<int> min5;
    for (int i = 0; i < arr.size(); ++i) {
        if (min5.size() < 5) {
            insert(min5, arr[i]);
            continue;
        }
        insert(min5, arr[i]);
        delMax(min5);
    }
    std::sort(arr.begin(), arr.end());
    printVec(min5);
    printVec(arr);
}
