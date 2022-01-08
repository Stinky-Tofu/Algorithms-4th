//
//  PrimMST.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/8.
//

#ifndef PrimMST_hpp
#define PrimMST_hpp

#include <stdio.h>

#include <vector>
#include <queue>

#include "EdgeWeightedGraph.hpp"
#include "../chapter2/MinIndexedPQ.hpp"

class PrimMST {
public:
    PrimMST(const EdgeWeightedGraph& G);
    std::vector<Edge> edges();
    double weight();
private:
    void partition(const EdgeWeightedGraph& G, const int& v);
    bool pop_min_edge(Edge& e);

    std::vector<Edge> mst;
    double mst_weight = 0.0;
    std::vector<Edge> minEdges;
    MinIndexedPQ minPQ = MinIndexedPQ(1000);
    std::vector<bool> masked;
};

void PrimMST_test();

#endif /* PrimMST_hpp */
