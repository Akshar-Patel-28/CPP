#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    std::string accountHolder;
    double balance;
    std::vector<std::string> transactionHistory;

    // Internal logger for function call history on errors
    void logError(const std::string& functionName, const std::string& errorMsg) {
        std::string logEntry = "[ERROR] Function: " + functionName + " - " + errorMsg;
        transactionHistory.push_back(logEntry);
        std::cerr << logEntry << std::endl;
    }

public:
    BankAccount(const std::string& name, double initialBalance)
        : accountHolder(name), balance(initialBalance) {
        transactionHistory.push_back("Account created for " + name + " with balance " + std::to_string(initialBalance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logError("deposit", "Deposit amount must be positive.");
            return;
        }
        balance += amount;
        transactionHistory.push_back("Deposited: " + std::to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logError("withdraw", "Withdrawal amount must be positive.");
            return;
        }
        if (amount > balance) {
            logError("withdraw", "Insufficient funds. Attempted to withdraw " + std::to_string(amount));
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrew: " + std::to_string(amount));
    }

    double getBalance() const {
        return balance;
    }

    void showTransactionHistory() const {
        std::cout << "\n--- Transaction History for " << accountHolder << " ---\n";
        for (const std::string& entry : transactionHistory) {
            std::cout << entry << std::endl;
        }
        std::cout << "----------------------------------------\n";
    }
};

int main() {
    std::string name;
    double initialBalance;

    std::cout << "Welcome to SimpleBank\n";
    std::cout << "Enter account holder's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    BankAccount account(name, initialBalance);

    int choice;
    double amount;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Show Transaction History\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                std::cout << "Current Balance: " << account.getBalance() << std::endl;
                break;

            case 4:
                account.showTransactionHistory();
                break;

            case 5:
                std::cout << "Thank you for using SimpleBank.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 5);
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
