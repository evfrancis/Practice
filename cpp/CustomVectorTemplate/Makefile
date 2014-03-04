#Graph library
$(CXX) = g++

all:	CustomVector

CustomVector:	main.o
	$(CXX) main.o myVector.h -o cvector.bin

main.o:	main.cpp
	$(CXX) -c main.cpp

clean:
	rm -rf *.o cvector.bin

clean_o:
	rm -rf *.o 
