//
//  MinIndexedPQ.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/8.
//

#ifndef MinIndexedPQ_hpp
#define MinIndexedPQ_hpp

#include <stdio.h>
#include <iostream>

/*
 * Indexed min priority queue
 * Supports insertion in O(log N), deletion of any key (regardless of whether
 * the key is the minimum key or not) in O(log N) and changes to key values
 * in O(log N), where N is the number of
 * elements currently in the PQ
 */
class MinIndexedPQ {
private:
    int NMAX, N, *heap, *index;
    float *keys;

    void swap(int i, int j);

    void bubbleUp(int k);

    void bubbleDown(int k);

public:
    // Create an empty MinIndexedPQ which can contain atmost NMAX elements
    MinIndexedPQ(int NMAX);
    
    ~MinIndexedPQ();

    // check if the PQ is empty
    bool isEmpty();

    // check if i is an index on the PQ
    bool contains(int i);
    
    // return the number of elements in the PQ
    int size();

    // associate key with index i; 0 < i < NMAX
    void insert(int i, float key);

    // returns the index associated with the minimal key
    int minIndex();

    // returns the minimal key
    float minKey();

    // delete the minimal key and return its associated index
    // Warning: Don't try to read from this index after calling this function
    int deleteMin();

    // returns the key associated with index i
    float keyOf(int i);

    // change the key associated with index i to the specified value
    void changeKey(int i, float key);

    // decrease the key associated with index i to the specified value
    void decreaseKey(int i, float key);

    // increase the key associated with index i to the specified value
    void increaseKey(int i, float key);

    // delete the key associated with index i
    void deleteKey(int i);
};

int MinIndexedPQ_test();

#endif /* MinIndexedPQ_hpp */
