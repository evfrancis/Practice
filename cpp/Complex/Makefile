CC=g++
CFLAGS=

all: tester.bin

tester.bin: Complex.o tester.o 
	$(CC) $(CFLAGS) Complex.o tester.o -o tester.bin

tester.o: tester.cpp
	$(CC) $(CFLAGS) -c tester.cpp

Complex.o: Complex.cpp Complex.h
	$(CC) $(CFLAGS) -c Complex.cpp

clean: 
	rm *.o *.bin
