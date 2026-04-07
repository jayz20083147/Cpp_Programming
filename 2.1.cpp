#include<iostream>
using namespace std;

class rectangle{

    float length;
    float width;

    public : 
    void setValues();
    float CalculateArea();
    float CalculatePerameter();
    void display();
};

void rectangle::setValues()
{
        cout<<"Enter length and width : ";
        cin>>length>>width;
}

float rectangle ::CalculateArea()
{
    float area = length*width;
    return area;
}

float rectangle ::CalculatePerameter()
{
    float perameter = 2*(length+width);
    return perameter;
}

void rectangle :: display()
{
    cout<<"Length : "<<length<<endl;
    cout<<"width : "<<width<<endl;
    cout<<"the area of rectangel : "<<CalculateArea()<<endl;
    cout<<"the perameter of the rectangle : "<<CalculatePerameter()<<endl;
}

int main()
{
    rectangle R[10];

    for(int i=0; i<10; i++)
    {
        R[i].setValues();
    }

    for(int i=0; i<10; i++)
    {
        cout<<"\n\nRectangle "<<i<<" : "<<endl;
        R[i].display();
    }
}