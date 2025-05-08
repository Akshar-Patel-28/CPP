#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string name;
    double marks;
    double tuitionFees;
};

ostream& currency(ostream& os) {
    return os << "₹";
}

void displayStudentReport(Student students[], int numStudents) {
    cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(15) << "Tuition Fees" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < numStudents; ++i) {
        cout << setw(20) << students[i].name
             << setw(10) << setprecision(2) << fixed << students[i].marks
             << setw(15) << currency << setprecision(2) << fixed << students[i].tuitionFees << endl;
    }
}

int main() {
    Student students[] = {
        {"John Doe", 85.5, 50000.0},
        {"Jane Smith", 92.0, 60000.0},
        {"Samuel Lee", 78.5, 45000.0}
    };

    int numStudents = sizeof(students) / sizeof(students[0]);
    displayStudentReport(students, numStudents);
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
