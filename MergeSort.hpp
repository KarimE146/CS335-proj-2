#ifndef MergeSort_HPP
#define MergeSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>



void mergeSortRecursive(std::vector<int>& nums, std::vector<int>& sorted) {
    int size = nums.size();

    if (size <= 1) {
        sorted = nums;  
        return;
    }

    int middle = size / 2;
    std::vector<int> left(nums.begin(), nums.begin() + middle);
    std::vector<int> right(nums.begin() + middle, nums.end());
    std::vector<int> sortedLeft, sortedRight;

    mergeSortRecursive(left, sortedLeft);
    mergeSortRecursive(right, sortedRight);
    sorted.clear(); 
    std::merge(sortedLeft.begin(), sortedLeft.end(), sortedRight.begin(), sortedRight.end(), std::back_inserter(sorted));

    nums.clear();  // Clear the original vector
    // Merge sortedLeft and sortedRight into nums
    std::merge(sortedLeft.begin(), sortedLeft.end(), sortedRight.begin(), sortedRight.end(), std::back_inserter(nums));
}


int mergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> temp(nums.size());
    mergeSortRecursive(nums,temp);

    

    // for (int x : temp){
    //     std::cout << x << " ";
    // }
    // std::cout << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);
    if (temp.size() % 2 == 0 )
    {
        return temp[(temp.size() / 2) -1];
    }else{
        return temp[temp.size() / 2];
    }
}
#endif
