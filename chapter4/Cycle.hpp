//
//  Cycle.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/14.
//

#ifndef Cycle_hpp
#define Cycle_hpp

#include <stdio.h>

#include "Graph.hpp"

class Cycle {
public:
    Cycle(const Graph& g);
    bool is_has_cycle();
private:
    void DFS(const Graph& g, const int& v, const int& u);
    std::vector<bool> masked = {};
    bool has_cycle = false;
};

#endif /* Cycle_hpp */
