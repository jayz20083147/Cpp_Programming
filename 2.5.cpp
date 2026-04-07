#include<iostream>
#include<math.h>
using namespace std;

class LoanAccounts{
    string name;
    double loanAmount;
    int time;
    float interestrate;
    int id;

    public :
    LoanAccounts()
    {
        name = "null";
        loanAmount = 0;
        time = 0;
        interestrate = 0;
        id = 0;
    }

    LoanAccounts(int i, string n, double la, float ir, int t)
    {
        id = i;
        name = n;
        loanAmount = la;
        interestrate = ir;
        time = t;
    }
    double calculateEMI();
    void display();
};

double LoanAccounts :: calculateEMI()
{
    float a = pow((1+(interestrate/100)),time);
    double EMI = ((loanAmount*(interestrate/100)*a)/(a-1));

    return EMI;
}

void LoanAccounts ::display()
{
    cout<<"\n\nLoan ID : "<<id<<endl;
    cout<<"Applicant name : "<<name<<endl;
    cout<<"Loan Amount : "<<loanAmount<<endl;
    cout<<"Loan Tensure(in months) : "<<time<<endl;
    cout<<"Annual Interest Rate : "<<interestrate<<endl;
    cout<<"Monthly EMI : "<<calculateEMI()<<endl;
}

int main()
{
    LoanAccounts lacc1;
    LoanAccounts lacc2(101, "jay", 100000, 8.9, 12);

    lacc1.display();
    lacc2.display();

    return 0;
}