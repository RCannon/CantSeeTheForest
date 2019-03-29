CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -g

all: test_htree

test_htree: test_htree.o htree.o hforest.o
	$(CXX) $(CXXFLAGS) -o test_htree test_htree.o htree.o hforest.o

test_htree.o: test_htree.cc htree.hh hforest.hh
	$(CXX) $(CXXFLAGS) -c test_htree.cc

htree.o: htree.cc htree.hh
	$(CXX) $(CXXFLAGS) -c htree.cc

hforest.o: hforest.cc hforest.hh
	$(CXX) $(CXXFLAGS) -c hforest.cc
	
clean:
	rm -rf *.o test_htree
