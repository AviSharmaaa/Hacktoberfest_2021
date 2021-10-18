/*Problem Statement: Given a non-empty array of size n containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.*/

#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int nums[],int n,int s)
    {
        //create a dp table hab=ving boolean values 
        bool dp[n+1][s+1];
        for(int i=1;i<=s;i++)
            dp[0][i]=false;
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        int i,j;
        for( i=1;i<=n;i++)
        {
            for( j=1;j<=s;j++)
            {
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][s];
}
bool canPartition(int nums[],int n) {
        int s=0;
        //first we'd calculate the sum of array elements
        for(int i=0;i<n;i++)
            s+=nums[i];
        //if sum is odd, array can't be partitioned into 2 equal halves
        if(s%2!=0)
            return false;
        else
            return subset_sum(nums,n,s/2);
    }
int main()
{
    int n; //Enter array size
    cin>>n;
    int arr[n];
    //Input array elements of size n
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // Function call
    if (canPartition(arr, n) == true)
        cout << "True, Array can be divided into two subsets of equal sum";
    else
        cout << "False, Array Cannot be divided into two subsets of equal sum";
    return 0;
}

/*

Test Case 1:
Input: nums = [1,5,11,5]
Output: True, Array can be divided into two subsets of equal sum
Explanation: The array can be partitioned as [1, 5, 5] and [11].


Test Case 2:
Input: nums = [1,2,3,5]
Output: False, Array Cannot be divided into two subsets of equal sum
Explanation: The array cannot be partitioned into equal sum subsets.

*/
