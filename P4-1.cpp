#include <iostream>
using namespace std;

class DynamicArray {
    int* arr;
    int size;

public:
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    void insertEnd(int value) {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) temp[i] = arr[i];
        temp[size] = value;
        delete[] arr;
        arr = temp;
        size++;
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > size) return;
        int* temp = new int[size + 1];
        for (int i = 0, j = 0; i < size + 1; i++) {
            if (i == index) temp[i] = value;
            else temp[i] = arr[j++];
        }
        delete[] arr;
        arr = temp;
        size++;
    }

    void deleteAt(int index) {
        if (size == 0 || index < 0 || index >= size) return;
        int* temp = new int[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) temp[j++] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size--;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }

    int countOccurrences(int value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) count++;
        }
        return count;
    }

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    DynamicArray d;

    d.insertEnd(10);
    d.display();

    d.insertEnd(20);
    d.display();

    d.insertEnd(30);
    d.display();

    d.insertEnd(40);
    d.display();

    d.insertEnd(50);
    d.display();

    d.deleteAt(2);
    d.display();

    d.deleteAt(0);
    d.display();

    d.deleteAt(2);
    d.display();

    d.insertAt(1, 25);
    d.display();

    cout << d.search(40) << endl;
    cout << d.countOccurrences(25) << endl;

    return 0;
}