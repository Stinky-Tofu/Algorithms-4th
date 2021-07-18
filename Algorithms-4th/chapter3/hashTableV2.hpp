//
//  hashTableV2.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/7/12.
//

#ifndef hashTableV2_hpp
#define hashTableV2_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <functional>


template <typename keyType, typename valType>
class hashTableV2 {
public:
    hashTableV2(const int& mInit);
    ~hashTableV2() = default;
    hashTableV2(const hashTableV2& r) = delete;
    hashTableV2& operator=(const hashTableV2& r) = delete;
    void insert(keyType key, valType val);
    valType get(keyType key);
    void del(keyType key);
    void print();
    size_t size();
    size_t capacity();
private:
    int hash(keyType key);
    int M = 0;
    int N = 0;
    std::hash<keyType> hashcode;
    std::vector<std::map<keyType, valType>> arr;
};

void hashTableV2Test();

#endif /* hashTableV2_hpp */
