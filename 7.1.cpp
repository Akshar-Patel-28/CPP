#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct WordEntry {
    char* word;
    int count;
};

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch + 32;
    return ch;
}

bool areEqual(const char* a, const char* b) {
    while (*a && *b) {
        if (toLower(*a) != toLower(*b)) return false;
        ++a; ++b;
    }
    return *a == '\0' && *b == '\0';
}

void toLowerCase(char* word) {
    for (int i = 0; word[i]; ++i)
        word[i] = toLower(word[i]);
}

int main() {
    const int MAX_LEN = 1000;
    char paragraph[MAX_LEN];
    cout << "Enter a paragraph: ";
    cin.getline(paragraph, MAX_LEN);

    int capacity = 10, size = 0;
    WordEntry* wordList = new WordEntry[capacity];

    char* token = strtok(paragraph, " ,.-!?;\n");
    while (token) {
        toLowerCase(token);
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (areEqual(wordList[i].word, token)) {
                wordList[i].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            if (size == capacity) {
                capacity *= 2;
                WordEntry* newList = new WordEntry[capacity];
                for (int i = 0; i < size; ++i)
                    newList[i] = wordList[i];
                delete[] wordList;
                wordList = newList;
            }
            wordList[size].word = new char[strlen(token) + 1];
            strcpy(wordList[size].word, token);
            wordList[size].count = 1;
            size++;
        }
        token = strtok(NULL, " ,.-!?;\n");
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < size; ++i)
        cout << wordList[i].word << " : " << wordList[i].count << endl;

    for (int i = 0; i < size; ++i)
        delete[] wordList[i].word;
    delete[] wordList;
    cout<<"\nName: AKSHAR PATEL "<<endl<<"ID: 24CE075";
    return 0;
}
