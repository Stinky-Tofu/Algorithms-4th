//
//  CC.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/13.
//

#include "CC.hpp"

#include <fstream>
#include <iostream>
#include <vector>

#include "utils/utils.hpp"



CC::CC(Graph g) {
    masked = std::vector<bool>(g.get_V(), false);
    id = std::vector<int>(g.get_V(), -1);
    for (int i = 0; i < g.get_V(); ++i) {
        if (!masked[i]) {
            DFS(g, i);
            ++count;
        }
    }
}

void CC::DFS(const Graph& g, const int& v) {
    masked[v] = true;
    id[v] = count;
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            DFS(g, adj);
        }
    }
}

bool CC::is_connected(const int &u, const int &w) const{
    return id[u] == id[w];
}

int CC::get_count() const {
    return count;
}

int CC::get_id(const int& v) const {
    return id[v];
}

void CC_test() {
    std::ifstream file("/Users/stinkytofu/Documents/code/algorithm/algs4-data/tinyG.txt");
    std::string line;
    std::getline(file, line);
    int V = std::atoi(line.data());
    std::getline(file, line);
    
    std::cout << "- - - - construct graph - - - -" << std::endl;
    Graph graph(V);
    while (std::getline(file, line)) {
        std::vector<std::string> edge;
        splitStr(line, edge);
        int pt0 = std::atoi(edge[0].data());
        int pt1 = std::atoi(edge[1].data());
        graph.add_edge(pt0, pt1);
        std::cout << "add edge:\t" << pt0 << " - " << pt1 << std::endl;
    }
    
    CC cc(graph);
    std::vector<std::vector<int>> components;
    components.resize(cc.get_count());
    for (int v = 0; v < graph.get_V(); ++v) {
        int id = cc.get_id(v);
        components[id].push_back(v);
    }
    
    for (const std::vector<int>& component: components) {
        printVec(component);
    }
}
