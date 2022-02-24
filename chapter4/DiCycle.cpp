//
//  DiCycle.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/31.
//

#include "DiCycle.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#include "DiGraph.hpp"
#include "utils/utils.hpp"

DiCycle::DiCycle(DiGraph g) {
    masked = std::vector<bool>(g.get_V(), false);
    edge_to = std::vector<int>(g.get_V(), -1);
    on_stack = std::vector<bool>(g.get_V(), false);
    cycle = {};
    cycle.clear();
    assert(cycle.empty());
    for (int v = 0; v < g.get_V(); ++v) {
        if (!masked[v])
            DFS(g, v);
    }
}

void DiCycle::DFS(const DiGraph& g, const int& v) {
    masked[v] = true;
    on_stack[v] = true;
    for (const int& adj: g.get_adj(v)) {
        if (has_cycle()) {
            return;
        } else if (!masked[adj]) {
            edge_to[adj] = v;
            DFS(g, adj);
        } else if (on_stack[adj]) {
            for (int x = v; v != adj; x = edge_to[x]) {
                cycle.push_back(x);
            }
            cycle.push_back(adj);
            cycle.push_back(v);
        }
    }
    on_stack[v] = false;
}

bool DiCycle::has_cycle() {
    return !cycle.empty();
}

std::vector<int> DiCycle::get_cycle() {
    return cycle;
}
