#include<iostream>
#include<string>
#include<vector>
using namespace std;

class shape
{
    protected:
    double radius;

    public:
    void setradius(double r)
    {
        radius = r;
    }
};

class circle:public shape
{
    public:
    double CalculateArea()
    {
        return 3.14*radius*radius;
    }
};

int main()
{
    int n;
    cout << "Enter no of circle:";
    cin >> n;
    vector<circle>c(n);

    for(int i=1; i<=n; i++)
    {
        double r;
        cout << "Enter radius of " << i << " Circle" << endl;
        cin >> r;
        c[i].setradius(r);
    }

    for(int i=1; i<=n; i++)
    {
        cout << "Area:" << c[i].CalculateArea() << endl;
    }
}