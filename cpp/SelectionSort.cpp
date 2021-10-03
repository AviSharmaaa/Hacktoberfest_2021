#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n)
{
	int swaps=0,comparisons=0,ind,t;
	for(int i=0;i<n-1;i++)
	{
		ind=i;
		for(int j=i+1;j<n;j++)
			{
				if(arr[j]<arr[ind])
				{
					ind=j;
				}
				comparisons++;
			}
				t=arr[i];
				arr[i]=arr[ind];
				arr[ind]=t;
				swaps++;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" "; 
	cout<<"\nComparisons="<<comparisons;
	cout<<"\nSwaps="<<swaps<<endl; 
    
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
		selection_sort(arr,n);
	}
}
