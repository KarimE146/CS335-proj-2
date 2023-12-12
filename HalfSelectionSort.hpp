#ifndef HalfSelectionSort_HPP
#define HalfSelectionSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    int count = 0;
    auto start = std::chrono::high_resolution_clock::now();

    if (nums.size() > 50000) {
        std::cout << "The input was too big for selection sort.";
    } else {
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            auto min = i; // sets min to be i which iterated through the vector

            if (count == (nums.size()/2) + (nums.size()%2))
            {
                break;
            }
            

            for (auto j = i + 1; j != nums.end(); ++j) {
                if (*j < *min) {
                    min = j;
                }
            }
            std::swap(*i, *min);
            count++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000); // Convert to milliseconds

    if (nums.size() % 2 == 0) {
        return *std::next(nums.begin(), (nums.size() / 2) - 1);
    } else {
        return *std::next(nums.begin(), nums.size() / 2);
    } // Return the median
}
#endif