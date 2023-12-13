#ifndef HalfHeapSort_HPP
#define HalfHeapSort_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


inline int leftChild(int i) {//access to left child
    return 2 * i;
}
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole){
    int size = heap.size();
    int child;
    int temp = heap[0];

    for(; leftChild(hole) < size; hole = child)
    {
        child = leftChild(hole);
        if (child  < size -1  && heap[child+1] < heap[child ])
            ++child;
        if (heap[child] < temp)
            heap[hole] = heap[child];
        else
            break;
    }
    heap[hole] = temp;
}

void buildHeap(std::vector<int>& heap) {
    for (int i = (heap.size() - 1) / 2; i > 0; --i) {
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start_time = std::chrono::high_resolution_clock::now();

    nums.push_back(nums[0]);
    buildHeap(nums);

    int split = ((nums.end() - nums.begin()) - 2) / 2;//gets the middle of the vector
    //splits the vector in half
    for(int i = 0; i < split; ++i){
      nums[0] = nums[nums.size() - 1];
      nums.pop_back();
      percDown(nums, 1);
   }

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    return nums[1];
}




//50492874

#endif
