#ifndef WorstCaseQuickSelect_HPP
#define WorstCaseQuickSelect_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int> worstCaseQuickSelect (void){
    std::vector<int> nums;
    for (int i = 20000; i >=1; i--){
        nums.push_back(i);
    }
    return nums;
}
#endif
