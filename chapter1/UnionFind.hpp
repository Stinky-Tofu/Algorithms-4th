//
//  UnionFind.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/27.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include <vector>

class UnionFind{
public:
    UnionFind(const int& N);
    int Find(const int& ele);
    void Union(const int& ele0, const int& ele1);
    int getCount();
    bool isConnect(const int& ele0, const int& ele1);
private:
    std::vector<int> arr;
    std::vector<int> sz;
    int count;
};

void testUF();

#endif /* UnionFind_hpp */
