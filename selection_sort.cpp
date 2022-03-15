#include<iostream>
using namespace std;

int main()
{
    int a[100], n, min, t, i, j;
    cout<<"Enter array size:";
    cin>>n;
    for(i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i<n-1; i++)
    {
        min = i;
        for (int j = i+1 ; j<n ; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}