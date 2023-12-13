#ifndef QuickSelect_HPP
#define QuickSelect_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "QuickSelect.hpp"

std::vector<int>::iterator medianOfThree(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    // auto mid = low + (high - low) / 2;

    // if (*low > *mid)
    //     std::iter_swap(low, mid);
    // if (*low > *high)
    //     std::iter_swap(low, high);
    // if (*mid > *high)
    //     std::iter_swap(mid, high);

    // std::iter_swap(mid, high - 1);
    // return high - 1;
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto pivot = medianOfThree(nums, low, high);

    auto i = low - 1;
    auto j = high;

    while (true) {
        do {
            ++i;
        } while (*(i) < (*pivot));
        do {
            --j;
        } while (*(j) > (*pivot));

        if (i >= j) {
            return j;
        }

        std::iter_swap(i, j);
    }
}

void quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    // if (low + 10 < high) {
    //     const auto piv = hoarePartition(nums, low, high);

    //     std::iter_swap(piv, high - 1);

    //     quickSelectHelper(nums, low, piv - 1);
    //     quickSelectHelper(nums, piv + 1, high);
    // }else {
    //     std::sort(low, high);
    // }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    // auto start = std::chrono::high_resolution_clock::now();

    // quickSelectHelper(nums, nums.begin(), nums.end() - 1);

    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double> diff = end - start;
    // duration = static_cast<int>(diff.count() * 1000);

    // if (nums.size() % 2 == 0) {
    //     return nums[(nums.size() / 2) - 1];
    // } else {
    //     return nums[nums.size() / 2];
    // }
}
#endif


// Implement a quickselect algorithm, which works like a quicksort, except that after partitioning your array into the part that's less than your pivot and the part that's 
// greater than your pivot, you only recurse on one side instead of both. To pick your pivot, use the "median of 3" method, which looks at the first, middle, and last 
// element and picks the median of them as your pivot. Your quick select should be in-place.
// Details: For pivot selection, use the median of 3 method. This method takes the first element, last element, and middle element (or left-middle element if there are an 
// even number of elements) and chooses the median of those as the pivot. If two or three of these share the same value, make the leftmost one your pivot.
// For partitioning, use the Hoare partition method, as described in textbook section 7.7.2. Swap values that are equal to the pivot (this prevents turning an 
// input of identical values into a worst-case scenario). Consider edge cases, and make sure your iterators don't go out of bounds in any case.
// Keep in mind for Quickselect that once the pivot is placed, you recurse on one side of the pivot, not including the pivot (which is already in its correct position).
// hoarePartition will assume that the pivot is already in place, at the end of the subarray to be partitioned. Thus, you must swap your pivot into position before calling hoarePartition. A helper function for pivot selection and placement is advisable.
// Recursive base case: once your subarray size reaches 10 or less, use std::sort to sort it all rather than recursively calling QuickSelect.

// After meeting with student during office hours, there are some issues for project 2 that keep coming up:

// 1) For heapsort's percDown, as per the precondition, the value to be placed in the hole should be at index 0. This means you should not be moving the contents of the 
// hole into position 0 in percDown. The reason for this is that when using percDown in buildHeap, the value to place is the value that starts in the hole, but when using 
// percDown for deleteMin, the hole is at index 1, but the value to be placed is at the end of the vector. Thus, the project specifications provide a consistent interface 
// that works in both situations.

// 2) Likewise, for hoarePartition, the specification is that the pivot should already be in the end position before hoarePartition is called, rather than being swapped 
// into place within hoarePartition.

// 3) Median of 3 does not follow the textbook implementation. My specifications are to identify the median of the low, middle, and high elements, then swap the median 
// into the "high" index. This is different from the textbook, which sorts all 3 then swaps.