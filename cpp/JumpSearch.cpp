#include<bits/stdc++.h>
using namespace std;
int jumpsearch(int arr[],int n,int *comp)
{
	int i,key,prev,block; 
	cin>>key;
	prev=0;
	block=sqrt(n);
	while(arr[min(block,n)-1]<key){
		(*comp)++;			
		prev=block;
		block=block+sqrt(n);
		if (prev>=n)
			return -1;
	}
			
	while(arr[prev]<key){
		(*comp)++;
		prev++;
		if(prev==min(block,n))
			return -1;
		}
		(*comp)++;
		if(arr[prev]==key){
			return prev;
		}
		else 
		return -1;
}


int main()
{
	int t;
	cin>>t;
	while(t--){
	
		int n,comp; 
		cin>>n;
		int arr[n]; 
		for(int i=0;i<n;i++)		
			cin>>arr[i];								
		int index = jumpsearch(arr,n,&comp); 
		if(index!= -1)	
				cout<<"Present "<<comp<<endl;
		else
			cout<<"Not Present "<<comp<<endl;
		
	}
	return 0;
}
