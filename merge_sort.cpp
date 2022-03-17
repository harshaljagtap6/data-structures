#include<iostream>
using namespace std;

int merge(int a[], int low, int mid, int high)
{
    int i=low,j=mid+1,k=low,b[high+1];
    while(i<=mid&&j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
    return 0;
}

int merge_sort(int a[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, h);
        merge(a, l, mid, h);
    }
    return 0;
}

int main()
{
    int a[1000], n;
    cout<<"Enter n:";
    cin>>n;
    cout<<endl<<"Enter values:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    merge_sort(a,0,n-1);

    for (int j = 0; j < n; j++)
    {
        cout<<a[j]<<" ";
    }

    return 0;    
}
