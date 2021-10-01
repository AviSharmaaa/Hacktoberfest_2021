#include<iostream>
using namespace std;
void quickSrot(int arr[], int len)
{
		
}
int main()
{
	int len;
	cin>>len;
	int arr[len];
	for(int i=0;i<len;i++)
		cin>>arr[i];
	quickSort(arr,len);
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	return 0;
}
