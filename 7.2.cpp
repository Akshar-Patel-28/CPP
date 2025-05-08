#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' || ch == '.' || ch == ';' || ch == '!';
}

int main() {
    const int MAX_LINE_LENGTH = 1000;
    char* line = new char[MAX_LINE_LENGTH];
    int totalLines = 0, totalWords = 0, totalChars = 0;

    cout << "Enter the file name: ";
    string filename;
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        delete[] line;
        return 1;
    }

    while (file.getline(line, MAX_LINE_LENGTH)) {
        totalLines++;
        int lineChars = 0, lineWords = 0;
        bool inWord = false;

        for (int i = 0; line[i] != '\0'; i++) {
            lineChars++;
            if (isDelimiter(line[i])) {
                if (inWord) {
                    lineWords++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) {
            lineWords++;
        }

        totalWords += lineWords;
        totalChars += lineChars;
    }

    cout << "\nFile Statistics:" << endl;
    cout << "Total Lines: " << totalLines << endl;
    cout << "Total Words: " << totalWords << endl;
    cout << "Total Characters: " << totalChars << endl;

    delete[] line;
    file.close();
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
