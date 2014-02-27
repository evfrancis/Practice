CC=gcc
CFLAGS=-g -O2 -Wall -Wunreachable-code

SOURCES=*.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tester.bin

all: $(EXECUTABLE)

tester.bin: tester.o algorithms.o BST.o linkedList.o stack.o
	$(CC) $(CFLAGS) algorithms.o BST.o linkedList.o stack.o tester.o  -o tester.bin

tester.o: tester.c
	$(CC) $(CFLAGS) -c tester.c

algorithms.o: algorithms.h algorithms.c
	$(CC) $(CFLAGS) -c algorithms.c

BST.o: BST.h BST.c
	$(CC) $(CFLAGS) -c BST.c

linkedList.o: linkedList.h linkedList.c
	$(CC) $(CFLAGS) -c linkedList.c

stack.o: stack.h stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm *.bin *.o
