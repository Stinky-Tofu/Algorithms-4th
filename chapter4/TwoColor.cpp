//
//  TwoColor.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/14.
//

#include "TwoColor.hpp"

TwoColor::TwoColor(Graph g) {
    masked = std::vector<bool>(g.get_V(), false);
    color = std::vector<bool>(g.get_V(), false);
    for (int i = 0; i < g.get_V(); ++i) {
        if (!masked[i]) {
            DFS(g, i);
        }
    }
}

void TwoColor::DFS(const Graph& g, const int& v) {
    if (v >= g.get_V())
        return;
    masked[v] = true;
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            DFS(g, adj);
            color[adj] = !color[v];
        } else if (color[adj] == color[v]) {
            is_bipartite = false;
        }
    }
}

bool TwoColor::is_two_colorable() {
    return is_bipartite;
}

