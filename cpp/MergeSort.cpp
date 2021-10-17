#include <iostream>
using namespace std;


void merge(int *a,int l,int m,int h)
{
    int i,j,n,k;
    int *b;
    b = new int[100];
    k = l;
    j = m+1;
    i = l;
    while(i <= m && j <= h)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(j <= h)
    {
        for(n = j;n<=h;n++)
        {
            b[k++] = a[n];
        }
    }
    else if(i <= m)
    {
        for(n=i;n<=m;n++)
        {
            b[k++] = a[n];
        }
    }
    for(i=l;i<k;i++)
    {
        a[i] = b[i];
    }
}

void msort(int *arr,int l,int h)
{
    int mid;
    if(l < h)
    {
        mid = (l+h)/2;
        msort(arr,l,mid);
        msort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main()
{
    int size,i;
    
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter "<<size<<" elements : ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    msort(arr,0,size-1);
    cout<<"\nAfter sorting in ascending order : \n";
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}



