////
////  RedBlackTree.hpp
////  Algorithms-4th
////
////  Created by Stinky Tofu on 2021/8/29.
////
//
//#ifndef RedBlackTree_hpp
//#define RedBlackTree_hpp
//
//#include <stdio.h>
//
//#include <vector>
//
//
//enum NodeColor {
//    BLACK = 0,
//    RED = 1
//};
//
//
//template <typename keyType, typename valType>
//class Node {
//public:
//    Node() = default;
//    Node(keyType _key, valType _val)
//    : key(_key), val(_val), left(nullptr), right(nullptr), color(BLACK), N(1){}
//    Node(keyType _key, valType _val, Node* _left, Node* _right, bool _color, int _N)
//    : key(_key), val(_val), left(_left), right(_right), color(_color), N(_N){}
//    ~Node() = default;
//    Node(const Node& r) = default;
//    Node& operator=(const Node& r) = default;
//
//    keyType key;
//    valType val;
//    Node* left = nullptr;
//    Node* right = nullptr;
//    bool color = BLACK;
//    int N = 0;
//};
//
//template <typename keyType, typename valType>
//class RedBlackTree {
//public:
//    RedBlackTree() = default;
//    RedBlackTree(const RedBlackTree& r);
//    RedBlackTree& operator=(const RedBlackTree& r);
//    ~RedBlackTree();
//    Node<keyType, valType>* rotateLeft(Node<keyType, valType>* h);
//    Node<keyType, valType>* rotateRight(Node<keyType, valType>* h);
//
//    void insert(keyType key, valType val);
//    Node<keyType, valType>* get(keyType key);
//    int size();
//    int size(Node<keyType, valType>* x);
//    Node<keyType, valType>* min();
//    Node<keyType, valType>* max();
//    Node<keyType, valType>* operator[](int k);
//    int rank(keyType key);
//    void del_min();
//    void del_max();
//    void del(keyType key);
//    std::vector<Node<keyType, valType>*> range(keyType low,
//                                                   keyType high);
//    Node<keyType, valType>* floor(keyType key);
//    Node<keyType, valType>* ceiling(keyType key);
//    void mid_order_print();
//    void print_node(Node<keyType, valType>* x);
//
//private:
//    Node<keyType, valType>* copyTree(const Node<keyType, valType>* x);
//    Node<keyType, valType>* root = nullptr;
//    Node<keyType, valType>* insert(Node<keyType, valType>* x, keyType key, valType val);
//    Node<keyType, valType>* get(Node<keyType, valType>* x, keyType key);
//    void clear(Node<keyType, valType>* x);
//    Node<keyType, valType>* min(Node<keyType, valType>* x);
//    Node<keyType, valType>* max(Node<keyType, valType>* x);
//    Node<keyType, valType>* select(Node<keyType, valType>* x, int k);
//    int rank(Node<keyType, valType>* x, keyType key);
//    Node<keyType, valType>* del_min(Node<keyType, valType>* x);
//    Node<keyType, valType>* del_max(Node<keyType, valType>* x);
//    Node<keyType, valType>* del(Node<keyType, valType>* x, keyType key);
//    void range(Node<keyType, valType>* x,
//               std::vector<Node<keyType, valType>*>& vec,
//               keyType low,
//               keyType high);
//    Node<keyType, valType>* floor(Node<keyType, valType>* x, keyType key);
//    Node<keyType, valType>* ceiling(Node<keyType, valType>* x, keyType key);
//    void mid_order_print(Node<keyType, valType>* x);
//};
//
//#endif /* RedBlackTree_hpp */
