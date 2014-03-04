#Graph library
$(CXX) = g++

all:	Graph

Graph:	graphNode.o main.o
	$(CXX) main.o graphNode.o -o graph.bin

graphNode.o:	graphNode.cpp graphNode.h
	$(CXX) -c graphNode.cpp 

main.o:	main.cpp
	$(CXX) -c main.cpp

clean:
	rm -rf *.o graph.bin

clean_o:
	rm -rf *.o 
