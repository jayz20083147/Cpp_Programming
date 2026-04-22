#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class ManagementSystem{
    public:
    string name;
    int quantity;
    double price;

    ManagementSystem()
    {
    }

    void dispaly()
    {
        cout << "Name:" << name;
        cout << " quantity:" << quantity;
        cout << " price:" << price;
         }
    void Additem()
    {
            ofstream file("inventory.txt",ios::app);
            string name;
            int quantity;
            double price;

            cout << "Enter item name:";
            cin >> name;
            cout << "Enter item quantity:";
            cin >> quantity;
            cout << "Enter item price:";
            cin >> price;

            file << name << " " << quantity << " " << price;
            file.close();
            cout << "Item added successfully:" << endl;
    }
    void ViewItem()
    {
            ifstream file("inventory.txt");
            string name;
            int quantity;
            double price;
            while(file >> name >> quantity >> price)
            {
                cout << name << "\t" << quantity << "\t" << price;
            }
            file.close();
    }
    void SearchItem()
    {
            string searchname;
            ifstream file("inventory.txt");
            string name;
            int quantity;
            double price;
            bool found=false;
            cout << "Enter item name to search:";
            cin >> searchname;
            while(file >> name >> quantity >> price)
            {
                if(searchname==name)
                {
                    cout << "Item found:";
                    cout << "Name:" << name << endl;
                    cout << "Quantity:" << quantity << endl;
                    cout << "Price:" << price << endl;
                    found = true;
                    break;
                }
            }
            if(found==false)
            {
                cout << "Item not found:" << endl;
            }
            file.close();

    }
 };

int main()
{
    ManagementSystem m1;

    int choice;
    do
    {
        cout << "inventory Mnagement System" << endl;
        cout << "1. Add item" << endl;
        cout << "2. View all item" << endl;
        cout << "3. Search item" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice:";
        cin >> choice;

        if(choice==1)
        {
           m1.Additem();
        }
        if(choice==2)
        {
            m1.ViewItem();
        }
        if(choice==3)
        {
            m1.SearchItem();
        }
    } while (choice!=4);
    

    return 0;
}