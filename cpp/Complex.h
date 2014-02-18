#ifndef COMPLEX_H
#define COMPLEX_H
// A class that implements complex numbers
class Complex {
    private:
        float real;
        float imag;
    public:
        Complex();
        Complex(const float& r, const float& i);
        Complex(const Complex& rhs);
        ~Complex();

        // Accessors
        Complex getConjugate();
        float getReal();
        float getImag();

        // Mutators
        float setReal(const float& r);
        float setImag(const float& i);

        // Operators
        Complex operator+ (const Complex& rhs);
        Complex operator- (const Complex& rhs);
        Complex operator* (const Complex& rhs);
        Complex operator/ (const Complex& rhs);
        bool operator== (const Complex& rhs); 

        void print();
};
#endif
