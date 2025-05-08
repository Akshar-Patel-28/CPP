#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    float add(int a, float b) {
        return a + b;
    }

    double add(float a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    cout << "Int + Int: " << calc.add(2, 3) << endl;
    cout << "Float + Float: " << calc.add(2.5f, 3.5f) << endl;
    cout << "Double + Double: " << calc.add(2.75, 3.25) << endl;
    cout << "Int + Float: " << calc.add(5, 4.5f) << endl;
    cout << "Float + Double: " << calc.add(1.1f, 2.2) << endl;
     cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
