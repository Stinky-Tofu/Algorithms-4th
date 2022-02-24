//
//  SymbolGraph.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/14.
//

#ifndef SymbolGraph_hpp
#define SymbolGraph_hpp

#include <stdio.h>

#include "Graph.hpp"

class SymbolGraph {
public:
    SymbolGraph(const std::string& file_path, const std::string& delim);
    bool contain(const std::string& key);
    int index(const std::string& key);
    std::string name(const int& v);
    Graph G();
private:
    Graph graph;
    std::map<std::string, int> st;
    std::vector<std::string> keys;
};

void symbol_graph_test();


#endif /* SymbolGraph_hpp */
