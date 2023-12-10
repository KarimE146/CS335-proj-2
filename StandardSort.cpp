#include "StandardSort.hpp"

int standardSort(std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(nums.begin(),nums.end()); 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);  // Convert to milliseconds

        
    if (nums.size() % 2 == 0 )
    {
        return nums[(nums.size() / 2) -1];
    }else{
        return nums[nums.size() / 2];
    } // Return the median

}