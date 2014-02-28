#Graph library
$(CXX) = g++

all:	Graph

Graph:	graphNode.o main.o
	$(CXX) main.o graphNode.o -o graph.executable

graphNode.o:	graphNode.cpp
	$(CXX) -c graphNode.cpp 

main.o:	main.cpp
	$(CXX) -c main.cpp

clean:
	rm -rf *.o graph.executable

clean_o:
	rm -rf *.o 
