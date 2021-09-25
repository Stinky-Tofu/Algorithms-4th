////
////  RedBlackTree.cpp
////  Algorithms-4th
////
////  Created by Stinky Tofu on 2021/8/29.
////
//
//#include "RedBlackTree.hpp"
//
//
//template <typename keyType, typename valType>
//Node<keyType, valType>* RedBlackTree<keyType, valType>::rotateLeft(Node<keyType, valType>* h) {
//    Node<keyType, valType>* x = h->right;
//    h->right = x->left;
//    x->left = h;
//    x->color = h->color;
//    h->color = RED;
//    x->N = h->N;
//    h->N = size(h->left) + size(h->right) + 1;
//    return x;
//}
//
//template <typename keyType, typename valType>
//Node<keyType, valType>* RedBlackTree<keyType, valType>::rotateRight(Node<keyType, valType>* h) {
//    Node<keyType, valType>* x = h->left;
//    h->left = x->right;
//    x->right = h;
//    x->color = h->color;
//    h->color = RED;
//    x->N = h->N;
//    h->N = size(h->left) + size(h->right) + 1;
//    return x;
//}
