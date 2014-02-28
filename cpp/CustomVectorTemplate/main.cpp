#include <iostream>
#include "myVector.h"

using namespace std;

int main()
{
    myVector<string> v;
    v.add("Jason");
    v.add("Jackson");
    v.add("Nathan");
    for (int i = 0; i < v.size(); i++)
        cout << v.getAt(i) << endl;
    //v.getAt(10);

    myVector<int> i;
    i.add(9);
    i.add(10);
    cout << i.getAt(1) << endl;

    return 0;
}

//remember constructor will get called when you initialize a myVector object
//destructor will get called when it goes out of scope
//Note how myVector.cpp isn't part of this project. However, if you look at myVector.h, you will see that it includes myVector.cpp which contains all the templatized functions
//This is done because the user has to determine what Type he wants myVector to be when instantiate. It needs to do it on the fly, therefore, the code for the cpp is in the header file
//The include parameter takes the content of the cpp file and dumps it in the header file
//myVector.cpp is sitting in the same directory as the project, that is why myVector.h can see it
