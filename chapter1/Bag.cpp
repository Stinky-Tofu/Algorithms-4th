//
//  Bag.cpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#include "Bag.hpp"

#include <vector>
#include <iostream>


template<typename T>
Bag<T>::~Bag(){
    while (head) {
        Node<T>* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

template<typename T>
void Bag<T>::push(const T &item){
    Node<T>* newNode = new Node<T>();
    newNode->item = item;
    newNode->next = head;
    head = newNode;
}

void BagTest(){
    std::vector<int> arr{1, 2, 3, 4, 5};
    Bag<int> bag;
    for (const int& item : arr) {
        bag.push(item);
    }
}
