#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    std::map<std::string, std::vector<std::string>> directory;
    int choice;
    std::string folder, file;

    do {
        std::cout << "\nDirectory Management System:\n";
        std::cout << "1. Create a new folder\n";
        std::cout << "2. Add file to an existing folder\n";
        std::cout << "3. Display directory structure\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter folder name: ";
                std::cin >> folder;
                if (directory.find(folder) == directory.end()) {
                    directory[folder] = std::vector<std::string>(); // creates an empty file list
                    std::cout << "Folder '" << folder << "' created.\n";
                } else {
                    std::cout << "Folder already exists.\n";
                }
                break;

            case 2:
                std::cout << "Enter folder name to add file to: ";
                std::cin >> folder;
                if (directory.find(folder) != directory.end()) {
                    std::cout << "Enter file name: ";
                    std::cin >> file;
                    directory[folder].push_back(file);
                    std::cout << "File '" << file << "' added to folder '" << folder << "'.\n";
                } else {
                    std::cout << "Folder does not exist. Create it first.\n";
                }
                break;

            case 3:
                std::cout << "\nDirectory Structure:\n";
                for (auto it = directory.begin(); it != directory.end(); ++it) {
                    std::cout << "Folder: " << it->first << "\n";
                    std::vector<std::string> files = it->second;

                    // Optional: sort files alphabetically
                    std::sort(files.begin(), files.end());

                    for (const auto& f : files) {
                        std::cout << "  - " << f << "\n";
                    }
                }
                break;

            case 4:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);
cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
