#include <chrono>
#include <vector>

inline int leftChild(int i) {
    return 2 * i + 1;
}

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    int largest, l = (2*hole) + 1, r = l + 1;

    if(l < heap.size() && heap[l] > heap[hole])
        largest = l;
    else
        largest = hole;

    if(r < heap.size() && heap[r] > heap[largest])
        largest = r;

    if(largest != hole)
    {
        std::swap(heap[hole], heap[largest]);
        percDown(heap, largest);
    }

}

void buildHeap(std::vector<int>& heap) {
    for(int i = (heap.size() / 2); i >= 0; i--)
    percDown(heap, i);
}



// Builds a max heap and removes n/2 elements
int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    buildHeap(nums);
    int sz = nums.size();
    for(int i = nums.size() - 1; i > 0; i--)
    {
        std::swap(nums[0], nums[i]);
        sz--;
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

// 102, 99, 70. 77, 96, 1, 60, 12, 5, 21 
//99 96 70 60 21 1 77 12 5 102 

//96 60 70 12 21 99 77 1 5 102 
//96 60 70 12 21 99 77 1 5 102 
//