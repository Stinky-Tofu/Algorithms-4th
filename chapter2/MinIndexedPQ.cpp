//
//  MinIndexedPQ.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/8.
//

#include "MinIndexedPQ.hpp"

#include <iostream>

void MinIndexedPQ::swap(int i, int j) {
    int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
    index[heap[i]] = i; index[heap[j]] = j;
}

void MinIndexedPQ::bubbleUp(int k)    {
    while(k > 1 && keys[heap[k/2]] > keys[heap[k]])   {
        swap(k, k/2);
        k = k/2;
    }
}

void MinIndexedPQ::bubbleDown(int k)  {
    int j;
    while(2*k <= N) {
        j = 2*k;
        if(j < N && keys[heap[j]] > keys[heap[j+1]])
            j++;
        if(keys[heap[k]] <= keys[heap[j]])
            break;
        swap(k, j);
        k = j;
    }
}

MinIndexedPQ::MinIndexedPQ(int NMAX)  {
    this->NMAX = NMAX;
    N = 0;
    keys = new float[NMAX + 1];
    heap = new int[NMAX + 1];
    index = new int[NMAX + 1];
    for(int i = 0; i <= NMAX; i++)
        index[i] = -1;
}

MinIndexedPQ::~MinIndexedPQ() {
    delete [] keys;
    delete [] heap;
    delete [] index;
}

bool MinIndexedPQ::isEmpty()  {
    return N == 0;
}

bool MinIndexedPQ::contains(int i)    {
    return index[i] != -1;
}

int MinIndexedPQ::size()  {
    return N;
}

void MinIndexedPQ::insert(int i, float key) {
    N++;
    index[i] = N;
    heap[N] = i;
    keys[i] = key;
    bubbleUp(N);
}

int MinIndexedPQ::minIndex()  {
    return heap[1];
}

float MinIndexedPQ::minKey()    {
    return keys[heap[1]];
}

int MinIndexedPQ::deleteMin() {
    int min = heap[1];
    swap(1, N--);
    bubbleDown(1);
    index[min] = -1;
    heap[N+1] = -1;
    return min;
}

float MinIndexedPQ::keyOf(int i)    {
    return keys[i];
}

void MinIndexedPQ::changeKey(int i, float key)  {
    keys[i] = key;
    bubbleUp(index[i]);
    bubbleDown(index[i]);
}

void MinIndexedPQ::decreaseKey(int i, float key)    {
    keys[i] = key;
    bubbleUp(index[i]);
}

void MinIndexedPQ::increaseKey(int i, float key)    {
    keys[i] = key;
    bubbleDown(index[i]);
}

void MinIndexedPQ::deleteKey(int i)   {
    int ind = index[i];
    swap(ind, N--);
    bubbleUp(ind);
    bubbleDown(ind);
    index[i] = -1;
}

int MinIndexedPQ_test()  {
    MinIndexedPQ pq(10);
    pq.insert(0, 3.5);
    pq.insert(1, 3.6);
    pq.insert(2, 2.7);
    pq.insert(3, 1.3);
    pq.insert(4, 9.2);
    pq.insert(5, 8.4);
    pq.insert(6, 0.2);
    pq.insert(7, 5.5);
    std::cout << "key of 0:\t" << pq.keyOf(0) << std::endl;
    std::cout << "min index:\t" << pq.minIndex() << std::endl;
    std::cout << "min key:\t" << pq.minKey() << std::endl;
    pq.insert(8, -0.7);
    std::cout << "min index:\t" << pq.minIndex() << std::endl;
    std::cout << "min key:\t" << pq.minKey() << std::endl;
    pq.changeKey(7, -1.3);
    std::cout << "min index:\t" << pq.minIndex() << std::endl;
    std::cout << "min key:\t" << pq.minKey() << std::endl;
    std::cout << "is pq contain 10?:\t" << pq.contains(10) << std::endl;
    std::cout << "is pq contain 0?:\t" << pq.contains(0) << std::endl;
    std::cout << "is pq empty:\t" << pq.isEmpty() << std::endl;
    std::cout << "pq delete min key:\t" << pq.deleteMin() << std::endl;
    std::cout << "min index:\t" << pq.minIndex() << std::endl;
    std::cout << "min key:\t" << pq.minKey() << std::endl;
    return 0;
}
