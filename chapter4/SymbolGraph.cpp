//
//  SymbolGraph.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/14.
//

#include "SymbolGraph.hpp"

#include <fstream>

#include "utils/utils.hpp"


SymbolGraph::SymbolGraph(const std::string& file_path, const std::string& delim) {
    std::ifstream file(file_path);
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        std::vector<std::string> dataStrVec;
        splitStr(line, dataStrVec, delim);
        for (const std::string& item: dataStrVec) {
            if (st.find(item) == st.end()) {
                st[item] = count;
                ++count;
            }
        }
    }
    keys.resize(count);
    for (const auto& pair: st) {
        keys[pair.second] = pair.first;
    }
    graph = Graph(count);

    std::ifstream file_again(file_path);
    while (std::getline(file_again, line)) {
        std::vector<std::string> dataStrVec;
        splitStr(line, dataStrVec, delim);
        int v = st[dataStrVec[0]];

        for (int i = 1; i < dataStrVec.size(); ++i) {
            graph.add_edge(v, st[dataStrVec[i]]);
        }
    }
}

bool SymbolGraph::contain(const std::string& key) {
    return st.find(key) != st.end();
}

int SymbolGraph::index(const std::string& key) {
    return st[key];
}

std::string SymbolGraph::name(const int& v) {
    return keys[v];
}

Graph SymbolGraph::G() {
    return graph;
}

void symbol_graph_test() {
    std::string filename = "/Users/stinkytofu/Documents/code/algorithm/algs4-data/movies.txt";
    std::string delim = " ";
    SymbolGraph sg(filename, delim);
    Graph graph = sg.G();
    
    std::string line;
    while (std::getline(std::cin, line)) {
        for (int v: graph.get_adj(sg.index(line))) {
            std::cout << "\t" << sg.name(v);
        }
        std::cout << std::endl;
    }
}
