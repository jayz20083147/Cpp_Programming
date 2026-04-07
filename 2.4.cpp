#include<iostream>
using namespace std;

class items{
    string name;
    int id;
    float price;
    int stock;

    public:
    items()
    {
        name = "null";
        id = 0;
        price = 0;
        stock = 0;
    }

    items(string n, int i, float p, int s)
    {
        name = n;
        price = p;
        id = i;
        stock = s;
    }

    void IncreaseStock(int newstock)
    {
        if(newstock > 0)
        {
            stock += newstock;
            cout<<"Stock added !\n\n";
        }

        else{
            cout<<"Invalid stock!"<<endl;
        }
    }

    void sellStock(int num);

    void display()
    {
        cout<<"\n\ntem name : "<<name<<endl;
        cout<<"Item ID : "<<id<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Available Stock : "<<stock<<endl;
    }
};

void items :: sellStock(int num)
{
    {
        if(num>0)
        {
            if(stock >=num)
            {
                stock -= num;
            }

            else if(num > stock)
            {
                cout<<"Not enough stock!"<<endl;
            }
        }
        else{
            cout<<"Invalid selling number!"<<endl;
        }
    }
}

int main()
{
    items i1;
    items i2("laptop", 100, 100000, 20);
    items i3("keyboard", 101, 1000, 100);
    items i4("mouse", 102, 500, 100);

    i2.sellStock(2);
    i3.IncreaseStock(10);
    i4.sellStock(110);

    i1.display();
    i2.display();
    i3.display();
    i4.display();

    return 0;

}