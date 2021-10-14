//
//  Search.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/10.
//

#include "Search.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#include "Graph.hpp"
#include "utils.hpp"

Search::Search(Graph g, const int& s, SearchMethod search_method) {
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

void Search::DFS(const Graph& g, const int& v) {
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

void Search::BFS(const Graph& g, const int& v) {
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

bool Search::has_path_to(const int& v) {
    return masked[v];
}

std::vector<int> Search::path_to(const int& v) {
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

int Search::get_count() const {
    return count;
}

bool Search::is_masked(const int &v) const {
    return masked[v];
}

void search_test() {
    int start = 0;
    std::ifstream file("/Users/stinkytofu/Documents/code/algorithm/algs4-data/tinyCG.txt");
    std::string line;
    std::getline(file, line);
    int V = std::atoi(line.data());
    std::getline(file, line);
    
    std::cout << "- - - - construct graph - - - -" << std::endl;
    Graph graph(V);
    while (std::getline(file, line)) {
        std::vector<std::string> edge;
        splitStr(line, edge);
        int pt0 = std::atoi(edge[0].data());
        int pt1 = std::atoi(edge[1].data());
        graph.add_edge(pt0, pt1);
        std::cout << "add edge:\t" << pt0 << " - " << pt1 << std::endl;
    }
    
    std::cout << "- - - - search graph - - - -" << std::endl;
    Search search_obj(graph, start, SearchMethod::DFS);
    for (int v = 0; v < graph.get_V(); ++v) {
        std::cout << start << " to " << v << ":\t";
        if (search_obj.has_path_to(v)) {
            for (const int& x: search_obj.path_to(v)) {
                if (x == start)
                    std::cout << x;
                else
                    std::cout << "->" << x;
            }
            std::cout << std::endl;
        }
    }
}
