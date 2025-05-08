#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
    char grade;
};

// User-defined manipulator for aligning columns
ostream& alignColumns(ostream& os) {
    return os << left << setw(20) << setfill(' ') << "";
}

void displayReportFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file to display report." << endl;
        return;
    }

    Student student;
    cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << "---------------------------------------------" << endl;

    while (file >> student.name >> student.marks >> student.grade) {
        cout << setw(20) << student.name << setw(10) << student.marks << setw(10) << student.grade << endl;
    }

    file.close();
}

void displayReportWithStorage(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file to process student records." << endl;
        return;
    }

    vector<Student> students;
    Student student;

    while (file >> student.name >> student.marks >> student.grade) {
        students.push_back(student);
    }

    file.close();

    cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& s : students) {
        cout << setw(20) << s.name << setw(10) << s.marks << setw(10) << s.grade << endl;
    }
}

int main() {
    string filename = "students.txt"; // Input file with student data
    int choice;

    do {
        cout << "\nStudent Performance Report Generator" << endl;
        cout << "1. Display Report (File Processing)" << endl;
        cout << "2. Display Report with Storage (Dynamic Structure)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            displayReportFromFile(filename);
        }
        else if (choice == 2) {
            displayReportWithStorage(filename);
        }
        else if (choice != 3) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";

    return 0;
}
