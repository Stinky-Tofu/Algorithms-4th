//
//  Search.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/2/13.
//

#include "Search.hpp"

#include <string>
#include <iostream>

size_t sub_str_search(const std::string &txt, const std::string &pat) {
    const size_t &N = txt.length();
    const size_t &M = pat.length();
    for (size_t i = 0; i <= N - M; ++i) {
        size_t j = 0;
        for (; j < M; ++j) {
            if (txt[i+j] != pat[j]) break;
        }
        if (j == M) return i;
    }
    return N;
}

size_t sub_str_search2(const std::string &txt, const std::string &pat) {
    const size_t &N = txt.length();
    const size_t &M = pat.length();
    size_t i = 0;
    size_t j = 0;
    for (; i < N && j < M; ++i) {
        if (txt[i] == pat[j]) {
            ++j;
        }
        else {
            i -= j;
            j = 0;
        }
    }
    if (j == M) return i - j;
    return N;
}


void sub_str_search_test() {
    std::string txt = "hellotextc++python";
    std::string pat = "text";
    std::cout << sub_str_search(txt, pat) << std::endl;
    std::cout << sub_str_search2(txt, pat) << std::endl;
    return;
}
