#include <iostream>
#include <cstring>
using namespace std;

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}
int isAlpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
int main() {
    char str[500];
    cin.getline(str, 500);
    char words[100][50];
    int freq[100] = {0};
    int count = 0;
    int i = 0;
    while (str[i]) {
        while (str[i] && !isAlpha(str[i]))
            i++;
        char temp[50];
        int j = 0;
        while (str[i] && isAlpha(str[i])) {
            temp[j++] = toLowerChar(str[i]);
            i++;
        }
        temp[j] = '\0';
        if (j == 0)
            continue;
        int found = -1;
        for (int k = 0; k < count; k++) {
            if (strcmp(words[k], temp) == 0) {
                found = k;
                break;
            }
        }
        if (found != -1)
            freq[found]++;
        else {
            strcpy(words[count], temp);
            freq[count] = 1;
            count++;
        }
    }
    cout << "Words and Frequencies:\n";
    for (int i = 0; i < count; i++)
        cout << words[i] << " : " << freq[i] << endl;
    int maxFreq = 0;
    int maxIndex = 0;
    for (int i = 0; i < count; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxIndex = i;
        }
    }
    cout << "Most Frequent Word: " << words[maxIndex] << endl;
    cout << "Total Unique Words: " << count << endl;
    return 0;
}