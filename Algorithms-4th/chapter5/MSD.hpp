//
//  MSD.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/23.
//

#ifndef MSD_hpp
#define MSD_hpp

#include <stdio.h>

#include <vector>
#include <string>


void MSD_sort(std::vector<std::string> &arr);
void sort(std::vector<std::string> &arr,
          const int &low,
          const int &high,
          const int &d);
void MSD_test();

#endif /* MSD_hpp */
