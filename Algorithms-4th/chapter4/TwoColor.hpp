//
//  TwoColor.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/14.
//

#ifndef TwoColor_hpp
#define TwoColor_hpp

#include <stdio.h>

#include "Graph.hpp"


class TwoColor {
public:
    TwoColor(Graph g);
    bool is_two_colorable();
private:
    void DFS(const Graph& g, const int& v);
    std::vector<bool> masked = {};
    std::vector<bool> color = {};
    bool is_bipartite = true;
};

#endif /* TwoColor_hpp */
