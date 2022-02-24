//
//  Queue.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

#include "Node.hpp"

template <typename T>
class Queue{
public:
    ~Queue();
    void enqueue(const T& item);
    T dequeue();
private:
    //  head用于指向队头结点，tail指向队尾结点
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};

void QueueTest();

#endif /* Queue_hpp */
