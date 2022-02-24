//
//  PrimMST.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/8.
//

#include "PrimMST.hpp"

#include <iostream>
#include <fstream>

#include "EdgeWeightedGraph.hpp"
#include "utils/utils.hpp"
#include "chapter2/MinIndexedPQ.hpp"

void PrimMST::partition(const EdgeWeightedGraph& G, const int& v) {
    for (const Edge& edge: G.get_adj(v)) {
        int w = edge.other(v);
        if (!masked[w]) {
            if (minPQ.contains(w)) {
                if (minPQ.keyOf(w) > edge.get_weight()) {
                    minPQ.changeKey(w, edge.get_weight());
                    minEdges[w] = edge;
                }
            } else {
                minPQ.insert(w, edge.get_weight());
                minEdges[w] = edge;
            }
        }
    }
}

bool PrimMST::pop_min_edge(Edge& e) {
    while (!minPQ.isEmpty()) {
        int w = minPQ.deleteMin();
        e = minEdges[w];
        int v = e.either();
        w = e.other(v);
        if (!masked[v] || !masked[w])
            return true;
    }
    return false;
}

PrimMST::PrimMST(const EdgeWeightedGraph& G) {
    int V = G.get_V();
    mst.clear();
    mst_weight = 0.0;
    minEdges.resize(V);
    masked = std::vector<bool>(V, false);

    int new_mst_node = 0;
    masked[new_mst_node] = true;
    partition(G, new_mst_node);
    while (!minPQ.isEmpty()) {
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

std::vector<Edge> PrimMST::edges() {
    return mst;
}

double PrimMST::weight() {
    return mst_weight;
}

void PrimMST_test() {
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
    PrimMST mst(graph);
    for (const Edge& e: mst.edges()) {
        int v = e.either();
        int w = e.other(v);
        std::cout << v << "-" << w << "\t" << e.get_weight() << std::endl;
    }
    std::cout << "mst weight:\t" << mst.weight() << std::endl;
}
