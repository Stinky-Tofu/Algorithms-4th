//
//  Cycle.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/14.
//

#include "Cycle.hpp"

Cycle::Cycle(const Graph& g) {
    masked = std::vector<bool>(g.get_V(), false);
    has_cycle = false;
    for (int v = 0; v < g.get_V(); ++v) {
        if (!masked[v]) {
            DFS(g, v, v);
        }
    }
}

void Cycle::DFS(const Graph& g, const int& v, const int& u) {
    if (v >= g.get_V())
        return;
    masked[v] = true;
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            DFS(g, adj, v);
        } else if (adj != u) {
            has_cycle = true;
            return;
        }
    }

}

bool Cycle::is_has_cycle() {
    return has_cycle;
}
