//
//  utils.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/13.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

void splitStr(const std::string& str,
              std::vector<std::string>& result,
              const std::string& delimeters = " ");

long long systemtime();

template <typename T>
bool isSorted(const std::vector<T>& arr) {
    if (arr.size() < 2) return true;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i-1] > arr[i]) return false;
    }
    return true;
}

template <typename T>
void printVec(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << "\t";
    }
    std::cout << std::endl;
}

#endif /* utils_hpp */
