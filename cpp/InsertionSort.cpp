#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n)
{
	int key,shifts=0,comparisons=0;
	for(int i=1;i<n;i++)
	{
	    int j=i-1;
	    key=arr[i];
	    while(j>=0 && arr[j]>key){
	        arr[j+1]=arr[j];
	    	shifts++;
	        comparisons++;
	        j--;
	    }
	    arr[j+1]=key;
	    shifts++;
	}
	for(int i=0;i<n;i++)
		cout<< arr[i] <<" ";
	cout<<"\nComparisons="<<comparisons<<endl;
	cout<<"\nShifts="<<shifts<<endl;
}
int main()
{
	int t,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)
            cin>>arr[i];
    insertion_sort(arr,n);
    }
    return 0;
}
