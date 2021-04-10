//
//  utils.hpp
//  code
//
//  Created by StinkyTofu on 2021/3/13.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <string>
#include <vector>

void splitStr(const std::string& str,
              std::vector<std::string>& result,
              const std::string& delimeters = " ");
long long systemtime();
#endif /* utils_hpp */
