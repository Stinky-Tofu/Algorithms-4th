//
//  Graph.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/9/19.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

#include <vector>
#include <map>

class Graph {
public:
    Graph() = default;
    Graph(const int& _V);
    void add_edge(const int& v, const int& w);
    int get_V() const;
    int get_E() const;
    std::vector<int> get_adj(const int& v) const;

private:
    int V = 0;
    int E = 0;
    std::vector<std::vector<int>> adj;
};

#endif /* Graph_hpp */
