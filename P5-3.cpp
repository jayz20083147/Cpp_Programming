#include <iostream>
using namespace std;

class Item {
private:
    char name[20];
    int quantity;
    float price;

public:
    void input() {
        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() {
        cout << "Name: " << name
             << ", Quantity: " << quantity
             << ", Price: " << price << endl;
    }

    char* getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    void setPrice(float p) {
        price = p;
    }
};

class Inventory {
private:
    Item items[100];
    int count;

public:
    Inventory() {
        count = 0;
    }
    bool isEqual(char a[], char b[]) {
        int i = 0;
        while (a[i] != '\0' && b[i] != '\0') {
            if (a[i] != b[i])
                return false;
            i++;
        }
        return (a[i] == '\0' && b[i] == '\0');
    }
    void addItem() {
        items[count].input();
        count++;
        cout << "Item added successfully!\n";
    }
    void viewItems() {
        cout << "\n--- Inventory List ---\n";
        for (int i = 0; i < count; i++) {
            items[i].display();
        }
    }
    void searchItem() {
        char searchName[20];
        cout << "Enter item name to search: ";
        cin >> searchName;

        for (int i = 0; i < count; i++) {
            if (isEqual(items[i].getName(), searchName)) {
                cout << "Item Found!\n";
                items[i].display();
                return;
            }
        }

        cout << "Item not found!\n";
    }
    void deleteItem() {
        char deleteName[20];
        cout << "Enter item name to delete: ";
        cin >> deleteName;

        for (int i = 0; i < count; i++) {
            if (isEqual(items[i].getName(), deleteName)) {

                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                }

                count--;
                cout << "Item deleted successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }
    void modifyItem() {
        char modifyName[20];
        cout << "Enter item name to modify: ";
        cin >> modifyName;

        for (int i = 0; i < count; i++) {
            if (isEqual(items[i].getName(), modifyName)) {
                cout << "Enter new quantity: ";
                int q;
                cin >> q;

                cout << "Enter new price: ";
                float p;
                cin >> p;

                items[i].setQuantity(q);
                items[i].setPrice(p);

                cout << "Item modified successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }
    void countItems() {
        cout << "Total items: " << count << endl;
    }
    void lowStock() {
        int threshold;
        cout << "Enter threshold: ";
        cin >> threshold;

        cout << "\nLow Stock Items:\n";

        for (int i = 0; i < count; i++) {
            if (items[i].getQuantity() < threshold) {
                items[i].display();
            }
        }
    }
};

int main() {
    Inventory inv;
    int choice;

    do {
        cout << "\n--- Inventory Menu (No File) ---\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Search Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Modify Item\n";
        cout << "6. Count Items\n";
        cout << "7. Low Stock Alert\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: inv.addItem(); break;
            case 2: inv.viewItems(); break;
            case 3: inv.searchItem(); break;
            case 4: inv.deleteItem(); break;
            case 5: inv.modifyItem(); break;
            case 6: inv.countItems(); break;
            case 7: inv.lowStock(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}