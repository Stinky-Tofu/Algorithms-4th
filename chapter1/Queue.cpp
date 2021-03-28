//
//  Queue.cpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#include "Queue.hpp"

#include <vector>
#include <iostream>

template<typename T>
Queue<T>::~Queue(){
    while (head) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::enqueue(const T &item){
    Node<T>* oldTail = tail;
    tail = new Node<T>();
    tail->item = item;
    tail->next = nullptr;
    if (head == nullptr){
        head = tail;
    }else{
        oldTail->next = tail;
    }
}


template<typename T>
T Queue<T>::dequeue(){
    if (head){
        Node<T>* nextNode = head->next;
        T item = head->item;
        delete head;
        head = nextNode;
        if (head == nullptr){
            tail = nullptr;
        }
        return item;
    }
    else{
        throw "stack empty";
    }
}

void QueueTest(){
    std::vector<int> arr{1, 2, 3, 4, 5, 6};
    Queue<int> queue;
    for (const int& item : arr) {
        queue.enqueue(item);
    }
    for (int i = 0; i < arr.size(); ++i){
        std::cout << queue.dequeue() << std::endl;
    }
}
