#ifndef QuickSelect_HPP
#define QuickSelect_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

std::vector<int>::iterator medianOfThree(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    std::vector<int>::iterator mid = low + std::distance(low, high) / 2;
    if (*low > *mid)
        std::iter_swap(low, mid);
    if (*low > *high)
        std::iter_swap(low, high);
    if (*mid > *high)
        std::iter_swap(mid, high);
    return mid;
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto pivot = high; 
    auto i = low + 1;
    auto j = high - 1;

    while (true) {
        while (i < pivot) {
            ++i;
        }
        while (j > pivot) {
            --j;
        }

        if (i >= j) {
            std::iter_swap(i, j);
            return i;
        }

        std::swap(*i, *j);
        //std::cout << *low<< " " << pivot << " " << *high << " "<< std::endl;
    }
}

void quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (high - low > 10) {
        auto pivot = medianOfThree(nums, low, high);
        std::swap(*pivot, *high); // Move pivot to end for partitioning
       
        auto splitPoint = hoarePartition(nums, low, high);

        quickSelectHelper(nums, low, splitPoint - 1);
        quickSelectHelper(nums, splitPoint , high);
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