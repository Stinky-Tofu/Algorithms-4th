//
//  quick_3_string.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/27.
//

#include "quick_3_string.hpp"

#include <vector>
#include <string>
#include <iostream>

#include "MSD.hpp"


void quick3WaySort(std::vector<std::string>& arr,
                   const int &low,
                   const int &high,
                   const int &d) {
    if (low >= high) return;

    // 三向切分
    int v = char_at(arr[low], d);
    int lt = low;
    int i = low + 1;
    int gt = high;
    while (i <= gt) {
        int t = char_at(arr[i], d);
        if (t < v) std::swap(arr[lt++], arr[i++]);
        else if (t > v) std::swap(arr[gt--], arr[i]);
        else ++i;
    }

    quick3WaySort(arr, low, lt-1, d);
    if (v != -1) quick3WaySort(arr, lt, gt, d+1);
    quick3WaySort(arr, gt+1, high, d);
}

void quick_3_string(std::vector<std::string> &arr) {
    quick3WaySort(arr, 0, (int)arr.size()-1, 0);
}

void quick_3_string_test() {
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
    quick_3_string(arr);
    for (const std::string &str: arr) {
        std::cout << str << std::endl;
    }
}

