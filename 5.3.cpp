#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator-() {
        return Point(-x, -y);
    }

    bool operator==(const Point& p) {
        return x == p.x && y == p.y;
    }

    void display() {
        cout << "(" << x << ", " << y << ")\n";
    }
};

class PointStack {
    Point stack[100];
    int top;

public:
    PointStack() : top(-1) {}

    void push(Point p) {
        if (top < 99)
            stack[++top] = p;
    }

    Point pop() {
        if (top >= 0)
            return stack[top--];
        return Point();
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Point p1(2, 3), p2(4, -1), p3;
    PointStack s;

    p3 = p1 + p2;
    s.push(p3);
    cout << "After addition: ";
    p3.display();

    p3 = -p3;
    s.push(p3);
    cout << "After negation: ";
    p3.display();

    if (p1 == p2)
        cout << "Points are equal\n";
    else
        cout << "Points are not equal\n";

    cout << "Undo operations:\n";
    while (!s.isEmpty()) {
        Point p = s.pop();
        p.display();
    }
cout<<"\nName: AKSHAR PATEL"<<endl<<"ID: 24CE075";
    return 0;
}
