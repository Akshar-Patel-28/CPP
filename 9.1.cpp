#include <iostream>
#include <limits>
#include <string>
#include <sstream>
using namespace std;

// Function to get a validated double input from user
double getValidatedInput(const std::string& prompt) {
    double value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            std::cout << "Invalid input. Please enter a valid numeric value.\n";
        }
    }
}

int main() {
    std::cout << "=== Loan-to-Income Ratio Calculator ===\n";

    // Get validated inputs
    double loanAmount = getValidatedInput("Enter total loan amount: ");
    double annualIncome;

    while (true) {
        annualIncome = getValidatedInput("Enter your annual income: ");
        if (annualIncome == 0) {
            std::cout << "Annual income cannot be zero. Please enter a valid income.\n";
        } else {
            break;
        }
    }

    // Calculate and display ratio
    double ratio = loanAmount / annualIncome;
    std::cout << "\nLoan-to-Income Ratio: " << ratio << std::endl;

    // Interpretation (optional)
    if (ratio > 0.5) {
        std::cout << "Warning: Your loan amount is high compared to your income.\n";
    } else {
        std::cout << "Your loan-to-income ratio is within an acceptable range.\n";
    }
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
