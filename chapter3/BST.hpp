//
//  BST.hpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/5/29.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

#include <vector>

template <typename keyType, typename valType>
class treeNode {
public:
    treeNode() = default;
    treeNode(keyType _key, valType _val)
    : key(_key), val(_val), left(nullptr), right(nullptr), N(1){}
    treeNode(keyType _key, valType _val, treeNode* _left, treeNode* _right, int _N)
    : key(_key), val(_val), left(_left), right(_right), N(_N){}
    ~treeNode() = default;
    treeNode(const treeNode& r) = default;
    treeNode& operator=(const treeNode& r) = default;
    
    keyType key;
    valType val;
    treeNode* left = nullptr;
    treeNode* right = nullptr;
    int N = 0;
};


template <typename keyType, typename valType>
class BST {
public:
    BST() = default;
    BST(const BST& r);
    BST& operator=(const BST& r);
    ~BST();
    void insert(keyType key, valType val);
    treeNode<keyType, valType>* get(keyType key);
    int size();
    int size(treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* min();
    treeNode<keyType, valType>* max();
    treeNode<keyType, valType>* operator[](int k);
    int rank(keyType key);
    void del_min();
    void del_max();
    void del(keyType key);
    std::vector<treeNode<keyType, valType>*> range(keyType low,
                                                   keyType high);
    treeNode<keyType, valType>* floor(keyType key);
    treeNode<keyType, valType>* ceiling(keyType key);
    void mid_order_print();
    void print_node(treeNode<keyType, valType>* x);
    
private:
    treeNode<keyType, valType>* copyTree(const treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* root = nullptr;
    treeNode<keyType, valType>* insert(treeNode<keyType, valType>* x, keyType key, valType val);
    treeNode<keyType, valType>* get(treeNode<keyType, valType>* x, keyType key);
    void clear(treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* min(treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* max(treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* select(treeNode<keyType, valType>* x, int k);
    int rank(treeNode<keyType, valType>* x, keyType key);
    treeNode<keyType, valType>* del_min(treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* del_max(treeNode<keyType, valType>* x);
    treeNode<keyType, valType>* del(treeNode<keyType, valType>* x, keyType key);
    void range(treeNode<keyType, valType>* x,
               std::vector<treeNode<keyType, valType>*>& vec,
               keyType low,
               keyType high);
    treeNode<keyType, valType>* floor(treeNode<keyType, valType>* x, keyType key);
    treeNode<keyType, valType>* ceiling(treeNode<keyType, valType>* x, keyType key);
    void mid_order_print(treeNode<keyType, valType>* x);
};

void BSTest();

#endif /* BST_hpp */
