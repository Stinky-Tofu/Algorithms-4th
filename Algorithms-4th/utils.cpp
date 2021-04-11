//
//  utils.cpp
//  code
//
//  Created by StinkyTofu on 2021/3/13.
//

#include "utils.hpp"

#include <string>
#include <vector>
#include<sys/timeb.h>
#include <iostream>

long long systemtime()
{
    timeb t;
    ftime(&t);
    return t.time*1000+t.millitm;
}

void splitStr(const std::string& str,
              std::vector<std::string>& result,
              const std::string& delimeters){
    std::string::size_type lastPos = str.find_first_not_of(delimeters, 0);
    std::string::size_type pos = str.find_first_of(delimeters, lastPos);
    while (std::string::npos != lastPos || std::string::npos != pos) {
        result.emplace_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimeters, pos);
        pos = str.find_first_of(delimeters, lastPos);
    }
}
