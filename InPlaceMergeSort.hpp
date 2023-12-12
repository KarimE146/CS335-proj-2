#ifndef InPlaceMergeSort_HPP
#define InPlaceMergeSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>

void inPlaceMergeSortRecursive(std::vector<int>& nums, std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if (start < end - 1) {
        auto mid = start + std::distance(start, end) / 2;
        inPlaceMergeSortRecursive(nums, start, mid); 
        inPlaceMergeSortRecursive(nums, mid, end);   
        std::inplace_merge(start, mid, end);    
    }
}


int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    inPlaceMergeSortRecursive(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

     if (nums.size() % 2 == 0 )
    {
        return nums[(nums.size() / 2) -1];
    }else{
        return nums[nums.size() / 2];
    } // Return the median
}

#endif
