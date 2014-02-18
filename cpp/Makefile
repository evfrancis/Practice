CC=g++
CFLAGS=-g -O2

tester.bin: Complex.o 
	$(CC) $(CFLAGS) Complex.o  -o tester.bin

Complex.o: Complex.cpp Complex.h
	$(CC) $(CFLAGS) Complex.cpp -c

clean: 
	rm *.o *.bin
