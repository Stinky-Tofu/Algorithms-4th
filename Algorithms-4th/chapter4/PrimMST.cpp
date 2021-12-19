//
//  PrimMST.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/12/3.
//

#include "PrimMST.hpp"

#include <iostream>
#include <fstream>

#include "EdgeWeightedGraph.hpp"
#include "../utils.hpp"
#include "../chapter1/UnionFind.hpp"


PrimMST::PrimMST(const EdgeWeightedGraph& G) {
    int V = G.get_V();
    std::vector<Edge> edges = G.get_edges();
    UnionFind uf(V);
    std::sort(edges.begin(), edges.end(),
    [](const Edge &l, const Edge &r) ->bool {return l.get_weight() > r.get_weight();});
    weight = 0;
    while (mst.size() != V - 1) {
        Edge e = *(edges.end()-1);
        edges.erase(edges.end()-1);
        int v = e.either();
        int w = e.other(v);
        if (uf.isConnect(v, w))
            continue;
        mst.push_back(e);
        uf.Union(v, w);
        weight += e.get_weight();
    }
}

std::vector<Edge> PrimMST::get_edges() {
    return mst;
}

double PrimMST::get_weight() {
    return weight;
}

void PrimMST_test() {
    std::ifstream file("/Users/stinkytofu/Documents/code/algorithm/algs4-data/tinyEWG.txt");
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
        std::cout << "add edge:\t" << pt0 << " - " << pt1
                  << "\tweight:\t" << weight << std::endl;
    }
    std::cout << "- - - - construct mst - - - -" << std::endl;
    PrimMST mst(graph);
    for (const Edge& e: mst.get_edges()) {
        int v = e.either();
        int w = e.other(v);
        std::cout << v << "-" << w << "\t" << e.get_weight() << std::endl;
    }
    std::cout << "mst weight:\t" << mst.get_weight() << std::endl;
}

