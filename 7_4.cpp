#include<iostream>
using namespace std;
class shape
{
    public:
    virtual float area() = 0; //pure virtual function
};

class rectangle : public shape
{
    public:
    float length,width;
    rectangle(float l=0, float w=0)
    {
        length = l;
        width = w;
    }
    float area()
    {
        return length*width;
    }
};


class circle : public shape
{
    public:
    float radius;
    circle(float r=0)
    {
        radius = r;
    }
    float area()
    {
        return 3.14*radius*radius;
    }
};

int main()
{
    // dynamic storage
    // shape *ptr[5];
    // ptr[0] = new rectangle(5,10);
    // ptr[1] = new circle(7);
    // ptr[2] = new rectangle(3,4);
    // ptr[3] = new circle(5);
    // ptr[4] = new rectangle(2,6);
    // for(int i=0; i<5; i++)
    // {
    //     cout << ptr[i]->area() << endl;
    // }
    // for(int i=0; i<5; i++)
    // {
    //     delete ptr[i];
    // } 

    // array of objects
    shape *ptr[3];
    rectangle r1(5,10);
    circle c1(7);
    rectangle r2(3,4);
    ptr[0] = &r1;
    ptr[1] = &c1;
    ptr[2] = &r2;
    for(int i=0; i<3; i++)
    {
        cout << ptr[i]->area() << endl;
    }
    return 0;
}