//
//  Bag.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#ifndef Bag_hpp
#define Bag_hpp

#include <stdio.h>

#include "Node.hpp"

template <typename T>
class Bag{
public:
    ~Bag();
    void push(const T& item);
private:
    Node<T>* head = nullptr;
};

void BagTest();

#endif /* Bag_hpp */
