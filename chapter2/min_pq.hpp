//
//  min_pq.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/5/3.
//

#ifndef min_pq_hpp
#define min_pq_hpp

#include <stdio.h>

#include <string>
#include <vector>

template <typename T>
void insert(std::vector<T>& arr, const T& val);

template <typename T>
T delMax(std::vector<T>& arr);

void minPQTest();

#endif /* min_pq_hpp */
