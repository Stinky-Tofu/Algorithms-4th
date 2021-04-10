//
//  UnionFind.cpp
//  code
//
//  Created by StinkyTofu on 2021/3/27.
//

#include "UnionFind.hpp"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "utils.hpp"

//  最简单的并查集实现，时间复杂度为O(N^2)
//UnionFind::UnionFind(const int& N): arr(N, 0), count(N){
//    for(int i = 0; i < arr.size(); ++i){
//        arr[i] = i;
//    }
//}
//
//int UnionFind::Find(const int &ele){
//    return arr[ele];
//}
//
//void UnionFind::Union(const int &ele0, const int &ele1){
//    int set0 = Find(ele0);
//    int set1 = Find(ele1);
//    if (set0 == set1){
//        return;
//    }
//    for (int& set: arr)
//        if (set == set0){
//            set = set1;
//    }
//    --count;
//}

//  quick-Union的并查集实现，时间复杂度为O(N^2)
//UnionFind::UnionFind(const int& N): arr(N, 0), count(N){
//    for(int i = 0; i < arr.size(); ++i){
//        arr[i] = i;
//    }
//}
//
//int UnionFind::Find(const int &ele){
//    if (ele == arr[ele]){
//        return ele;
//    }
//    return Find(arr[ele]);
//}
//
//void UnionFind::Union(const int &ele0, const int &ele1){
//    int set0 = Find(ele0);
//    int set1 = Find(ele1);
//    if (set0 == set1){
//        return;
//    }
//    arr[set0] = set1;
//    --count;
//}

////  加权quick-Union的并查集实现，时间复杂度为O(NlgN)
//UnionFind::UnionFind(const int& N): arr(N, 0), sz(N, 1), count(N){
//    for(int i = 0; i < arr.size(); ++i){
//        arr[i] = i;
//    }
//}
//
//int UnionFind::Find(const int &ele){
//    if (ele == arr[ele]){
//        return ele;
//    }
//    return Find(arr[ele]);
//}
//
//void UnionFind::Union(const int &ele0, const int &ele1){
//    int set0 = Find(ele0);
//    int set1 = Find(ele1);
//    if (set0 == set1){
//        return;
//    }
//    if (sz[set0] < sz[set1]){
//        arr[set0] = set1;
//        sz[set1] += sz[set0];
//    }else{
//        arr[set1] = set0;
//        sz[set0] += sz[set1];
//    }
//    --count;
//}

//  并查集的最优实现，时间复杂度≈O(N)
UnionFind::UnionFind(const int& N): arr(N, 0), sz(N, 1), count(N){
    for(int i = 0; i < arr.size(); ++i){
        arr[i] = i;
    }
}

int UnionFind::Find(const int &ele){
    if (ele == arr[ele]){
        return ele;
    }
    arr[ele] = Find(arr[ele]);
    return arr[ele];
}

void UnionFind::Union(const int &ele0, const int &ele1){
    int set0 = Find(ele0);
    int set1 = Find(ele1);
    if (set0 == set1){
        return;
    }
    if (sz[set0] < sz[set1]){
        arr[set0] = set1;
        sz[set1] += sz[set0];
    }else{
        arr[set1] = set0;
        sz[set0] += sz[set1];
    }
    --count;
}

bool UnionFind::isConnect(const int &ele0, const int &ele1){
    return Find(ele0) == Find(ele1);
}

int UnionFind::getCount(){
    return count;
}

void testUF(){
    std::ifstream file("/Users/apple/Documents/code/algorithm/algs4-data/mediumUF.txt");
    std::string NStr;
    std::getline(file, NStr);
    int N = std::atoi(NStr.data());
    std::string line;
    UnionFind uf(N);
    int unionCount = 0;
    long long now = systemtime();
    while (std::getline(file, line)) {
        std::vector<std::string> dataStrVec;
        splitStr(line, dataStrVec);
        int val0 = std::atoi(dataStrVec[0].data());
        int val1 = std::atoi(dataStrVec[1].data());
        if (uf.isConnect(val0, val1)){
            continue;
        }
        uf.Union(val0, val1);
        std::cout << val0 << " union " << val1 << std::endl;
        ++unionCount;
    }
    std::cout << uf.getCount() << " components" << std::endl;
    std::cout << unionCount << " connected" << std::endl;
    std::cout << systemtime() - now << " ms" << std::endl;
}
