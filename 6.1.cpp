#include <iostream>
using namespace std;

class DynamicArray {
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    void insert(int value) {
        if (size == capacity)
            resize(capacity * 2);
        data[size++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size)
            return;
        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        size--;
    }

    void display() {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.display();

    arr.removeAt(1);
    arr.display();

    arr.insert(40);
    arr.display();
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
