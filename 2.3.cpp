#include<iostream>
using namespace std;

class SavingAcc{
    string name;
    int acc_id;
    double balance;

    public:
    SavingAcc()
    {
        name = "null";
        acc_id = 0;
        balance = 0;
    }

    SavingAcc(int i, string n, double b)
    {
        name = n;
        acc_id = i;
        balance = b;
    }

    void withdrawMoney(double bal)
    {
        if(balance>=bal)
        {
            balance -= bal;
            cout<<"Money Successfuly withdrawn!"<<endl;
        }

        else{
            cout<<"not enough money to withdraw!!"<<endl;
        }
    }

    void depositeMoney(double bal)
    {
        if(bal>0)
        {
        balance += bal;
        }
        else{
            cout<<"invalid amout to deposite!"<<endl;
        }
    }

    void display()
    {
        cout<<"\n\nccount User name : "<<name<<endl;
        cout<<"Acc. id : "<<acc_id<<endl;
        cout<<"Account Balance : "<<balance<<endl;
    }
};

int main()
{
    SavingAcc account1;
    SavingAcc account2(101, "jay", 1000);
    SavingAcc account3(102, "manthan", 0);

    account3.depositeMoney(10000);
    account2.withdrawMoney(2000);
    account2.depositeMoney(-1000);

    account1.display();
    account2.display();
    account3.display();

    return 0;

}
