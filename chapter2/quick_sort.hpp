//
//  quick_sort.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/4/18.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <stdio.h>
#include <vector>

enum SORTTYPE {
    BASIC = 0,
    QUICK3WAY
};

template <typename T>
int partition(std::vector<T>& arr, int low, int high);

template <typename T>
void quick3WaySort(std::vector<T>& arr, int low, int high);

template <typename T>
void sort(std::vector<T>& arr, int low, int high);

template <typename T>
void quickSort(std::vector<T>& arr, SORTTYPE sortType);

void quickSortTest();

#endif /* quick_sort_hpp */
