#include "myVector.h"

template <typename Type>
myVector<Type>::myVector() //constructor
{
    arr = new Type[10]; //allocate for 10 spaces
    numAllocated = 10;
    numUsed = 0;
}

template <typename Type>
myVector<Type>::~myVector() //destructor
{
    //can just delete the entire array, the internals will figure out the size
    delete[] arr;
}

template <typename Type>
int myVector<Type>::size()
{
    return numUsed;
}

template <typename Type>
void myVector<Type>::add(Type s)
{
    if (numUsed == numAllocated) //make a bigger array, copy over what we have
        doubleCapacity();
    arr[numUsed++] = s; //remember array starts at 0, so the next use of numUsed will point to the next free space
}

template <typename Type>
Type myVector<Type>::getAt(int index)
{
    if (index >= size())
    {
        std::cerr << "ERROR: Out of scope\n";
        return 0;
    }
    else
        return arr[index];
}

template <typename Type>
void myVector<Type>::doubleCapacity()
{
    Type *new_arr;
    new_arr = new Type[2*numAllocated];
    for (int i = 0; i < numUsed; i++)
        new_arr[i] = arr[i];    //numUsed stays the same
    numAllocated = 2*numAllocated;
    delete[] arr;
    arr = new_arr; //arr now points to new_arr
}

