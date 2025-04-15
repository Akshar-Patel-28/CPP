#include <iostream>
#include <cstring>

const int maxParagraphLength = 1000;
const int maxUniqueWords = 100;
const int maxWordLength = 30;

struct WordFrequency {
    char word[maxWordLength];
    int count;
};

char convertToLowercase(char character) {
    if (character >= 'A' && character <= 'Z') {
        return character + ('a' - 'A');
    }
    return character;
}

bool areWordsEqual(const char* word1, const char* word2) {
    int index = 0;
    while (word1[index] && word2[index]) {
        if (convertToLowercase(word1[index]) != convertToLowercase(word2[index])) {
            return false;
        }
        index++;
    }
    return word1[index] == '\0' && word2[index] == '\0';
}

bool isAlphabet(char character) {
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
}

int main() {
    char inputParagraph[maxParagraphLength];
    WordFrequency wordList[maxUniqueWords];
    int totalUniqueWords = 0;

    std::cout << "Enter a paragraph:\n";
    std::cin.getline(inputParagraph, maxParagraphLength);

    char currentWord[maxWordLength];
    int currentWordLength = 0;

    for (int position = 0; ; position++) {
        char currentCharacter = inputParagraph[position];

        if (isAlphabet(currentCharacter)) {
            if (currentWordLength < maxWordLength - 1) {
                currentWord[currentWordLength++] = convertToLowercase(currentCharacter);
            }
        } else {
            if (currentWordLength > 0) {
                currentWord[currentWordLength] = '\0';
                currentWordLength = 0;

                bool wordFound = false;
                for (int i = 0; i < totalUniqueWords; i++) {
                    if (areWordsEqual(wordList[i].word, currentWord)) {
                        wordList[i].count++;
                        wordFound = true;
                        break;
                    }
                }

                if (!wordFound && totalUniqueWords < maxUniqueWords) {
                    std::strcpy(wordList[totalUniqueWords].word, currentWord);
                    wordList[totalUniqueWords].count = 1;
                    totalUniqueWords++;
                }
            }
        }

        if (currentCharacter == '\0') {
            break;
        }
    }

    std::cout << "\nWord Frequencies:\n";
    for (int i = 0; i < totalUniqueWords; i++) {
        std::cout << wordList[i].word << ": " << wordList[i].count << "\n";
    }

    return 0;
}
