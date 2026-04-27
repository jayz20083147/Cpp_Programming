#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> input;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        input.push_back(value);
    }

    // Store in set (automatically removes duplicates and sorts)
    set<int> uniqueSet(input.begin(), input.end());

    // Display original input
    cout << "\nOriginal List (with possible duplicates): ";
    for (int x : input) {
        cout << x << " ";
    }

    // Display set using iterator
    cout << "\n\nUnique Sorted Elements (using set + iterator): ";
    for (set<int>::iterator it = uniqueSet.begin(); it != uniqueSet.end(); ++it) {
        cout << *it << " ";
    }

    // Convert set to vector
    vector<int> uniqueVector(uniqueSet.begin(), uniqueSet.end());

    // Display vector
    cout << "\n\nConverted to Vector: ";
    for (int x : uniqueVector) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}