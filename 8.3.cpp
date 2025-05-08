 #include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    std::set<int> transactionIDs;
    int id;

    std::cout << "Enter transaction IDs (enter -1 to stop):\n";
    while (std::cin >> id && id != -1) {
        transactionIDs.insert(id); // Automatically removes duplicates
    }

    std::cout << "\nUnique transaction IDs in sorted order:\n";
    for (auto it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
