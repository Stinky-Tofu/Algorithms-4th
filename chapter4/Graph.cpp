//
//  Graph.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/9/19.
//

#include "Graph.hpp"

#include <stack>
#include <queue>
#include <map>
#include <fstream>

#include "utils/utils.hpp"

Graph::Graph(const int& _V) {
    V = _V;
    E = 0;
    adj.clear();
    for (int i = 0; i < V; ++i) {
        adj.emplace_back(std::vector<int>());
        adj[i].clear();
    }
}

void Graph::add_edge(const int &v, const int &w) {
    adj[v].insert(adj[v].begin(), w);
    adj[w].insert(adj[w].begin(), v);
    ++E;
}

int Graph::get_V() const {
    return V;
}

int Graph::get_E() const {
    return E;
}

std::vector<int> Graph::get_adj(const int& v) const {
    assert(v < V);
    return adj[v];
}
