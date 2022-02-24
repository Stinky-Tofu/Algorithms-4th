//
//  hashTableV2.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/7/12.
//

#include "hashTableV2.hpp"

#include <iostream>
#include <vector>
#include <map>


template <typename keyType, typename valType>
hashTableV2<keyType, valType>::hashTableV2(const int& mInit)
    :M(mInit), N(0){
    for (int i = 0; i < M; ++i)
        arr.push_back(std::map<keyType, valType>());
}

template <typename keyType, typename valType>
int hashTableV2<keyType, valType>::hash(keyType key) {
    return hashcode(key) % M;
}

template <typename keyType, typename valType>
void hashTableV2<keyType, valType>::insert(keyType key, valType val) {
    size_t x = hash(key);
    arr[x][key] = val;
    ++N;
}

template <typename keyType, typename valType>
valType hashTableV2<keyType, valType>::get(keyType key) {
    size_t x = hash(key);
    return arr[x].at(key);
}

template <typename keyType, typename valType>
void hashTableV2<keyType, valType>::del(keyType key) {
    size_t x = hash(key);
    arr[x].erase(key);
    --N;
}

template <typename keyType, typename valType>
void hashTableV2<keyType, valType>::print() {
    for (std::map<keyType, valType>& bst: arr) {
        for (auto iter = bst.begin(); iter != bst.end(); ++iter) {
            std::cout << "key: " << iter->first << "\tval: " << iter->second
            << "\tbst size: " << bst.size() << std::endl;
        }
    }
}

template <typename keyType, typename valType>
size_t hashTableV2<keyType, valType>::size() {
    return N;
}

template <typename keyType, typename valType>
size_t hashTableV2<keyType, valType>::capacity() {
    return M;
}

void hashTableV2Test() {
    hashTableV2<int, int> hashTableV2Obj(50);
    std::cout << "**********insert**********" << std::endl;
    for (int i = 0; i < 100; ++i) {
        hashTableV2Obj.insert(i, i + 100);
        std::cout << "size:\t" << hashTableV2Obj.size() << "\tcapacity:\t" << hashTableV2Obj.capacity() << std::endl;
    }
    hashTableV2Obj.print();
    std::cout << "**********get**********" << std::endl;
    for (int i = 0; i < 100; ++i) {
        std::cout << hashTableV2Obj.get(i) << std::endl;
        hashTableV2Obj.get(i);
    }
    std::cout << "**********delete**********" << std::endl;
    for (int i = 0; i < 40; ++i) {
        hashTableV2Obj.del(i);
        std::cout << "size:\t" << hashTableV2Obj.size() << "\tcapacity:\t" << hashTableV2Obj.capacity() << std::endl;
    }
    hashTableV2Obj.print();
    for (int i = 40; i < 100; ++i) {
        hashTableV2Obj.del(i);
        std::cout << "size:\t" << hashTableV2Obj.size() << "\tcapacity:\t" << hashTableV2Obj.capacity() << std::endl;
    }
    hashTableV2Obj.print();
}
