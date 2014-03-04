#Graph library
$(CXX) = g++

all:	CustomVector

CustomVector:	main.o
	$(CXX) main.o myVector.h -o cvector.executable

main.o:	main.cpp
	$(CXX) -c main.cpp

clean:
	rm -rf *.o cvector.executable

clean_o:
	rm -rf *.o 
