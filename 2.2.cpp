#include <iostream>
using namespace std;

class students_details {
    int eng, maths, cpp, id;
    float avg;
    string name;

public:
    void get_data(string n, int roll_no, int m1, int m2, int m3) {
        name = n;
        id = roll_no;
        eng = m1;
        maths = m2;
        cpp = m3;
        calculate_average();
    }

    void calculate_average() {
        avg = (eng + maths + cpp) / 3.0;
    }

    int search_id(int id1) {
        if (id == id1) {
            return 1;
        }
       else { return 0;
    }
    }

    void display() {
        cout << "\nName      : " << name;
        cout << "\nRoll No   : " << id;
        cout << "\nAverage   : " << avg;
        cout << "\n---------------------------------------------\n";
    }
};

int main() {
    int count, choice, m1, m2, m3, roll_no, id1;
    string n;
    students_details s[50];

    cout << "Enter the number of students: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "\nEnter the name of student " << i + 1 << ": ";
        cin >> n;
        cout << "Enter the roll number of student " << i + 1 << ": ";
        cin >> roll_no;
        cout << "Enter the marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
        s[i].get_data(n, roll_no, m1, m2, m3);
    }

    cout << "\nEnter 1 to display all records or 0 to display a specific record: ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < count; i++) {
            s[i].display();
        }
    } else {
        cout << "\nEnter the roll number to search: ";
        cin >> id1;

        for (int i = 0; i < count; i++) {
            if (s[i].search_id(id1) == 1) {
                s[i].display();
                break;
            }
            else if (s[i].search_id(id1) == 0){
                if(i==count-1){
                    cout<<" Id Not Found. ";
                }
                else{continue;}

            }
        }

    }


    return 0;
}
