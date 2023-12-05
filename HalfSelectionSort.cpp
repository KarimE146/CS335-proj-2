#include "HalfHeapSort.hpp"

int halfSelectionSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();

    if (nums.size() > 50000)
    {
        std::cout << "The input was too big for selection sort.";
    }else{

        for (int i = 0; i < (nums.size() /2) +1; i++)
        {
            int min = i;//sets min to be i whiich iterated through the vector
            
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[min])
                {
                    min = j;
                }
                std::swap(nums[min], nums[i]);
            }
             
            for (int x : nums){
                    std::cout << x << " ";
                } 
                    std::cout << "\n";
        }
    }
    



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
