//
//  Graph.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/9/19.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

#include <vector>
#include <map>

class Graph {
public:
    Graph() = default;
    Graph(const int& _V);
    int get_V() const;
    int get_E() const;
    std::vector<int> get_adj(const int& v) const;
    void add_edge(const int& v, const int& w);

private:
    int V = 0;
    int E = 0;
    std::vector<std::vector<int>> adj;
};

class Search {
public:
    Search(Graph g, const int& s);
    int get_count() const;
    bool is_masked(const int& v) const;
    virtual void search(const Graph& g, const int& v);
    std::vector<int> path_to(const int& v);
    bool has_path_to(const int& v);
    
protected:
    std::vector<bool> masked = {};
    std::vector<int> edge_to = {};
    int count = 0;
    int start = 0;
};

class DepthFirstSearch: public Search {
public:
    DepthFirstSearch(Graph g, const int& s)
    : Search(g, s){};
    void search(const Graph& g, const int& v);
};

class BreadFirstSearch: public Search {
public:
    BreadFirstSearch(Graph g, const int& s)
    : Search(g, s){};
    void search(const Graph& g, const int& v);
};

class CC {
public:
    CC(Graph g);
    bool is_connected(const int& u, const int& w) const;
    int get_count() const;
    int get_id(const int& v) const;
private:
    void DFS(const Graph& g, const int& v);
    std::vector<bool> masked = {};
    std::vector<int> id = {};
    int count = 0;
};


class SymbolGraph {
public:
    SymbolGraph(const std::string& file_path, const std::string& delim);
    bool contain(const std::string& key);
    int index(const std::string& key);
    std::string name(const int& v);
    Graph G();
private:
    Graph graph;
    std::map<std::string, int> st;
    std::vector<std::string> keys;
};

class Cycle {
public:
    Cycle(const Graph& g);
    bool is_has_cycle();
private:
    void DFS(const Graph& g, const int& v, const int& u);
    std::vector<bool> masked = {};
    bool has_cycle = false;
};

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

#endif /* Graph_hpp */
