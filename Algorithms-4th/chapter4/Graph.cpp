//
//  Graph.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/9/19.
//

#include "Graph.hpp"

#include <stack>
#include <queue>
#include <map>
#include <fstream>

#include "utils.hpp"

Graph::Graph(const int& _V) {
    V = _V;
    E = 0;
    adj.resize(_V);
}

int Graph::get_V() const {
    return V;
}

int Graph::get_E() const {
    return E;
}

std::vector<int> Graph::get_adj(const int& v) const {
    assert(v < V);
    return adj[v];
}

void Graph::add_edge(const int &v, const int &w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    ++E;
}


Search::Search(Graph g, const int& s) {
    masked = std::vector<bool>(g.get_V(), false);
    edge_to = std::vector<int>(g.get_V(), -1);
    count = 0;
    start = s;
    search(g, s);
}

int Search::get_count() const {
    return count;
}

bool Search::is_masked(const int &v) const {
    return masked[v];
}

void Search::search(const Graph& g, const int& v) {
    if (v >= g.get_V())
        return;
    masked[v] = true;
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            edge_to[adj] = v;
            search(g, adj);
            ++count;
        }
    }
}

bool Search::has_path_to(const int& v) {
    return masked[v];
}

std::vector<int> Search::path_to(const int& v) {
    std::vector<int> path = {};
    for (int x = v; x != start; x = edge_to[x]) {
        path.push_back(x);
    }
    path.push_back(start);
    return path;
}


void DepthFirstSearch::search(const Graph& g, const int& v) {
    if (v >= g.get_V())
        return;
    std::stack<int> st;
    st.push(v);
    while (!st.empty()) {
        int x = st.top();
        masked[x] = true;
        ++count;
        st.pop();
        for (const int& adj: g.get_adj(x)) {
            if (!masked[adj])
                edge_to[adj] = x;
                st.push(adj);
        }
    }
}

void BreadFirstSearch::search(const Graph& g, const int& v) {
    if (v >= g.get_V())
        return;
    std::queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int x = q.front();
        masked[x] = true;
        ++count;
        q.pop();
        for (const int& adj: g.get_adj(x)) {
            if (!masked[adj])
                edge_to[adj] = x;
                q.push(adj);
        }
    }
}


CC::CC(Graph g) {
    masked = std::vector<bool>(g.get_V(), false);
    id = std::vector<int>(g.get_V(), -1);
    for (int i = 0; i < g.get_V(); ++i) {
        if (!masked[i]) {
            DFS(g, i);
            ++count;
        }
    }
}

void CC::DFS(const Graph& g, const int& v) {
    if (v >= g.get_V())
        return;
    masked[v] = true;
    id[v] = count;
    for (const int& adj: g.get_adj(v)) {
        if (!masked[adj]) {
            DFS(g, adj);
        }
    }
}

bool CC::is_connected(const int &u, const int &w) const{
    return id[u] == id[w];
}

int CC::get_count() const {
    return count;
}

int CC::get_id(const int& v) const {
    return id[v];
}

SymbolGraph::SymbolGraph(const std::string& file_path, const std::string& delim) {
    std::ifstream file(file_path);
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> dataStrVec;
        splitStr(line, dataStrVec, delim);
        int count = 0;
        for (const std::string& item: dataStrVec) {
            st[item] = count;
            ++count;
        }
    }
    for (const auto& pair: st) {
        keys[pair.second] = pair.first;
    }
    graph = Graph((int)st.size());
    
    while (std::getline(file, line)) {
        std::vector<std::string> dataStrVec;
        splitStr(line, dataStrVec, delim);
        int v = st[dataStrVec[0]];
        
        for (int i = 1; i < dataStrVec.size(); ++i) {
            graph.add_edge(v, st[dataStrVec[i]]);
        }
    }
}

bool SymbolGraph::contain(const std::string& key) {
    return st.find(key) != st.end();
}

int SymbolGraph::index(const std::string& key) {
    return st[key];
}

std::string SymbolGraph::name(const int& v) {
    return keys[v];
}

Graph SymbolGraph::G() {
    return graph;
}


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
