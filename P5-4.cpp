#include <iostream>
using namespace std;

class Student {
private:
    char name[20];
    float marks;
    float fees;

public:
    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks (out of 100): ";
        cin >> marks;
        cout << "Enter Fees: ";
        cin >> fees;
    }

    char* getName() {
        return name;
    }

    float getMarks() {
        return marks;
    }

    float getFees() {
        return fees;
    }
};

class Display {
public:
    void printSpaces(int n) {
        for (int i = 0; i < n; i++)
            cout << " ";
    }
    void printLine() {
        for (int i = 0; i < 60; i++)
            cout << "=";
        cout << endl;
    }
    void currency(float amount) {
        cout << "₹ " << amount;
    }

    void show(Student s[], int n) {

        printLine();

        cout << "Name";
        printSpaces(15);
        cout << "Marks";
        printSpaces(10);
        cout << "Percentage";
        printSpaces(5);
        cout << "Fees" << endl;

        printLine();

        for (int i = 0; i < n; i++) {

            float percentage = s[i].getMarks();
            cout << s[i].getName();
            printSpaces(20 - strlen(s[i].getName()));
            cout << s[i].getMarks();
            printSpaces(15);
            cout << percentage;
            printSpaces(15);
            currency(s[i].getFees());

            cout << endl;
        }

        printLine();
    }
};

int main() {
    Student s[5];
    Display d;

    cout << "Enter details of 3 students:\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << i + 1 << endl;
        s[i].input();
    }

    cout << "\nFormatted Output:\n";
    d.show(s, 3);

    return 0;
}