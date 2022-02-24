//
//  DiGraph.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/25.
//

#ifndef DiGraph_hpp
#define DiGraph_hpp

#include <stdio.h>

#include <vector>
#include <map>

class DiGraph {
public:
    DiGraph() = default;
    DiGraph(const int& _V);
    void add_edge(const int& v, const int& w);
    int get_V() const;
    int get_E() const;
    std::vector<int> get_adj(const int& v) const;
    DiGraph reverse();

private:
    int V = 0;
    int E = 0;
    std::vector<std::vector<int>> adj;
};

#endif /* DiGraph_hpp */
