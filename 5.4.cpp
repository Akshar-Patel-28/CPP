#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float t = 0) : temp(t) {}

    operator Fahrenheit();

    bool operator==(const Celsius& c) {
        return temp == c.temp;
    }

    float getTemp() const {
        return temp;
    }

    void display() {
        cout << temp << " °C\n";
    }
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 0) : temp(t) {}

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    bool operator==(const Fahrenheit& f) {
        return temp == f.temp;
    }

    float getTemp() const {
        return temp;
    }

    void display() {
        cout << temp << " °F\n";
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

class TempQueue {
    Fahrenheit queue[100];
    int front, rear;

public:
    TempQueue() : front(0), rear(0) {}

    void enqueue(Fahrenheit f) {
        if (rear < 100)
            queue[rear++] = f;
    }

    Fahrenheit dequeue() {
        if (front < rear)
            return queue[front++];
        return Fahrenheit();
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    Celsius c1(37.0);
    Fahrenheit f1 = c1;

    f1.display();

    Celsius c2 = f1;
    c2.display();

    TempQueue tq;
    tq.enqueue(f1);
    tq.enqueue(Fahrenheit(98.6));

    cout << "Dequeue temperatures:\n";
    while (!tq.isEmpty()) {
        Fahrenheit f = tq.dequeue();
        f.display();
    }
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";

    return 0;
}
