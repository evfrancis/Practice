#include <iostream>
#include "graphNode.h"

using namespace std;

int main()
{
    GraphNode a;
    GraphNode b;
    GraphNode c;
/*
    a.add2wayConnection(b);
    a.add2wayConnection(c);
    a.printConnections();
    cout << endl << endl;
    //a.remove2wayConnection(b);
    a.removeOutputConnection(b);
    a.removeInputConnection(b);
    a.printConnections();
*/

/*
    cout << a.addInputConnection(b) << endl; //a<-b
    cout << endl;
    
    cout << "A:" << endl;
    a.printConnections();
    
    cout << "B:" << endl;
    b.printConnections();
*/
  //create a 2 way connection using the input and output adding functions
    a.addInputConnection(b);
    cout << a.addOutputConnection(b) << endl; //a->b
    cout << a.addOutputConnection(b) << endl; //a->b
    cout << endl;
    
    cout << "A:" << endl;
    a.printConnections();
    
    cout << "B:" << endl;
    b.printConnections();
    
    return 0;
}
