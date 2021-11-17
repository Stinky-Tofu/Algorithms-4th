//
//  LazyPrimMST.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/11/15.
//

#include "LazyPrimMST.hpp"

#include <iostream>
#include <fstream>

#include "EdgeWeightedGraph.hpp"
#include "../utils.hpp"


void LazyPrimMST::partition(const EdgeWeightedGraph& G, const int& v) {
    for (const Edge& edge: G.get_adj(v)) {
        int w = edge.other(v);
        if (!masked[w])
            pq.push(edge);
    }
}

bool LazyPrimMST::pop_min_edge(Edge& e) {
    while (!pq.empty()) {
        e = pq.top();
        pq.pop();
        int v = e.either();
        int w = e.other(v);
        if (!masked[v] || !masked[w])
            return true;
    }
    return false;
}

LazyPrimMST::LazyPrimMST(const EdgeWeightedGraph& G) {
    masked = std::vector<bool>(G.get_V(), false);
    int new_mst_node = 0;
    masked[new_mst_node] = true;
    partition(G, new_mst_node);
    while (!pq.empty()) {
        Edge e;
        if (!pop_min_edge(e))
            break;
        mst.push_back(e);
        mst_weight += e.get_weight();
        int v = e.either();
        int w = e.other(v);
        new_mst_node = masked[v] ? w : v;
        masked[new_mst_node] = true;
        partition(G, new_mst_node);
    }
}

std::vector<Edge> LazyPrimMST::edges() {
    return mst;
}

double LazyPrimMST::weight() {
    return mst_weight;
}

void LazyPrimMST_test() {
    std::ifstream file("/Users/stinkytofu/Documents/code/algorithm/algs4-data/mediumEWG.txt");
    std::string line;
    std::getline(file, line);
    int V = std::atoi(line.data());
    std::getline(file, line);
    
    std::cout << "- - - - construct graph - - - -" << std::endl;
    EdgeWeightedGraph graph(V);
    while (std::getline(file, line)) {
        std::vector<std::string> edge;
        std::cout << line << std::endl;
        splitStr(line, edge);
        int pt0 = std::atoi(edge[0].data());
        int pt1 = std::atoi(edge[1].data());
        float weight = std::atof(edge[2].data());
        Edge e(pt0, pt1, weight);
        graph.add_edge(e);
        std::cout << "add edge:\t" << pt0 << " - " << pt1 << "\tweight:\t" << weight << std::endl;
    }
    LazyPrimMST mst(graph);
    for (const Edge& e: mst.edges()) {
        int v = e.either();
        int w = e.other(v);
        std::cout << v << "-" << w << "\t" << e.get_weight() << std::endl;
    }
    std::cout << "mst weight:\t" << mst.weight() << std::endl;
}
