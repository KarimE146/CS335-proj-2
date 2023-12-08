#include "HalfHeapSort.hpp"
inline std::vector<int>::size_type leftChild(std::vector<int>::size_type i) {
    return 2 * i + 1;
}

int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    // Move the first element to the end of the vector
    std::swap(nums[0], nums[nums.size() - 1]);

    // Build heap
    buildHeap(nums);

    // Delete n/2 elements from the heap
    for (int j = nums.size() - 1; j > nums.size() / 2; --j) {
        std::swap(nums[0], nums[j]);
        percDown(nums, 0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

     if (nums.size() % 2 == 0 )
    {
        return nums[(nums.size() / 2) -1];
    }else{
        return nums[nums.size() / 2];
    } // Return the median
}
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    std::vector<int>::size_type child;
    int tmp = std::move(heap[hole]);

    for (; leftChild(hole) < heap.size(); hole = child) {
        child = leftChild(hole);
        if (child != heap.size() - 1 && heap[child] < heap[child + 1])
            ++child;
        if (tmp < heap[child])
            heap[hole] = std::move(heap[child]);
        else
            break;
    }
    heap[hole] = std::move(tmp);
}
   // parameter "hole" is the index of the hole.
   // percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
   // percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void buildHeap(std::vector<int>& heap) {
    for (int i = heap.size(); i >= 0; --i) {
        percDown(heap, i);
    }
}

