//
//  LazyPrimMST.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/11/15.
//

#ifndef LazyPrimMST_hpp
#define LazyPrimMST_hpp

#include <stdio.h>

#include <vector>
#include <queue>

#include "EdgeWeightedGraph.hpp"
#include "../chapter2/min_pq.hpp"

class LazyPrimMST {
public:
    LazyPrimMST(const EdgeWeightedGraph& G);
    std::vector<Edge> edges();
    double weight();
private:
    void partition(const EdgeWeightedGraph& G, const int& v);
    bool pop_min_edge(Edge& e);
    
    std::vector<bool> masked;
    std::vector<Edge> mst;
    std::priority_queue<Edge, std::vector<Edge>, cmp> pq;
    double mst_weight = 0.0;
};

void LazyPrimMST_test();

#endif /* LazyPrimMST_hpp */
