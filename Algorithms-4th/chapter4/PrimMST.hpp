//
//  PrimMST.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/12/3.
//

#ifndef PrimMST_hpp
#define PrimMST_hpp

#include <stdio.h>

#include <vector>
#include <queue>

#include "EdgeWeightedGraph.hpp"
#include "../chapter2/min_pq.hpp"

class PrimMST {
public:
    PrimMST(const EdgeWeightedGraph& G);
    std::vector<Edge> get_edges();
    double get_weight();
private:
    std::vector<Edge> mst;
    double weight;
};

void PrimMST_test();

#endif /* PrimMST_hpp */
