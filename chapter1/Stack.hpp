//
//  Stack.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

#include "Node.hpp"

template <typename T>
class Stack{
public:
    ~Stack();
    void push(const T& item);
    T pop();
private:
    //  head用于指向栈顶结点
    Node<T>* head = nullptr;
};

void StackTest();

#endif /* Stack_hpp */
