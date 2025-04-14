#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Employee : public Person {
protected:
    int employeeId;
public:
    Employee(string n = "", int a = 0, int id = 0)
        : Person(n, a), employeeId(id) {}
    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeId << endl;
    }
};
class Manager : public Employee {
private:
    string department;
public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "")
        : Employee(n, a, id), department(dept) {}

    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};
class ManagerStorage {
private:
    Manager managers[10];
    int count;
public:
    ManagerStorage() : count(0) {}

    void addManager(Manager m) {
        if (count < 10) {
            managers[count++] = m;
        } else {
            cout << "Cannot add more managers. Storage is full.\n";
        }
    }

    void showAllManagers() {
        for (int i = 0; i < count; i++) {
            cout << "\nManager " << i + 1 << " Details:\n";
            managers[i].displayManager();
        }
    }
};

int main() {
    ManagerStorage store;
    int num;

    cout << "Enter number of managers to add (max 10): ";
    cin >> num;
    cin.ignore();

    if (num > 10) {
        cout << "Only up to 10 managers allowed.\n";
        num = 10;
    }

    for (int i = 0; i < num; i++) {
        string name, department;
        int age, id;

        cout << "\nEnter details for Manager " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Department: ";
        getline(cin, department);

        Manager m(name, age, id, department);
        store.addManager(m);
    }

    cout << "\n--- All Manager Details ---\n";
    store.showAllManagers();

    return 0;
}
