//
//  DepthFirstOrder.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/31.
//

#include "DepthFirstOrder.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#include "DiGraph.hpp"
#include "utils.hpp"

DepthFirstOrder::DepthFirstOrder(DiGraph g) {
    masked = std::vector<bool>(g.get_V(), false);
    pre = {};
    post = {};
    pre.clear();
    post.clear();
    for (int v = 0; v < g.get_V(); ++v) {
        if (!masked[v])
            DFS(g, v);
    }
}

void DepthFirstOrder::DFS(const DiGraph& g, const int& v) {
    masked[v] = true;
    pre.push_back(v);
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            DFS(g, adj);
        }
    }
    post.push_back(v);
}

std::vector<int> DepthFirstOrder::get_pre() {
    return pre;
}

std::vector<int> DepthFirstOrder::get_post() {
    return post;
}
