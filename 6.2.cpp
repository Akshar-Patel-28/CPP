#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point* moveX(int dx) {
        x += dx;
        return this;
    }

    Point* moveY(int dy) {
        y += dy;
        return this;
    }

    Point* move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(5, 10);
    p.moveX(3)->moveY(-2)->move(-1, 4)->display();
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
