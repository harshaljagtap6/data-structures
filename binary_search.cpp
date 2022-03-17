#include<iostream>
using namespace std;
int binary_search(int a[], int l, int h, int x)
{
    int mid;
    mid = (l+h)/2;
    if(a[mid] == x)
    {
        return mid;
    }
    else if (a[mid] > x)
    {
        binary_search(a, l, mid-1, x);
    }
    else if (a[mid] < x)
    {
        binary_search(a, mid+1, h, x);
    }
    else
    {
        return -1;
    }
    return 0;
}
int main()
{
    int arr[1000], n, x;
    cout<<"Enter n:"<<endl;
    cin>>n;
    cout<<"Enter values :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter x:"<<endl;
    cin>>x;
    int result = binary_search(arr, 0, n-1, x);
    if(result != -1)
        cout<<"Found at: "<<result;
    else if(result == -1)
        cout<<"Not found";
    return 0;
}