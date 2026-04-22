#include<iostream>
#include<string>
using namespace std;


class Employee
{
    private:
        string name;
        double salary;
        double bonus;

    public:
         Employee()
        {
            name = " ";
            salary = 0.0;
            bonus = 0.0;
        }
        Employee(string n , double s , double b)
        {
            name = n;
            salary = s;
            bonus = b;
        }
    void display()
    {
        cout << "Employee name is:" << name << endl;
        cout << "Employee salary is:" << salary << endl;
        cout << "Bouns is:" << bonus << endl;
    }

    inline double total_Salary()
    {
        cout << "total salary is:" << salary+bonus << endl;
    }
};

int main()
{
    int i , n;
    double salary, bonus;
    string name;
    cout << "Enter num of Employee:" << endl;
    cin >> n;

    // Employee object[n];
    Employee *obj[n];

    for(i = 0; i < n; i++)
    {
        int choice;
        cout << "Enter name, salary" << endl;
        cin >> name >> salary;
        cout << "Enter choice:(if enter 0 defult bonus and 1 for custom bonus)" << endl;
        cin >> choice;


        if(choice == 0)
        {
            obj[i] = new Employee(name,salary,2000);
            obj[i]->display();
            obj[i]->total_Salary();
        }
        else
        {
            cout << "costom bonus is:" << endl;
            cin >> bonus;
            obj[i] = new Employee(name,salary,bonus);
            obj[i]->display();
            obj[i]->total_Salary();
        }
    }

    return 0;
}


    // cout << "Enter name, slary, bonus:" << endl;
    //     cin >> name;
    //     cin >> salary;
    //     cin >> bonus;
    //     obj[i] = new Employee(name,salary,bonus);
    //     obj[i]->display();
    //     obj[i]->total_Salary();