#ifndef _myVector_H  //don't want to include this header file twice so we do this
#define _myVector_H

#include <string> //need to use std::string since we are not using namespace std;
#include <iostream>

//This will only be used for a string. Check the other files for a templatized version
template <typename Type>
class myVector
{
    public:
        myVector();
        ~myVector();

        int size();
        void add(Type s);
        Type getAt(int index);

    private:
        void doubleCapacity();
        Type * arr; //will resize and copy elements over everytime it gets full
        int numUsed, numAllocated;
};

#include "myVector.ipp" //this is only done for templatized functions, the compiler doesn't see the header and the cpp separate for this

#endif

