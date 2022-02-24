//
//  hashTable.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/7/11.
//

#ifndef hashTable_hpp
#define hashTable_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include <functional>

template <typename keyType, typename valType>
class hashTable {
public:
    hashTable(const int& mInit);
    ~hashTable();
    hashTable(const hashTable& r) = delete;
    hashTable& operator=(const hashTable& r) = delete;
    void insert(keyType key, valType val);
    std::pair<keyType, valType>* get(keyType key);
    void del(keyType key);
    void resize(int cap);
    void print();
    void clear();
    size_t size();
    size_t capacity();
private:
    int hash(keyType key);
    int M = 0;
    int N = 0;
    std::hash<keyType> hashcode;
    std::vector<std::pair<keyType, valType>*> arr;
};

void hashTableTest();

#endif /* hashTable_hpp */
