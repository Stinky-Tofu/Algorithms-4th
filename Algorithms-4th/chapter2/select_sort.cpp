//
//  select_sort.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/10.
//

#include "select_sort.hpp"

#include <cstdlib>
#include <vector>
#include <algorithm>

#include "utils.hpp"

template <typename T>
void selectSort(std::vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int minInd = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minInd]) minInd = j;
        }
        std::swap(arr[i], arr[minInd]);
    }
}

void selectSortTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 100; ++i) {
        arr.push_back(rand() % 1000);
    }
    selectSort(arr);
    std::cout << isSorted(arr) << std::endl;
    printVec(arr);
}
