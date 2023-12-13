#ifndef HalfHeapSort_HPP
#define HalfHeapSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


inline int leftChild(int i) {
    return 2 * i + 1;
}
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    int size = heap.size();
    int child;
    int temp;

    for (temp = std::move(heap[hole]); leftChild(hole) < size; hole = child)
    {
        child = leftChild(hole);
        if (child != size - 1 && heap[child] < heap[child + 1])
            ++child;
        if (heap[child] > temp)
            heap[hole] = std::move(heap[child]);
        else
            break;
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

    // Move the first element to the back
    nums.push_back(std::move(nums[0]));
    nums.erase(nums.begin());

    // Adjust the size for the upcoming buildHeap
    int originalSize = nums.size();
    int newSize = (originalSize / 2) + 1;
    nums.resize(newSize);

    // Build the heap on the first half of the vector
    buildHeap(nums);

    // Continue with the remaining steps of halfHeapSort
    while (nums.size() > newSize) {
        std::swap(nums[0], nums[nums.size() - 1]);
        nums.pop_back();
        percDown(nums, 0);
    }

    // Restore the original size after sorting
    nums.resize(originalSize);

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    return nums[0];
}




//50492874

#endif
