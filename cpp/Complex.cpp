#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(const Complex& rhs) {
    real = rhs.real;
    imag = rhs.imag;
}

Complex::Complex(const float& r, const float& i) {
    real = r;
    imag = i;
}

Complex::~Complex() {
}

Complex Complex::getConjugate() {
    return Complex(real, -1*imag);
}

float Complex::getReal() {
    return real;
}

float Complex::getImag() {
    return imag;
}

float Complex::setReal(const float& r) {
    real = r;
}

float Complex::setImag(const float& i) {
    imag = i;
}

Complex Complex::operator+ (const Complex& rhs) {
    return Complex(real + rhs.real, imag + rhs.imag);
}

Complex Complex::operator- (const Complex& rhs) {
    return Complex(real - rhs.real, imag - rhs.imag);
}

Complex Complex::operator* (const Complex& rhs) {
    return Complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
}

Complex Complex::operator/ (const Complex& rhs) {
    float denom = rhs.imag*rhs.imag + rhs.real*rhs.real;
    return Complex((real * rhs.real + imag * rhs.imag)/denom, (real * rhs.imag + imag * rhs.real)/denom);
}

bool Complex::operator== (const Complex& rhs) {
    return (real == rhs.real) && (imag == rhs.imag);
}

void Complex::print() {
    if (imag < 0) {
        cout << real << " - " << -1*imag << "i\n";
    } else {
        cout << real << " + " << imag << "i\n";
    }
}
int main() {
    Complex a(6,3);
    Complex b(3,23);
    Complex c(a);
    c = a+b;
    c.print();
    
}
