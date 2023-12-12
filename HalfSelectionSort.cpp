#include "HalfSelectionSort.hpp"

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    if (nums.size() > 50000) {
        std::cout << "The input was too big for selection sort.";
    } else {
        for (auto i = nums.begin(); i != nums.begin() + (nums.size() / 2) +1; ++i) {
            auto min = i; // sets min to be i which iterated through the vector

            for (auto j = i + 1; j != nums.end(); ++j) {
                if (*j < *min) {
                    min = j;
                }
            }
            std::iter_swap(min, i);
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


