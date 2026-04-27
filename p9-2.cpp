#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// Function to convert string to lowercase
string toLower(string word) {
    for (char &c : word) {
        c = tolower(c);
    }
    return word;
}

// Function to remove punctuation from a word
string cleanWord(string word) {
    string result = "";
    for (char c : word) {
        if (isalnum(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    map<string, int> wordFreq;

    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        word = cleanWord(word);     // remove punctuation
        word = toLower(word);       // convert to lowercase

        if (!word.empty()) {
            wordFreq[word]++;       // increase frequency
        }
    }

    cout << "\nWord Frequencies:\n";

    for (map<string, int>::iterator it = wordFreq.begin(); it != wordFreq.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}