//
//  DiSearch.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/25.
//

#include "DiSearch.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#include "DiGraph.hpp"
#include "utils/utils.hpp"

DiSearch::DiSearch(DiGraph g, const int& s, SearchMethod search_method) {
    masked = std::vector<bool>(g.get_V(), false);
    edge_to = std::vector<int>(g.get_V(), -1);
    count = 0;
    start = s;
    switch (search_method) {
        case SearchMethod::DFS:
            DFS(g, s);
            break;
        case SearchMethod::BFS:
            BFS(g, s);
            break;
        default:
            break;
    }
}

DiSearch::DiSearch(DiGraph g, const std::vector<int>& sources, SearchMethod search_method) {
    masked = std::vector<bool>(g.get_V(), false);
    edge_to = std::vector<int>(g.get_V(), -1);
    count = 0;
    for (const int& v: sources) {
        if (is_masked(v))
            continue;
        switch (search_method) {
            case SearchMethod::DFS:
                DFS(g, v);
                break;
            case SearchMethod::BFS:
                BFS(g, v);
                break;
            default:
                break;
        }
    }
}

void DiSearch::DFS(const DiGraph& g, const int& v) {
    if (v >= g.get_V())
        return;
    masked[v] = true;
    ++count;
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            edge_to[adj] = v;
            DFS(g, adj);
        }
    }
}

void DiSearch::BFS(const DiGraph& g, const int& v) {
    std::queue<int> q;
    masked[v] = true;
    q.push(v);
    ++count;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (const int& adj: g.get_adj(x)) {
            if (!masked[adj]) {
                edge_to[adj] = x;
                masked[adj] = true;
                q.push(adj);
                ++count;
            }
        }
    }
}

bool DiSearch::has_path_to(const int& v) {
    return masked[v];
}

std::vector<int> DiSearch::path_to(const int& v) {
    std::vector<int> path = {};
    if (!has_path_to(v))
        return path;
    for (int x = v; x != start; x = edge_to[x]) {
        path.push_back(x);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}

int DiSearch::get_count() const {
    return count;
}

bool DiSearch::is_masked(const int &v) const {
    return masked[v];
}

void di_search_test() {
    std::vector<int> sources = {1, 2, 6};
    
    std::ifstream file("/Users/stinkytofu/Documents/code/algorithm/algs4-data/tinyDG.txt");
    std::string line;
    std::getline(file, line);
    int V = std::atoi(line.data());
    std::getline(file, line);
    
    std::cout << "- - - - construct graph - - - -" << std::endl;
    DiGraph di_graph(V);
    while (std::getline(file, line)) {
        std::vector<std::string> di_edge;
        splitStr(line, di_edge);
        int pt0 = std::atoi(di_edge[0].data());
        int pt1 = std::atoi(di_edge[1].data());
        di_graph.add_edge(pt0, pt1);
        std::cout << "add edge:\t" << pt0 << " -> " << pt1 << std::endl;
    }
    
    std::cout << "- - - - search graph - - - -" << std::endl;
    DiSearch di_search_obj(di_graph, sources, SearchMethod::DFS);
    for (int v = 0; v < di_graph.get_V(); ++v) {
        if (di_search_obj.is_masked(v)) {
            std::cout << v << " ";
        }
    }
    std::cout << std::endl;
}
