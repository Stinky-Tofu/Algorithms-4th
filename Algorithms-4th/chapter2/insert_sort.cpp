//
//  insert_sort.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/11.
//

#include "insert_sort.hpp"

#include <vector>
#include <algorithm>

#include "utils.hpp"

template <typename T>
void insertSort(std::vector<T>& arr) {
    for (int rInd = 1; rInd < arr.size(); ++rInd)
        for (int lInd = rInd; lInd > 0 && arr[lInd] < arr[lInd-1]; --lInd)
            std::swap(arr[lInd], arr[lInd-1]);
}

void insertSortTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 100; ++i) {
        arr.push_back(rand() % 1000);
    }
    insertSort(arr);
    std::cout << isSorted(arr) << std::endl;
    printVec(arr);
}
