//
//  Node.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/14.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <typename T>
class Node{
public:
    /*
     Node的析构函数只需要按默认析构函数把item对象和next指针对象销毁即可，不能在析构函数中通过delete next释放
     next指针所指的对象，因为如果在释放对象A的析构函数中delelte next，那么就相当于在释放对象A的时候，
     同时释放了A.next所指向的对象B，在释放对象B的析构函数中delete next，又会释放B.next所指向的对象C，
     从而造成连锁反应，这是不合理的，因为析构函数只能用于销毁当前对象，禁止销毁其他对象，销毁其他对象应该由指向
     其他对象的指针来销毁。
    */
    T item = T();
    Node* next = nullptr;
};

#endif /* Node_hpp */
