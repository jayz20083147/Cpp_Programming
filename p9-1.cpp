#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

// Function to display vector
void display(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> vec;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        vec.push_back(value);
    }

    cout << "\nOriginal Vector: ";
    display(vec);

    // Method 1: Using std::reverse()
    vector<int> v1 = vec;
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    display(v1);

    // Method 2: Manual reversal using iterators
    vector<int> v2 = vec;

    vector<int>::iterator start = v2.begin();
    vector<int>::iterator end = v2.end() - 1;

    while (start < end) {
        // swap elements
        int temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }

    cout << "\nReversed using manual iterator method: ";
    display(v2);

    return 0;
}