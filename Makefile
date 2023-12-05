CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List of source files (add more as needed)
SRCS = main.cpp HalfSelectionSort.cpp StandardSort.cpp MergeSort.cpp InPlaceMergeSort.cpp HalfHeapSort.cpp QuickSelect.cpp WorstCaseQuickSelect.cpp MedianOfMediansMethod.cpp

# List of header files (add more as needed)
HDRS = HalfSelectionSort.hpp StandardSort.hpp MergeSort.hpp InPlaceMergeSort.hpp HalfHeapSort.hpp QuickSelect.hpp WorstCaseQuickSelect.hpp MedianOfMediansMethod.hpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
rebuild: clean all
