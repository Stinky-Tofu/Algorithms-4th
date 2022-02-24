//
//  quick_sort.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/18.
//

#include "quick_sort.hpp"

#include <vector>
#include <iostream>
#include <random>

#include "utils/utils.hpp"

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T& v = arr[low];
    int i = low;
    int j = high + 1;
    while (true) {
        while (arr[++i] < v && i != high);
        while (arr[--j] > v && j != low);
        if (i >= j) break;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[j], v);
    return j;
}

//  三向切分的实现
template <typename T>
void quick3WaySort(std::vector<T>& arr, int low, int high) {
    if (low >= high) return;

    // partition part
    T v = arr[low]; //此处切勿使用引用
    int lt = low;
    int i = low + 1;
    int gt = high;
    while (i <= gt) {
        if (arr[i] < v) std::swap(arr[lt++], arr[i++]);
        else if (arr[i] > v) std::swap(arr[gt--], arr[i]);
        else ++i;
    }
    // partition part

    quick3WaySort(arr, low, lt-1);
    quick3WaySort(arr, gt+1, high);
}

template <typename T>
void sort(std::vector<T>& arr, int low, int high) {
    if (low >= high) return;
    int s = partition(arr, low, high);
    sort(arr, low, s-1);
    sort(arr, s+1, high);
}

template <typename T>
void quickSort(std::vector<T>& arr, SORTTYPE sortType) {
    std::shuffle(arr.begin(), arr.end(),
                 std::default_random_engine(std::random_device()()));
    switch (sortType) {
        case SORTTYPE::BASIC:
            sort(arr, 0, (int)arr.size()-1);
            break;
        case SORTTYPE::QUICK3WAY:
            quick3WaySort(arr, 0, (int)arr.size()-1);
            break;
        default:
            break;
    }
}

void quickSortTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 1000; ++i) {
        arr.push_back(rand() % 1000);
    }
    printVec(arr);
    quickSort(arr, SORTTYPE::QUICK3WAY);
    printVec(arr);
    std::cout << isSorted(arr) << std::endl;
}

