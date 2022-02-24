//
//  LSD.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/15.
//

#include "LSD.hpp"

#include <vector>
#include <string>
#include <iostream>

void lsd_sort(std::vector<std::string> &arr) {
    if (arr.size() <= 1)
        return;
    int W = (int)arr[0].size();
    for (const std::string &str: arr) {
        assert(str.size() == W);
    }
    int R = 256;
    int N = (int)arr.size();
    std::vector<std::string> aux(N);
    for (int d = W - 1; d >= 0; --d) {
        std::vector<int> count(R+1);
        
        //  统计频率，count[i]统计的是字符i-1的频率
        for (const std::string &str: arr) {
            count[int(str[d])+1] += 1;
        }
        //  将频率转换成起始索引，转换后count[i]变成字符i的起始索引，count[i]=字符i-1的终止索引+1
        //  count[256]=字符255的终止索引+1，因为最大字符为255，所以count[256]是无用的
        for (int i = 0; i < R; ++i) {
            count[i+1] += count[i];
        }
        //  将元素分类
        for (const std::string &str: arr) {
            aux[count[int(str[d])]++] = str;
        }
        arr = aux;
    }
}


void LSD_test() {
    std::vector<std::string> arr = {
        "4PGC938",
        "2IYE230",
        "3CIO720",
        "1ICK750",
        "1OHV845",
        "4JZY524",
        "1ICK750",
        "3CI0720",
        "1OHV845",
        "1OHV845",
        "2RLA629",
        "2RLA629",
        "3ATW723"
    };
    lsd_sort(arr);
    for (const std::string &str: arr) {
        std::cout << str << std::endl;
    }
}
