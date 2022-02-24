//
//  TopoLogical.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/31.
//

#include "TopoLogical.hpp"

#include <iostream>

#include "DepthFirstOrder.hpp"
#include "DiCycle.hpp"

TopoLogical::TopoLogical(DiGraph g) {
    order.clear();
    DiCycle DC(g);
    if (!DC.has_cycle()) {
        DepthFirstOrder DFO(g);
        order = DFO.get_post();
        std::reverse(order.begin(), order.end());
    }
}

bool TopoLogical::is_DAG() {
    return !order.empty();
}

std::vector<int> TopoLogical::get_order() {
    return order;
}

void topo_logical_test() {
    std::vector<DiEdge> edges;
    edges.emplace_back(0, 5);
    edges.emplace_back(0, 1);
    edges.emplace_back(0, 6);
    edges.emplace_back(2, 0);
    edges.emplace_back(2, 3);
    edges.emplace_back(3, 5);
    edges.emplace_back(5, 4);
    edges.emplace_back(8, 7);
    edges.emplace_back(7, 6);
    edges.emplace_back(6, 4);
    edges.emplace_back(6, 9);
    edges.emplace_back(9, 10);
    edges.emplace_back(9, 12);
    edges.emplace_back(9, 11);
    edges.emplace_back(11, 12);
    int V = 13;
    
    DiGraph DG(V);
    for (DiEdge di_edge: edges) {
        DG.add_edge(di_edge.head, di_edge.tail);
    }
    
    TopoLogical topo_logical(DG);
    for (int v: topo_logical.get_order()) {
        std::cout << v << "\t";
    }
    std::cout << std::endl;
}
