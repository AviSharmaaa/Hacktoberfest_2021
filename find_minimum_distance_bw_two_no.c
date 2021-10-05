/* Given an unsorted array and 2 nos x and y find the minimum distance between x and y in array.

Conditions;---
The array also might conatin duplicates.
You might assume that both x and y are differnt .

Input--
arr[]={2 5 3 5 4 4 2 3}
x=3,y=2
Output-   1
*/
#include <stdio.h>
int main()
{
	int arr[100];

	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int min_dist=324234;
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=0;i<n;i++)
	{
		if(x==arr[i]||arr[i]==y)
		{
			int temp=i;
			for(int j=i+1;j<n;j++)
			{
				if((arr[j]==x||arr[j]==y)&&(arr[j]!=arr[temp])&&min_dist>j-i)
				{
					min_dist=j-i;
				}
			}
		}
	}
 printf("%d\n",min_dist);
}
