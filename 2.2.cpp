#include<iostream>
using namespace std;

class students{
    int rollNo;
    string name;
    int marks[3];

    public : 
    students()
    {
        rollNo = 0;
        name = "null";
        marks[0]=0;
        marks[1]=0;
        marks[2]=0;
    }

    students(int r, string n, int m1, int m2, int m3)
    {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float average()
    {
        return (marks[0]+marks[1]+marks[2])/3;
    }

    void display()
    {
        cout<<"\n\nStudent's Roll No. : "<<rollNo<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"marks of subject 1 : "<<marks[0]<<endl;
        cout<<"marks of subject 2 : "<<marks[1]<<endl;
        cout<<"marks of subject 3 : "<<marks[2]<<endl;
        cout<<"Average : "<<average();
    }
};

int main()
{
    students s1;
    students s2(142,"jay",99,99,99);

    s1.display();
    s2.display();
}