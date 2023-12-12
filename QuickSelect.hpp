#ifndef QuickSelect_HPP
#define QuickSelect_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

std::vector<int>::iterator medianOfThree(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto center = low + std::distance(low, high) / 2;

    if (*center < *low)
        std::swap(*low, *center);
    if (*high < *low)
        std::swap(*low, *high);
    if (*high < *center)
        std::swap(*center, *high);

    // Swap the median into the last position without ordering the three
    std::swap(*center, *(high - 1));

    return high - 1;
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int pivot = *high; 
    auto i = low;
    auto j = high - 1;

    while (true) {
        while (*i < pivot && i < high) {
            ++i;
        }
        while (*j > pivot && j > low) {
            --j;
        }

        if (i >= j) {
            std::swap(*i, *high);
            return i;
        }

        std::swap(*i, *j);
    }
}

void quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (high - low > 10) {
        auto mid = low + (high - low) / 2;
        std::swap(*mid, *high);
        auto pivotPos = hoarePartition(nums, low, high);

        quickSelectHelper(nums, low, pivotPos - 1);
        quickSelectHelper(nums, pivotPos, high);
    } else {
        std::sort(low, high + 1);
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    quickSelectHelper(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

    if (nums.size() % 2 == 0) {
        return nums[(nums.size() / 2) - 1];
    } else {
        return nums[nums.size() / 2];
    }
}

#endif