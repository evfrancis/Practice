#Graph library
CXX = g++
CFLAGS= -g

all:	Graph

Graph:	graphNode.o main.o
	$(CXX) $(CFLAGS) main.o graphNode.o -o graph.bin

graphNode.o:	graphNode.cpp graphNode.h
	$(CXX) $(CFLAGS) -c graphNode.cpp 

main.o:	main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o graph.bin

clean_o:
	rm -rf *.o 
