#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "MedianOfMediansMethod.hpp"
#include "QuickSelect.hpp"

int main() {
    //Read input from file into vector
    std::vector<int> nums;
    int num;
    std::ifstream inputFile("input1.txt");

    if (inputFile.is_open()) {
        while (inputFile >> num) {
            nums.push_back(num);
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input file.\n";
        return 1;
    }


   int duration;

    //Make a copy of the original vector
    std::vector<int> numsCopy = nums;

    int qs = halfHeapSort(numsCopy, duration);

    
    if (qs != -1) {
        std::cout << "Median found by HS: " << qs << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    for (int x : numsCopy)
    {
        std::cout << x << " ";
    }
    

//     std::vector<int> vect;
 
//     vect.push_back(12);
//     vect.push_back(5);
//     vect.push_back(1);
//     vect.push_back(99);
//     vect.push_back(21);
//     vect.push_back(70);
//     vect.push_back(60);
//     vect.push_back(77);
//     vect.push_back(102);
//     vect.push_back(96);
//     vect.push_back(55);
//     vect.push_back(43);
//     vect.push_back(93);
//     vect.push_back(38);
//     vect.push_back(89);
//     vect.push_back(11);

 
//     for (int x : vect){
//         std::cout << x << " ";
//     }
//     std::cout << "\n";
 
//     int i;
//     std::cout << quickSelect(vect,i);
//     std::cout << "\n";

//     for (int x : vect){
//         std::cout << x << " ";
//     }
//     std::cout << "\n";


//     return 0;
}



//50492874