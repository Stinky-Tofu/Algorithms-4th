//
//  DepthFirstOrder.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/31.
//

#ifndef DepthFirstOrder_hpp
#define DepthFirstOrder_hpp

#include <stdio.h>
#include <vector>

#include "DiGraph.hpp"

class DepthFirstOrder {
public:
    DepthFirstOrder(DiGraph g);
    std::vector<int> get_pre();
    std::vector<int> get_post();
    
protected:
    void DFS(const DiGraph& g, const int& v);
    std::vector<bool> masked = {};
    std::vector<int> pre = {};
    std::vector<int> post = {};
};

#endif /* DepthFirstOrder_hpp */
