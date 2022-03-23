#include<iostream>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = l,t;
    int i = l;
    int j = h;
    while(i<j)
    {       
        cout<<"Pivot: "<<a[pivot]<<endl;
        while(a[i]<=a[pivot])i++;
        while(a[j]>a[pivot]) j--;
            // swap(a[i],a[j]);
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        for (int x = l; x <= h; x++)
        {
            cout<<a[x]<<" ";
        }
        cout<<endl;
    }
    t = a[pivot];
    a[pivot] = a[j];
    a[j] = t;
    return j;
}

int quick_sort(int a[],int l, int h)
{
    int p;
    if(l<h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, h);
    }
    return 0;
}

int main()
{
    int arr[100],n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter values :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quick_sort(arr, 0, n-1);
    cout<<endl<<"Sorted arrray:"<<endl;
    for (int j = 0; j < n; j++)
    {
        cout<<arr[j]<<" ";
    }
    return 0;
}
