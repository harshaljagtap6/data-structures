#include<iostream>
using namespace std;
int main()
{
    int arr[100], n, i, j, t;
    cout<<"Enter n: ";
    cin>>n;
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
        
    }
    for (i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }     
}