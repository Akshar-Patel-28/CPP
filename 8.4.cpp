#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    std::vector<std::pair<std::string, int>> students;
    std::string name;
    int score;

    std::cout << "Enter student name and score (enter 'end' to stop):\n";
    while (true) {
        std::cout << "Name: ";
        std::cin >> name;
        if (name == "end") break;
        std::cout << "Score: ";
        std::cin >> score;
        students.push_back({name, score});
    }

    // Sort using custom comparator (descending order of score)
    std::sort(students.begin(), students.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    std::cout << "\nRanked Student List:\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        std::cout << rank++ << ". " << it->first << " - " << it->second << std::endl;
    }
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
