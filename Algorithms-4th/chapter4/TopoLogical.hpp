//
//  TopoLogical.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/31.
//

#ifndef TopoLogical_hpp
#define TopoLogical_hpp

#include <stdio.h>
#include <vector>

#include "DiGraph.hpp"

class DiEdge {
public:
    DiEdge(int head_, int tail_)
    : head(head_), tail(tail_){}
    int head;
    int tail;
};

class TopoLogical {
public:
    TopoLogical(DiGraph g);
    bool is_DAG();
    std::vector<int> get_order();
private:
    std::vector<int> order;
};

void topo_logical_test();

#endif /* TopoLogical_hpp */
