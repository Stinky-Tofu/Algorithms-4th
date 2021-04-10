//
//  Stack.cpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#include "Stack.hpp"

#include <vector>
#include <iostream>


template<typename T>
Stack<T>::~Stack(){
    while (head) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T &item){
    Node<T>* newNode = new Node<T>();
    newNode->item = item;
    newNode->next = head;
    head = newNode;
}


template<typename T>
T Stack<T>::pop(){
    if (head){
        Node<T>* nextNode = head->next;
        T item = head->item;
        delete head;
        head = nextNode;
        return item;
    }
    else{
        throw "stack empty";
    }
}

void StackTest(){
    std::vector<int> arr{1, 2, 3, 4, 5};
    Stack<int> stack;
    for (const int& item : arr) {
        stack.push(item);
    }
    for (int i = 0; i < arr.size(); ++i){
        std::cout << stack.pop() << std::endl;
    }
}
