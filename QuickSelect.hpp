#ifndef QuickSelect_HPP
#define QuickSelect_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

#include "QuickSelect.hpp"

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int pivot = *low; 
    auto i = low - nums.begin();
    auto j = high - nums.begin();

    // we have to use Itr's so thats how we get the inciced for the first and last

    while (true) {
        do {
            ++i;
        } while (nums[i] < pivot);

        do {
            --j;
        } while (nums[j] > pivot);

        if (i >= j) {
            return nums.begin() + j; 
        }

        std::iter_swap(nums.begin() + i, nums.begin() + j);
    }
}

void quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (high - low > 10) {
        auto pivotPos = hoarePartition(nums, low, high);
        if (pivotPos > low) {
            quickSelectHelper(nums, low, pivotPos);
        }

        if (pivotPos + 1 < high) {
            quickSelectHelper(nums, pivotPos + 1, high);
        }
    } else {
        std::sort(nums.begin(), nums.end());
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    auto middle = nums.begin() + nums.size() / 2;
    if (*middle < *nums.begin()) {
        std::swap(*middle, *nums.begin());
    }
    if (*(nums.end() - 1) < *nums.begin()) {
        std::swap(*(nums.end() - 1), *nums.begin());
    }
    if (*middle < *(nums.end() - 1)) {
        std::swap(*middle, *(nums.end() - 1));
    }
    //median of 3 method^

    quickSelectHelper(nums, nums.begin(), nums.end());


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
