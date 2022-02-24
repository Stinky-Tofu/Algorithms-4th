//
//  merge_sort.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/11.
//

#include "merge_sort.hpp"

#include <vector>
#include <cstdlib>

#include "utils/utils.hpp"

template <typename T>
void merge(std::vector<T>& arr, int low, int mid, int high) {
    std::vector<T> aux_arr;
    for (int i = low; i <= high; ++i)
        aux_arr.push_back(arr[i]);
    int aux_low = low - low;
    int aux_mid = mid - low;
    int aux_high = high - low;
    int aux_i = aux_low;
    int aux_j = aux_mid + 1;
    
    for (int i = low; i <= high; ++i) {
        if (aux_i > aux_mid) {
            arr[i] = aux_arr[aux_j++];
        }else if (aux_j > aux_high) {
            arr[i] = aux_arr[aux_i++];
        }else if (aux_arr[aux_j] < aux_arr[aux_i]){
            arr[i] =  aux_arr[aux_j++];
        }else {
            arr[i] = aux_arr[aux_i++];
        }
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr) {
    int low = 0;
    int high = (int)arr.size() - 1;
    sort(arr, low, high);
}

template <typename T>
void sort(std::vector<T>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    sort(arr, low, mid);
    sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSortTest() {
    std::vector<int> arr{};
    for (int i = 0; i < 1000; ++i) {
        arr.push_back(rand() % 1000);
    }
    mergeSort(arr);
    std::cout << isSorted(arr) << std::endl;
    printVec(arr);
}
