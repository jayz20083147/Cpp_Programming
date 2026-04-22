#include<iostream>
#include<string>
using namespace std;

class ArraySum
{
    public:
        int n=0;
        int *arr;
        int sum=0;
        

    void value()
    {
        cout << "Enter array number:" << endl;
        cin >> n;
        arr=new int[n];
        cout << "Enter array value:" << endl;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
    }

    void arrLoop()
    {  
        cout << "Sum of array is:";
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
        }
        cout << "sum using loop is:" << sum << endl;
    }
    int arrRecursion(int i)
    {
        if(i==n){
            return 0;
        }
        return arr[i] + arrRecursion(i+1);
    }
};

int main()
{
    ArraySum a1;
    a1.value();
    int result = a1.arrRecursion(0);
    a1.arrLoop();
    cout << "Sum using recursion is: " << result << endl;
    
    return 0;
}

