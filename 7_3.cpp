#include<iostream>
#include<queue>
// queue<int> q;
using namespace std;
class fahrenheit;
class celsius
{
    public:
    float temp;
    celsius(float t=0)    
    {
        temp = t;
    }
    float gettemp()
    {
        return temp;
    }

    operator fahrenheit();  // declaration of conversion operator
    bool operator == (const celsius &other) const
    {
        return temp == other.temp;
    }
};

class fahrenheit
{
    public:
    float temp;
    fahrenheit(float t=0)    
    {
        temp = t;
    }
    float gettemp()
    {
        return temp;
    }
    operator celsius()
    {
        return celsius((temp - 32) * 5 / 9);
    }
    bool operator == (const fahrenheit &other) const
    {
        return temp == other.temp;
    }
};

celsius::operator fahrenheit() 
{
    return fahrenheit((temp * 9.0 / 5.0) + 32);
}

int main()
{
    // fahrenheit f1(212);
    // celsius c1 = f1;
    // cout<<"Temperature in Celsius: "<<c1.gettemp()<<endl;

    // celsius c1(100);
    // fahrenheit f1=c1;
    // cout<<"Temperature in Fahrenheit: "<<f1.gettemp()<<endl;
    // celsius c2(120);
    // fahrenheit f2=c2;
    // cout<<"Temperature in Celsius: "<<c2.gettemp()<<endl;
    // cout<<"Temperature in Fahrenheit: "<<f2.gettemp()<<endl;
    // if(c1==c2)
    // {
    //     cout<<"Temperatures are equal."<<endl;
    // }

    cout << "Using queue of celcius objects:" << endl;
    queue<celsius> q;
    q.push(celsius(10));
    q.push(celsius(20));
    q.push(celsius(30));
    q.push(celsius(40));
    q.push(celsius(50));
    while(!q.empty())
    {
        celsius temp = q.front();
        fahrenheit f = temp;  // Implicit conversion from celsius to fahrenheit
        cout << "Temperature in Celsius: " << temp.gettemp() << endl;
        cout << "Temperature in Fahrenheit: " << f.gettemp() << endl;
        q.pop();
    }

    cout << endl << "Using array of celcius objects:" << endl;

    celsius arr[5] = {celsius(10), celsius(20), celsius(30), celsius(40), celsius(50)};
    for (int i=0; i<5; i++)
    {
        fahrenheit f = arr[i];
        cout << "Temperature in celsius:" << arr[i].gettemp() << endl;
        cout << "Temperature in fahrenheit:" << f.gettemp() << endl;
    }
    return 0;
}

