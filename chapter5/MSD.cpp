//
//  MSD.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/23.
//

#include "MSD.hpp"

#include <vector>
#include <string>
#include <iostream>

static const int R = 256;
static const int M = 3;

void insert_sort(std::vector<std::string> &arr,
                 const int &low,
                 const int &high,
                 const int &d) {
    if (low >= high)
        return;
    for (int i = low + 1; i <= high; ++i) {
        for (int j = i; j > low && arr[j] < arr[j-1]; --j) {
            std::swap(arr[j], arr[j-1]);
        }
    }
}

void MSD_sort(std::vector<std::string> &arr) {
    sort(arr, 0, (int)arr.size()-1, 0);
}

int char_at(const std::string &str, const int &d) {
    return ((str.size() <= d) ? -1 : int(str[d]));
}

void sort(std::vector<std::string> &arr,
          const int &low,
          const int &high,
          const int &d) {
    if (low + M >= high) {
        insert_sort(arr, low, high, d);
        return;
    }
    std::vector<int> count(R + 2);
    std::vector<std::string> aux(high - low + 1);
    for (int i = low; i <= high; ++i) {
        count[char_at(arr[i], d) + 2] += 1;
    }
    for (int i = 0; i < count.size() - 1; ++i) {
        count[i + 1] = count[i] + count[i + 1];
    }
    for (int i = low; i <= high; ++i) {
        aux[count[char_at(arr[i], d) + 1]++] = arr[i];
    }
    for (int i = 0; i < aux.size(); ++i) {
        arr[low + i] = aux[i];
    }
    for (int i = 0; i < R; ++i) {
        sort(arr, low + count[i], low + count[i + 1] - 1, d + 1);
    }
}


void MSD_test() {
    std::vector<std::string> arr = {
        "she",
        "sells",
        "seashells",
        "by",
        "the",
        "sea",
        "shore",
        "the",
        "shells",
        "she",
        "sells",
        "are",
        "surely",
        "seashells"
    };
    MSD_sort(arr);
    for (const std::string &str: arr) {
        std::cout << str << std::endl;
    }
}
