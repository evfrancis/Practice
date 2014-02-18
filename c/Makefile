CC=gcc
CFLAGS=-g -O2

tester.bin: tester.c algorithms.o BST.o linkedList.o
	$(CC) $(CFLAGS) algorithms.o BST.o linkedList.o tester.c -o tester.bin

algorithms.o: algorithms.h algorithms.c
	$(CC) $(CFLAGS) -c algorithms.c

BST.o: BST.h BST.c
	$(CC) $(CFLAGS) -c BST.c

linkedList.o: linkedList.h linkedList.c
	$(CC) $(CFLAGS) -c linkedList.c

clean:
	rm *.bin *.o
