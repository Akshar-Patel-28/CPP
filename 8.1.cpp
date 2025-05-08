#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

int main() {
    std::vector<int> numbers;
    int num, choice;

    std::cout << "Enter numbers (enter -1 to stop): ";
    while (std::cin >> num && num != -1) {
        numbers.push_back(num);
    }

    std::cout << "\nChoose reversal method:\n";
    std::cout << "1. Using std::reverse()\n";
    std::cout << "2. Using manual iterator-based reversal\n";
    std::cin >> choice;

    if (choice == 1) {
        std::reverse(numbers.begin(), numbers.end());
    } else if (choice == 2) {
        auto front = numbers.begin();
        auto back = numbers.end();
        --back; // move to last element

        while (front < back) {
            std::iter_swap(front, back);
            ++front;
            --back;
        }
    } else {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    std::cout << "\nReversed sequence: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
}
