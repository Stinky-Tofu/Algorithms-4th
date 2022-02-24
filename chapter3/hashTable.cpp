//
//  hashTable.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/7/11.
//

#include "hashTable.hpp"

#include <functional>
#include <string>
#include <iostream>
#include <memory>

template <typename keyType, typename valType>
hashTable<keyType, valType>::hashTable(const int& mInit)
    :M(mInit), N(0){
    for (int i = 0; i < M; ++i)
        arr.push_back(nullptr);
}

template <typename keyType, typename valType>
hashTable<keyType, valType>::~hashTable() {
    clear();
}

template <typename keyType, typename valType>
int hashTable<keyType, valType>::hash(keyType key) {
    return hashcode(key) % M;
}

template <typename keyType, typename valType>
void hashTable<keyType, valType>::insert(keyType key, valType val) {
    if (2 * N >= M)
        resize(2 * M);
    size_t x = hash(key);
    while (true) {
        if (!arr[x]) {
            arr[x] = new std::pair<keyType, valType>(key, val);
            ++N;
            return;
        } else if (arr[x]->first == key){
            arr[x]->second = val;
            return;
        } else {
            x = (x + 1) % M;
        }
    }
}

template <typename keyType, typename valType>
std::pair<keyType, valType>* hashTable<keyType, valType>::get(keyType key) {
    size_t x = hash(key);
    while (true) {
        if (!arr[x]) {
            return nullptr;
        } else if (arr[x]->first == key){
            return arr[x];
        } else {
            x = (x + 1) % M;
        }
    }
}

template <typename keyType, typename valType>
void hashTable<keyType, valType>::del(keyType key) {
    size_t x = hash(key);
    while (true) {
        if (!arr[x]) {
            return;
        } else if (arr[x]->first == key){
            delete arr[x];
            arr[x] = nullptr;
            --N;
            break;
        } else {
            x = (x + 1) % M;
        }
    }
    x = (x + 1) % M;
    while (arr[x]) {
        std::pair<keyType, valType> preserve = *arr[x];
        delete arr[x];
        arr[x] = nullptr;
        --N;
        insert(preserve.first, preserve.second);
        x = (x + 1) % M;
    }
    if (N > 0 && (N <= M / 8)) resize(M / 2);
}

template <typename keyType, typename valType>
void hashTable<keyType, valType>::resize(int cap) {
    std::vector<std::pair<keyType, valType>> preserveArr;
    for (std::pair<keyType, valType>* ele: arr) {
        if (ele) preserveArr.push_back(*ele);
    }
    clear();
    for (int i = 0; i < cap; ++i) {
        arr.push_back(nullptr);
    }
    M = cap;
    for (std::pair<keyType, valType> ele: preserveArr) {
        insert(ele.first, ele.second);
    }
}

template <typename keyType, typename valType>
void hashTable<keyType, valType>::print() {
    for (std::pair<keyType, valType>* ele: arr) {
        if (ele) std::cout << "(" << ele->first << ", " << ele->second << ")" << std::endl;
    }
}

template <typename keyType, typename valType>
void hashTable<keyType, valType>::clear() {
    for (size_t x = 0; x < arr.size(); ++x) {
        if (arr[x]) {
            delete arr[x];
            arr[x] = nullptr;
        }
    }
    N = 0;
    arr.clear();
}

template <typename keyType, typename valType>
size_t hashTable<keyType, valType>::size() {
    return N;
}

template <typename keyType, typename valType>
size_t hashTable<keyType, valType>::capacity() {
    return M;
}

void hashTableTest() {
    hashTable<int, int> hashTableObj(5);
    std::cout << "**********insert**********" << std::endl;
    for (int i = 0; i < 100; ++i) {
        hashTableObj.insert(i, i + 100);
        std::cout << "size:\t" << hashTableObj.size() << "\tcapacity:\t" << hashTableObj.capacity() << std::endl;
    }
    hashTableObj.print();
    std::cout << "**********get**********" << std::endl;
    for (int i = 0; i < 100; ++i) {
        std::cout << hashTableObj.get(i)->second << std::endl;
    }
    std::cout << "**********delete**********" << std::endl;
    for (int i = 0; i < 50; ++i) {
        hashTableObj.del(i);
        std::cout << "size:\t" << hashTableObj.size() << "\tcapacity:\t" << hashTableObj.capacity() << std::endl;
    }
    hashTableObj.print();
    for (int i = 50; i < 100; ++i) {
        hashTableObj.del(i);
        std::cout << "size:\t" << hashTableObj.size() << "\tcapacity:\t" << hashTableObj.capacity() << std::endl;
    }
    hashTableObj.print();
}
