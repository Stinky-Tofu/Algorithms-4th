//
//  shell_sort.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/11.
//

#include "shell_sort.hpp"
#include <vector>
#include <iostream>

#include "utils.hpp"

template <typename T>
void shellSort(std::vector<T>& arr) {
    int h = 1;
    while (h < arr.size() / 3) {
        h = 3 * h + 1;
    }
    
    while (h >= 1) {
        for (int rInd = h; rInd < arr.size(); ++rInd) {
            for (int lInd = rInd; lInd >= h && arr[lInd] < arr[lInd - h]; lInd -= h) {
                std::swap(arr[lInd], arr[lInd - h]);
            }
        }
        h /= 3;
    }
}


void shellSortTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 100; ++i) {
        arr.push_back(rand() % 1000);
    }
    shellSort(arr);
    std::cout << isSorted(arr) << std::endl;
    printVec(arr);
}
