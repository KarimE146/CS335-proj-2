CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List of header files (add more as needed)
HDRS = HalfSelectionSort.hpp StandardSort.hpp MergeSort.hpp InPlaceMergeSort.hpp HalfHeapSort.hpp QuickSelect.hpp WorstCaseQuickSelect.hpp MedianOfMediansMethod.hpp

# List of source files (add more as needed)
SRCS = $(wildcard *.cpp)

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

.PHONY: all clean rebuild

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Rule to build object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

rebuild: clean all
