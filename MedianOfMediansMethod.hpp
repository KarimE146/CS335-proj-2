#ifndef MedianOfMediansMethod_HPP
#define MedianOfMediansMethod_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/*Update: Median of medians will be hand-graded and your vector after the algorithm finishes does not need to exactly match my end result, 
/but in order for your submission to qualify for grading, you must meet the following requirements:
- You completed QuickSelect
- Your median of medians runs on the autograder and returns the correct median.
- Your time for median of medians is within the expected range (which will be very broad).
*/
//For maximum points, must also have a function called "medianOfFive" that calculates the median of 5 numbers in 6 comparisons, as we went over in class.
//Note that median of medians is a pivot selection method. For partitioning, you'll use Hoare's partition again.

int medianOfMediansMethod ( std::vector<int>& nums, int& duration );
int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high );
   // returns the median of medians of all elements contained between high and low, inclusive.


#endif
