#include <iostream>
using namespace std;

class Base {
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
    int* data;
public:
    Derived(int size) {
        data = new int[size];
    }
    ~Derived() {
        delete[] data;
        cout << "Derived Destructor Called" << endl;
    }
};

int main() {
    Base* ptr = new Derived(10);
    delete ptr;
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
