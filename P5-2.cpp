#include <iostream>
#include <fstream>
using namespace std;

int isVowel(char c) {
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
        c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return 1;
    return 0;
}

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "File not found\n";
        return 0;
    }

    char ch;
    int chars = 0, words = 0, lines = 0, blank = 0;
    int vowels = 0, consonants = 0;
    bool inWord = false;

    char line[500];
    int maxLen = 0;

    while (file.getline(line, 500)) {
        lines++;

        int len = 0;
        bool isBlank = true;

        for (int i = 0; line[i] != '\0'; i++) {
            ch = line[i];
            chars++;
            len++;

            if (ch != ' ' && ch != '\t')
                isBlank = false;

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                if (isVowel(ch))
                    vowels++;
                else
                    consonants++;

                if (!inWord) {
                    words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }

        if (isBlank)
            blank++;

        if (len > maxLen)
            maxLen = len;

        inWord = false;
    }

    cout << "Characters: " << chars << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;
    cout << "Blank Lines: " << blank << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Longest Line Length: " << maxLen << endl;

    file.close();
    return 0;
}