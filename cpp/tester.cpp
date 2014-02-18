#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex a(6,3);
    Complex b(3,23);
    Complex c(a);
    c = a+b;
    c.print();
    
}
