#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float Area() {
        return length * width;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    float Area() {
        return M_PI * radius * radius;
    }
};

int main() {
    Shape* shapes[5];
    int count = 0;

    shapes[count++] = new Rectangle(4.0, 5.0);
    shapes[count++] = new Circle(3.0);
    shapes[count++] = new Rectangle(6.0, 2.0);
    shapes[count++] = new Circle(2.5);

    for (int i = 0; i < count; i++) {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->Area() << endl;
    }

    for (int i = 0; i < count; i++) {
        delete shapes[i];
    }
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
