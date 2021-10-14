//
//  Search.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/10.
//

#ifndef Search_hpp
#define Search_hpp

#include <stdio.h>

#include "Graph.hpp"

#include <vector>

enum SearchMethod {
    DFS,
    BFS
};

class Search {
public:
    Search(Graph g, const int& s, SearchMethod search_method);
    void DFS(const Graph& g, const int& v);
    void BFS(const Graph& g, const int& v);
    bool has_path_to(const int& v);
    std::vector<int> path_to(const int& v);
    int get_count() const;
    bool is_masked(const int& v) const;
    
protected:
    std::vector<bool> masked = {};
    std::vector<int> edge_to = {};
    int count = 0;
    int start = 0;
};


void search_test();

#endif /* Search_hpp */
