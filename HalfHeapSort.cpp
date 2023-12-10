#include <chrono>
#include <vector>

// inline int leftChild(int i) {
//     return 2 * i + 1;
// }

// void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
//     int largest, l = (2*hole) + 1, r = l + 1;

//     if(l < heap.size() && heap[l] > heap[hole])
//         largest = l;
//     else
//         largest = hole;

//     if(r < heap.size() && heap[r] > heap[largest])
//         largest = r;

//     if(largest != hole)
//     {
//         std::swap(heap[hole], heap[largest]);
//         percDown(heap, largest);
//     }

// }

// void buildHeap(std::vector<int>& heap) {
//     for(int i = (heap.size() / 2); i >= 0; i--)
//     percDown(heap, i);
// }



// // Builds a max heap and removes n/2 elements
// int halfHeapSort(std::vector<int>& nums, int& duration) {
//     auto start = std::chrono::high_resolution_clock::now();

//     buildHeap(nums);
//     int sz = nums.size();
//     for(int i = nums.size() - 1; i > 0; i--)
//     {
//         std::swap(nums[0], nums[i]);
//         sz--;
//         percDown(nums, 0);
//     }
    

//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> diff = end - start;
//     duration = static_cast<int>(diff.count() * 1000);

//          if (nums.size() % 2 == 0 )
//     {
//         return nums[(nums.size() / 2) -1];
//     }else{
//         return nums[nums.size() / 2];
//     } // Return the median
// }

// 102, 99, 70. 77, 96, 1, 60, 12, 5, 21 
//99 96 70 60 21 1 77 12 5 102 

//96 60 70 12 21 99 77 1 5 102 
//96 60 70 12 21 99 77 1 5 102 
//



void percDown(std::vector<int>& heap, int hole, int size){
    int temp = std::move(heap[hole]);

    // Perc down
    while (hole * 2 + 1 < size)
    {
        // Left child
        int child = hole * 2 + 1;

        // Right child
        if (child != size - 1 && heap[child] > heap[child + 1])
        {
            ++child; // Right child if larger
        }

        // Swap if child is smaller than temp
        if (heap[child] < temp)
        {
            heap[hole] = std::move(heap[child]);
            hole = child;
        }

        else
        {
            break;
        }
    }

    // Insert temp into the hole
    heap[hole] = std::move(temp);
}

void buildHeap(std::vector<int>& heap){
    int size = heap.size();

    // Build the heap
    for (int i = (size - 2) / 2; i >= 0; --i)
    {
        percDown(heap, i, size);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration){
    auto start_time = std::chrono::high_resolution_clock::now(); 

    // Move the first element to the end
    nums.push_back(std::move(nums[0]));
    nums.erase(nums.begin());

    // Perform partial heapsort to get bottom n/2 elements in ascending order
    buildHeap(nums);

    int size = nums.size(); 

    // Delete the bottom n/2 elements
    while (size > (nums.size() / 2 + 1))
    {
        std::swap(nums[0], nums[size - 1]);
        --size;
        percDown(nums, 0, size);
    }

    // Resize the vector to half its original size
    nums.resize(nums.size() / 2 + 1);
    auto end_time = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // Median is at the root of the remaining heap
    int median = nums[0];
    return median;
}