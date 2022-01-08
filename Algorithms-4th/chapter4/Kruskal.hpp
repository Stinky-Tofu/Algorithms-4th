//
//  Kruskal.hpp
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

class Kruskal {
public:
    Kruskal(const EdgeWeightedGraph& G);
    std::vector<Edge> get_edges();
    double get_weight();
private:
    std::vector<Edge> mst;
    double weight;
};

void Kruskal_test();

#endif /* Kruskal_hpp */
