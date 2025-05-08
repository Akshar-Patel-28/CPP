#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
protected:
    string name;
    float marks;

public:
    Student(const string& name, float marks) : name(name), marks(marks) {}
    virtual void computeGrade() const = 0;
    virtual void display() const {
        cout << "Name: " << name << ", Marks: " << marks << " ";
    }
    virtual ~Student() {}
};

class Undergraduate : public Student {
public:
    Undergraduate(const string& name, float marks) : Student(name, marks) {}

    void computeGrade() const override {
        display();
        if (marks >= 85)
            cout << "Grade: A\n";
        else if (marks >= 70)
            cout << "Grade: B\n";
        else if (marks >= 50)
            cout << "Grade: C\n";
        else
            cout << "Grade: F\n";
    }
};

class Postgraduate : public Student {
public:
    Postgraduate(const string& name, float marks) : Student(name, marks) {}

    void computeGrade() const override {
        display();
        if (marks >= 90)
            cout << "Grade: A\n";
        else if (marks >= 75)
            cout << "Grade: B\n";
        else if (marks >= 60)
            cout << "Grade: C\n";
        else
            cout << "Grade: F\n";
    }
};

int main() {
    Student* students[MAX_STUDENTS];
    int count = 0;
    int choice;
    string name;
    float marks;

    cout << "Student Grading System\n";
    while (true) {
        cout << "\n1. Add Undergraduate Student\n2. Add Postgraduate Student\n3. Display Grades\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count >= MAX_STUDENTS) {
                cout << "Student limit reached!\n";
                break;
            }
            cout << "Enter name and marks: ";
            cin >> name >> marks;
            students[count++] = new Undergraduate(name, marks);
            break;
        case 2:
            if (count >= MAX_STUDENTS) {
                cout << "Student limit reached!\n";
                break;
            }
            cout << "Enter name and marks: ";
            cin >> name >> marks;
            students[count++] = new Postgraduate(name, marks);
            break;
        case 3:
            cout << "\nStudent Grades:\n";
            for (int i = 0; i < count; ++i)
                students[i]->computeGrade();
            break;
        case 4:
            for (int i = 0; i < count; ++i)
                delete students[i];
                 cout<<"\nAKSHAR PATEL\n24CE075 ";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";

        }
    }
}
