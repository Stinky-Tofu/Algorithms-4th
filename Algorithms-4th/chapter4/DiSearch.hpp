//
//  DiSearch.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/25.
//

#ifndef DiSearch_hpp
#define DiSearch_hpp

#include <stdio.h>

#include "Search.hpp"
#include "DiGraph.hpp"

#include <vector>

class DiSearch {
public:
    DiSearch(DiGraph g, const int& s, SearchMethod search_method);
    DiSearch(DiGraph g, const std::vector<int>& sources, SearchMethod search_method);
    void DFS(const DiGraph& g, const int& v);
    void BFS(const DiGraph& g, const int& v);
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

void di_search_test();

#endif /* DiSearch_hpp */
