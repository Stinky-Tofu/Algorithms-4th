//
//  DiGraph.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/25.
//

#include "DiGraph.hpp"

#include <stack>
#include <queue>
#include <map>
#include <fstream>

#include "utils/utils.hpp"

DiGraph::DiGraph(const int& _V) {
    V = _V;
    E = 0;
    adj.clear();
    for (int i = 0; i < V; ++i) {
        adj.emplace_back(std::vector<int>());
        adj[i].clear();
    }
}

void DiGraph::add_edge(const int &v, const int &w) {
    adj[v].insert(adj[v].begin(), w);
    ++E;
}

int DiGraph::get_V() const {
    return V;
}

int DiGraph::get_E() const {
    return E;
}

std::vector<int> DiGraph::get_adj(const int& v) const {
    assert(v < V);
    return adj[v];
}

DiGraph DiGraph::reverse() {
    DiGraph DG(V);
    for (int v = 0; v < V; ++v) {
        for (const int& w: adj[v]) {
            DG.add_edge(w, v);
        }
    }
    return DG;
}
