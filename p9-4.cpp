#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\n--- Directory Management System ---\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string folder;
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) == directory.end()) {
                directory[folder] = vector<string>();
                cout << "Folder added successfully!\n";
            } else {
                cout << "Folder already exists!\n";
            }
        }

        else if (choice == 2) {
            string folder, file;
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) != directory.end()) {
                cout << "Enter file name: ";
                cin >> file;

                directory[folder].push_back(file);
                cout << "File added successfully!\n";
            } else {
                cout << "Folder does not exist!\n";
            }
        }

        else if (choice == 3) {
            if (directory.empty()) {
                cout << "Directory is empty.\n";
            } else {
                cout << "\n--- Directory Contents ---\n";
                for (auto &pair : directory) {
                    cout << "Folder: " << pair.first << "\n";
                    if (pair.second.empty()) {
                        cout << "  (No files)\n";
                    } else {
                        for (string file : pair.second) {
                            cout << "  - " << file << "\n";
                        }
                    }
                }
            }
        }

        else if (choice == 4) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}