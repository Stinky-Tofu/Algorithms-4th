//
//  EdgeWeightedGraph.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/11/14.
//

#include "EdgeWeightedGraph.hpp"

EdgeWeightedGraph::EdgeWeightedGraph(int V_) {
    V = V_;
    E = 0;
    adj.clear();
    adj.resize(V);
    for (std::vector<Edge> temp: adj) {
        temp.clear();
    }
}

int EdgeWeightedGraph::get_V() const {
    return V;
}

int EdgeWeightedGraph::get_E() const {
    return E;
}

std::vector<Edge> EdgeWeightedGraph::get_adj(int v) const {
    return adj[v];
}

std::vector<Edge> EdgeWeightedGraph::get_edges() const {
    return edges;
}

void EdgeWeightedGraph::add_edge(const Edge& e) {
    int v = e.either();
    int w = e.other(v);
    adj[v].push_back(e);
    adj[w].push_back(e);
    ++E;
    edges.push_back(e);
}
