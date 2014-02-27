CC=gcc
CFLAGS=-g -O2 -Wall -Wunreachable-code
LDFLAGS=
SOURCES=tester.c algorithms.c BST.c linkedList.c stack.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tester.bin

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -f *.bin *.o
