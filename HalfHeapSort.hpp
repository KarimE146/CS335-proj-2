#ifndef HalfHeapSort_HPP
#define HalfHeapSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// 12 5 1 99 21 70 60 77 102 96 55 43 93 38 89 11 
// 55
// 55 70 60 89 99 93 77 102 96 
inline int leftChild(int i) {
    return 2 * i + 1;
}
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    int temp = std::move(heap[hole]);

    while (hole * 2 + 1 < heap.size()) {
        std::vector<int>::size_type child = hole * 2 + 1;
        if (child != heap.size() - 1 && heap[child] > heap[child + 1]) {
            ++child;
        }
        if (heap[child] < temp) {
            heap[hole] = std::move(heap[child]);
            hole = child;
        } else {
            break;
        }
    }

    heap[hole] = std::move(temp);
}

void buildHeap(std::vector<int>& heap) {
    for (int i = (heap.size() - 2) / 2; i >= 0; --i) {
        percDown(heap, i);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start_time = std::chrono::high_resolution_clock::now();

    nums.push_back(std::move(nums[0]));
    nums.erase(nums.begin());

    buildHeap(nums);

    while (nums.size() > (nums.size() / 2 + 1)) {
        std::swap(nums[0], nums[nums.size() - 1]);
        nums.pop_back();
        percDown(nums, 0);
    }

    nums.resize(nums.size() / 2 + 1);

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    return nums[0];
}



// 102, 99, 70. 77, 96, 1, 60, 12, 5, 21 
//99 96 70 60 21 1 77 12 5 102 

//96 60 70 12 21 99 77 1 5 102 
//96 60 70 12 21 99 77 1 5 102 
//



// void percDown(std::vector<int>& heap, int hole, int size){
//     int temp = std::move(heap[hole]);

//     // Perc down
//     while (hole * 2 + 1 < size)
//     {
//         // Left child
//         int child = hole * 2 + 1;

//         // Right child
//         if (child != size - 1 && heap[child] > heap[child + 1])
//         {
//             ++child; // Right child if larger
//         }

//         // Swap if child is smaller than temp
//         if (heap[child] < temp)
//         {
//             heap[hole] = std::move(heap[child]);
//             hole = child;
//         }

//         else
//         {
//             break;
//         }
//     }

//     // Insert temp into the hole
//     heap[hole] = std::move(temp);
// }

// void buildHeap(std::vector<int>& heap){
//     int size = heap.size();

//     // Build the heap
//     for (int i = (size - 2) / 2; i >= 0; --i)
//     {
//         percDown(heap, i, size);
//     }
// }

// int halfHeapSort(std::vector<int>& nums, int& duration){
//     auto start_time = std::chrono::high_resolution_clock::now(); 

//     // Move the first element to the end
//     nums.push_back(std::move(nums[0]));
//     nums.erase(nums.begin());

//     // Perform partial heapsort to get bottom n/2 elements in ascending order
//     buildHeap(nums);

//     int size = nums.size(); 

//     // Delete the bottom n/2 elements
//     while (size > (nums.size() / 2 + 1))
//     {
//         std::swap(nums[0], nums[size - 1]);
//         --size;
//         percDown(nums, 0, size);
//     }

//     // Resize the vector to half its original size
//     nums.resize(nums.size() / 2 + 1);
//     auto end_time = std::chrono::high_resolution_clock::now();

//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

//     // Median is at the root of the remaining heap
//     int median = nums[0];
//     return median;
// }



//50492874

#endif
