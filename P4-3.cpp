#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int* a = new int[n];
    int* b = new int[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int* c = new int[n + m];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }

    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];

    for (int i = 0; i < n + m; i++) cout << c[i] << " ";
    cout << endl;

    int* uniqueArr = new int[n + m];
    int u = 0;

    for (int i = 0; i < n + m; i++) {
        if (i == 0 || c[i] != c[i - 1]) uniqueArr[u++] = c[i];
    }

    for (int i = 0; i < u; i++) cout << uniqueArr[i] << " ";
    cout << endl;

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] uniqueArr;

    return 0;
}