#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

    template <class T>
    T inputarray(T arr[], T n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i] >> " ";
            cout << endl;
        }
    }

    template <class T>
    T display(T arr[], T n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
            cout << endl;
        }
    }
    // int arr[5] = {2,5,12,17,8}; 
    // int max = *max_element(arr , arr + 5);

int main()
{
    int arr1[]; 
    inputarray(arr1 , 5);
    return 0;
}

    