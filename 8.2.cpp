#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::string sentence;
    std::map<std::string, int> wordCount;

    std::cout << "Enter a sentence:\n";
    std::cin.ignore(); // Clear newline from input buffer
    std::getline(std::cin, sentence);

    std::istringstream stream(sentence);
    std::string word;

    while (stream >> word) {
        ++wordCount[word];
    }

    std::cout << "\nWord frequency:\n";
    for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
