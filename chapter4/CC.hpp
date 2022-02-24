//
//  CC.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2021/10/13.
//

#ifndef CC_hpp
#define CC_hpp

#include <stdio.h>

#include "Graph.hpp"

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

void CC_test();

#endif /* CC_hpp */
