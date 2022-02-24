//
//  BST.cpp
//  Algorithms-4th
//
//  Created by StinkyTofu on 2021/5/29.
//

#include "BST.hpp"

#include <iostream>

template <typename keyType, typename valType>
BST<keyType, valType>::~BST() {
    clear(root);
}

template <typename keyType, typename valType>
BST<keyType, valType>::BST(const BST& r) {
    root = copyTree(r.root);
}

template <typename keyType, typename valType>
BST<keyType, valType>& BST<keyType, valType>::operator=(const BST& r) {
    clear(root);
    root = copyTree(r.root);
    return *this;
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::copyTree(const treeNode<keyType, valType>* x) {
    if (!x) return nullptr;
    treeNode<keyType, valType>* xCopy = new treeNode<keyType, valType>(x->key, x->val);
    xCopy->left = copyTree(x->left);
    xCopy->right = copyTree(x->right);
    xCopy->N = size(xCopy->left) + size(xCopy->right) + 1;
    return xCopy;
}

template <typename keyType, typename valType>
void BST<keyType,  valType>::clear(treeNode<keyType, valType>* x) {
    if (x == nullptr) {
        return;
    }
    clear(x->left);
    clear(x->right);
    delete x;
    x = nullptr;
}

template <typename keyType, typename valType>
void BST<keyType, valType>::insert(keyType key, valType val) {
    root = insert(root, key, val);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::insert(treeNode<keyType,valType>* x,
                                                          keyType key,
                                                          valType val) {
    if (x == nullptr) {
        return new treeNode<keyType, valType>(key, val, nullptr, nullptr, 1);
    }
    if (key < x->key)
        x->left = insert(x->left, key, val);
    if (key == x->key)
        x->val = val;
    if (key > x->key)
        x->right = insert(x->right, key, val);
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::get(keyType key) {
    return get(root, key);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::get(treeNode<keyType,
                                                       valType>* x,
                                                       keyType key) {
    if (x == nullptr)
        return nullptr;
    if (key < x->key)
        return get(x->left, key);
    else if (key == x->key)
        return x;
    else
        return get(x->right, key);
    
}


template <typename keyType, typename valType>
int BST<keyType, valType>::size(treeNode<keyType, valType>* x) {
    return (x == nullptr) ? 0 : x->N;
}

template <typename keyType, typename valType>
int BST<keyType, valType>::size() {
    return size(root);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::min() {
    return min(root);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::min(treeNode<keyType, valType>* x) {
    if (!x) return nullptr;
    if (!x->left) return x;
    return min(x->left);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::max() {
    return max(root);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::max(treeNode<keyType, valType>* x) {
    if (!x) return nullptr;
    if (!x->right) return x;
    return max(x->right);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::operator[](int k) {
    return select(root, k);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::select(treeNode<keyType, valType>* x, int k) {
    if (size(x) < k) return nullptr;
    int left_N = size(x->left);
    if (left_N == k-1)
        return x;
    else if (left_N == k)
        return max(x->left);
    else if (left_N < k - 1)
        return select(x->right, k - 1 - left_N);
    else
        return select(x->left, k);
}

template <typename keyType, typename valType>
int BST<keyType, valType>::rank(keyType key) {
    return rank(root, key);
}

template <typename keyType, typename valType>
int BST<keyType, valType>::rank(treeNode<keyType, valType>* x, keyType key) {
    if (!x) return -1;
    if (x->key == key)
        return size(x->left) + 1;
    else if (x->key > key)
        return rank(x->left, key);
    else {
        int r = rank(x->right, key);
        if (r == -1)
            return -1;
        else
            return size(x->left) + 1 + r;
    }
}

template <typename keyType, typename valType>
void BST<keyType, valType>::del_min() {
    root = del_min(root);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::del_min(treeNode<keyType, valType>* x) {
    if (!x->left) {
        treeNode<keyType, valType>* x_right = x->right;
        delete x;
        return x_right;
    }
    x->left = del_min(x->left);
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

template <typename keyType, typename valType>
void BST<keyType, valType>::del_max() {
    root = del_max(root);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::del_max(treeNode<keyType, valType>* x) {
    if (!x->right) {
        treeNode<keyType, valType>* x_left = x->left;
        delete x;
        return x_left;
    }
    x->right = del_max(x->right);
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

template <typename keyType, typename valType>
void BST<keyType, valType>::del(keyType key) {
    root = del(root, key);
}


template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::del(treeNode<keyType, valType>* x, keyType key) {
    if (!x) return nullptr;
    if (x->key < key) {
        x->right = del(x->right, key);
    } else if (x->key > key) {
        x->left = del(x->left, key);
    } else {
        if (!x->left) {
            treeNode<keyType, valType>* x_right = x->right;
            delete x;
            return x_right;
        }
        if (!x->right) {
            treeNode<keyType, valType>* x_left = x->left;
            delete x;
            return x_left;
        }
        
        treeNode<keyType, valType>* x_right_min_node = new treeNode<keyType, valType>();
        *x_right_min_node = *min(x->right);
        x_right_min_node->left = x->left;
        x_right_min_node->right = del_min(x->right);
        delete x;
        x = x_right_min_node;
    }
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

template <typename keyType, typename valType>
std::vector<treeNode<keyType, valType>*> BST<keyType, valType>::range(keyType low,
                                                                      keyType high) {
    std::vector<treeNode<keyType, valType>*> vec{};
    range(root, vec, low, high);
    return vec;
}

template <typename keyType, typename valType>
void BST<keyType, valType>::range(treeNode<keyType, valType>* x,
           std::vector<treeNode<keyType, valType>*>& vec,
           keyType low,
           keyType high) {
    if (!x) return;
    range(x->left, vec, low, high);
    if (x->key >= low && x->key <= high) vec.push_back(x);
    range(x->right, vec, low, high);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::floor(keyType key) {
    return floor(root, key);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::floor(treeNode<keyType, valType>* x, keyType key) {
    if (!x) return nullptr;
    if (x->key == key) {
        return x;
    } else if (x->key < key) {
        treeNode<keyType, valType>* t = floor(x->right, key);
        return (!t ? x : t);
    } else {
        return floor(x->left, key);
    }
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::ceiling(keyType key) {
    return ceiling(root, key);
}

template <typename keyType, typename valType>
treeNode<keyType, valType>* BST<keyType, valType>::ceiling(treeNode<keyType, valType>* x, keyType key) {
    if (!x) return nullptr;
    if (x->key == key) {
        return x;
    } else if (x->key > key) {
        treeNode<keyType, valType>* t = ceiling(x->left, key);
        return (!t ? x : t);
    } else {
        return ceiling(x->right, key);
    }
}

template <typename keyType, typename valType>
void BST<keyType, valType>::mid_order_print() {
    mid_order_print(root);
}

template <typename keyType, typename valType>
void BST<keyType, valType>::mid_order_print(treeNode<keyType, valType>* x) {
    if (!x) return;
    mid_order_print(x->left);
    std::cout << "key: " << x->key << "\tval: " << x->val << "\tN: " << x->N << std::endl;
    mid_order_print(x->right);
}

template <typename keyType, typename valType>
void BST<keyType, valType>::print_node(treeNode<keyType, valType>* x) {
    std::cout << "key: " << x->key << "\tval: " << x->val << "\tN: " << x->N << std::endl;
}


void BSTest() {
    std::cout << "*******insert*******" << std::endl;
    BST<int, int> bst;
    bst.insert(3, 1);
    bst.insert(1, 2);
    bst.insert(2, 4);
    bst.insert(2, 5);
    bst.insert(7, 4);
    bst.insert(9, 7);
    bst.insert(19, 20);
    bst.insert(0, 4);
    bst.insert(10, 4);
    bst.mid_order_print();
    
    std::cout << "*******copy construct*******" << std::endl;
    BST<int, int> copyBst(bst);
    copyBst.mid_order_print();
    
    std::cout << "*******assign*******" << std::endl;
    BST<int, int> assignBst;
    assignBst = bst;
    assignBst.mid_order_print();

    std::cout << "*******get min node and max node*******" << std::endl;
    bst.print_node(bst.min());
    bst.print_node(bst.max());
    
    std::cout << "*******floor and ceiling*******" << std::endl;
    bst.print_node(bst.floor(4));
    bst.print_node(bst.ceiling(4));
    
    std::cout << "*******select*******" << std::endl;
    bst.print_node(bst[4]);
    
    std::cout << "*******rank*******" << std::endl;
    std::cout << "rank:\t" << bst.rank(9) << std::endl;
    std::cout << "rank:\t" << bst.rank(1) << std::endl;
    std::cout << "rank:\t" << bst.rank(2) << std::endl;
    std::cout << "rank:\t" << bst.rank(7) << std::endl;
    std::cout << "rank:\t" << bst.rank(3) << std::endl;
    std::cout << "rank:\t" << bst.rank(10) << std::endl;
    std::cout << "rank:\t" << bst.rank(12) << std::endl;
    
    std::cout << "*******del min and max*******" << std::endl;
    bst.del_min();
    bst.del_max();
    bst.mid_order_print();
    
    std::cout << "*******del*******" << std::endl;
    bst.del(3);
    bst.mid_order_print();
    
    std::cout << "*******range*******" << std::endl;
    std::vector<treeNode<int, int>*> vec = bst.range(3, 10);
    for (treeNode<int, int>* ele: vec) {
        std::cout << ele->key << std::endl;
    }

}
