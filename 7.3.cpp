#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
};

void addProduct(const string& filename, const Product& product) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error: Could not open file to add product." << endl;
        return;
    }
    file << product.name << " " << product.quantity << " " << product.price << endl;
    file.close();
}

void displayInventory(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file to display inventory." << endl;
        return;
    }

    Product product;
    while (file >> product.name >> product.quantity >> product.price) {
        cout << "Name: " << product.name << ", Quantity: " << product.quantity << ", Price: $" << product.price << endl;
    }
    file.close();
}

void searchProduct(const string& filename, const string& searchName) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file to search product." << endl;
        return;
    }

    Product product;
    bool found = false;
    while (file >> product.name >> product.quantity >> product.price) {
        if (product.name == searchName) {
            cout << "Product found: Name: " << product.name << ", Quantity: " << product.quantity << ", Price: $" << product.price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found!" << endl;
    }
    file.close();
}

int main() {
    string filename = "inventory.txt";
    int choice;
    do {
        cout << "\nInventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To discard newline character after integer input

        if (choice == 1) {
            Product newProduct;
            cout << "Enter product name: ";
            getline(cin, newProduct.name);
            cout << "Enter product quantity: ";
            cin >> newProduct.quantity;
            cout << "Enter product price: ";
            cin >> newProduct.price;

            addProduct(filename, newProduct);
            cout << "Product added successfully!" << endl;
        }
        else if (choice == 2) {
            displayInventory(filename);
        }
        else if (choice == 3) {
            string searchName;
            cout << "Enter product name to search: ";
            cin.ignore(); // To discard leftover newline
            getline(cin, searchName);

            searchProduct(filename, searchName);
        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
