#include <iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;
    cout << "Enter first complex number (real and imaginary): ";
    cin >> c1;
    cout << "Enter second complex number (real and imaginary): ";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
