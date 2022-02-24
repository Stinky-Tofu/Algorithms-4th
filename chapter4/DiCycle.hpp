//
//  DiCycle.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/31.
//

#ifndef DiCycle_hpp
#define DiCycle_hpp

#include <stdio.h>
#include <vector>

#include "DiGraph.hpp"

class DiCycle {
public:
    DiCycle(DiGraph g);
    bool has_cycle();
    std::vector<int> get_cycle();
    
protected:
    void DFS(const DiGraph& g, const int& v);
    std::vector<bool> masked = {};
    std::vector<int> edge_to = {};
    std::vector<bool> on_stack = {};
    std::vector<int> cycle = {};
};


#endif /* DiCycle_hpp */
