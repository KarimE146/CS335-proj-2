#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"
#include "MedianOfMediansMethod.hpp"

#include <chrono>

int main() {
    // Your testing logic goes here
    // Create vectors, test each sorting function, measure duration, and print results
    std::vector<int> vect;
 
    vect.push_back(12);
    vect.push_back(5);
    vect.push_back(1);
    vect.push_back(99);
    vect.push_back(21);
    vect.push_back(70);
    vect.push_back(60);
    vect.push_back(77);
    vect.push_back(102);
    vect.push_back(96);
    // vect.push_back(34);

 
    for (int x : vect){
        std::cout << x << " ";
    }
    std::cout << "\n";
 
    int i;
    std::cout << standardSort(vect,i);
    std::cout << "\n";

    return 0;
}
