#include <iostream>
using namespace std;

class fuel {
protected:
    string fuelType;
public:
    fuel(string f = "") {
        fuelType = f;
    }
};

class brand {
protected:
    string brandName;
public:
    brand(string b = "") {
        brandName = b;
    }
};

class Car : public fuel, public brand {
private:
    string carName;
public:
    Car() : fuel(""), brand("") {
        carName = "";
    }

    void setDetails(string cn, string f, string b) {
        carName = cn;
        fuelType = f;
        brandName = b;
    }

    void displayDetail() {
        cout << "\n--- Car Details ---" << endl;
        cout << "Car Name: " << carName << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Brand Name: " << brandName << endl;
    }
};

int main() {
    Car cars[100];
    string cn, f, b;
    int i = 0;
    char choice;

    do {
        cout << "\nEnter details for car " << i + 1 << ":" << endl;
        cout << "Enter Car Name: ";
        cin >> cn;
        cout << "Enter Fuel Type: ";
        cin >> f;
        cout << "Enter Brand Name: ";
        cin >> b;

        cars[i].setDetails(cn, f, b);
        i++;

        cout << "Do you want to add another car? (y/n): ";
        cin >> choice;

    } while ((choice == 'y' || choice == 'Y') && i < 100);

    cout << "\nDisplaying all car details:\n";
    for (int j = 0; j < i; j++) {
        cars[j].displayDetail();
    }


    return 0;
}
