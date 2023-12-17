#ifndef QuickSelect_HPP
#define QuickSelect_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "QuickSelect.hpp"

std::vector<int>::iterator medianOfThree(std::vector<int>& nums,std::vector<int>::iterator& low, std::vector<int>::iterator& high)
{
        auto middle = low + distance(low, high) / 2;

        if (nums.size() % 2 == 0)
            middle[(nums.size() / 2) - 1];

        if (*low < *middle && *middle < *high) {
        std::swap(*middle, *high);
    } else if (*high < *middle && *middle < *low) {
        std::swap(*middle, *high);
    } else if (*middle < *low && *low < *high) {
        std::swap(*low, *high);
    } else if (*high < *low && *low < *middle) {
        std::swap(*low, *high);
    }

    return high;
}


std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto median = medianOfThree(nums,low, high);
    std::iter_swap(median, high); 

    auto i = low ;
    auto j = high;

    while (true) {  
        
        while (i < j && *i < *median)
        {
            i++;
        }
        while (j > i && *j >= *median)
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }

        std::swap(*i, *j);
    }
    std::swap(*i, *high);
    return i;
}

int quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int mid)
{
    auto hoare = hoarePartition(nums, low, high); 
    int diff = std::distance(low, hoare);
    
    if (high - low >= 10)
    {
        if (diff == mid)
        {
            return *hoare; 
        }
        // If the difference is greater than the mid, then we know that the median is in the right side of the vector
        else if (diff > mid)
        {
            return quickSelectHelper(nums, low, hoare - 1, mid); 
        }
        // If the difference is less than the mid, then we know that the median is in the left side of the vector
        else
        {
            return quickSelectHelper(nums, hoare + 1, high, mid - diff - 1);
        }
        // If the difference is equal to the mid, then we know that the median is in the right side of the vector
    }else if (high - low < 10){
        std::sort(low, high + 1); 
        return *(low + mid); 
        //aorts if the size is < 10
    }
}


int quickSelect(std::vector<int>& nums, int& duration)
{
    auto start = std::chrono::high_resolution_clock::now(); 

    int mid = (nums.size() - 1) / 2;

    quickSelectHelper(nums, nums.begin(), nums.end() - 1, mid); 

    auto end = std::chrono::high_resolution_clock::now(); 
    auto time_lapse = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    duration = static_cast<int>(time_lapse.count()); 

    if (nums.size() % 2 == 0) {
        return nums[(nums.size() / 2) - 1];
    } else {
        return nums[nums.size() / 2];
    } // Return the median 
}
#endif
//50492874
//11 5 1 12 21 38 43 55 60 70 77 89 93 96 102 99 


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