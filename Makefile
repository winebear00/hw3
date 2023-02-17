CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS=llrec.o 
all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

llrec.o: llrec.cpp llrec-test.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ llrec-test.cpp 

stack.o: stack.h stack_tests.cpp
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ 

heap.o: heap.h heap_tests.cpp
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ 

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 