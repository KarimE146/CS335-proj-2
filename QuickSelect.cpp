#include "QuickSelect.hpp"

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int pivot = *low; // Choose the leftmost element as the pivot
    auto i = low - nums.begin();
    auto j = high - nums.begin();

    while (true) {
        do {
            ++i;
        } while (nums[i] < pivot);

        do {
            --j;
        } while (nums[j] > pivot);

        if (i >= j) {
            return nums.begin() + j; // Return the pivot position
        }

        std::swap(nums[i], nums[j]);
    }
}

void quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (high - low > 0) {
        auto pivotPos = hoarePartition(nums, low, high);
        if (pivotPos > low) {
            quickSelectHelper(nums, low, pivotPos);
        }
        // Note: We exclude the pivot from the recursive call on the right side
        if (pivotPos + 1 < high) {
            quickSelectHelper(nums, pivotPos + 1, high);
        }else{
        std::sort(nums.begin(),nums.end());
        }
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    // Choose the median of three as the initial pivot
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

    quickSelectHelper(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

    return *middle; // Return the median
}

   // hoarePartition precondition: low points to the first element in the subnumsay to be partitioned. 
   //The pivot is the last element in the subnumsay to be partitioned, and is pointed to by high.
   // hoarePartition returns an iterator to the pivot after it's placed.
   //Note that this implementation of hoarePartition makes it usable with different pivot selection methods, 
   //but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.