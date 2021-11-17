//
//  EdgeWeightedGraph.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/11/14.
//

#ifndef EdgeWeightedGraph_hpp
#define EdgeWeightedGraph_hpp

#include <stdio.h>

#include <stdexcept>
#include <vector>

class Edge {
public:
    Edge() = default;
    Edge(int v_, int w_, float wiehgt_)
    :v(v_), w(w_), weight(wiehgt_){}
    int either() const {
        return v;
    }
    int other(int vertex) const {
        if (vertex == v)
            return w;
        else if (vertex == w)
            return v;
        else
            throw std::runtime_error("inconsistent edge");
    }
    float get_weight() const {
        return weight;
    }
private:
    int v = 0;
    int w = 0;
    float weight = 0.0;
};

struct cmp {
    bool operator ()(const Edge& l, const Edge& r) {
        return l.get_weight() > r.get_weight();
    }
};

class EdgeWeightedGraph {
public:
    EdgeWeightedGraph(int V_);
    int get_V() const;
    int get_E() const;
    std::vector<Edge> get_adj(int v) const;
    void add_edge(const Edge& e);
private:
    int V;
    int E;
    std::vector<std::vector<Edge>> adj;
};

#endif /* EdgeWeightedGraph_hpp */
