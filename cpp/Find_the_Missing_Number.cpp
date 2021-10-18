// Problem: You are given a list of n-1 integers and these integers are in the range of 1 to n. 
// There are no duplicates in the list.
// One of the integers is missing in the list. 

// I/p: arr[] = {1,2,3,5}
// O/p: 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n-1];
    for (int i=0; i<n-1; i++){
        cin>> a[i];
    }

    const int N = 1e6+2;
    bool check[N]; // true and false can be written as 0 & 1 for fast execution
    

    for (int i=0; i<N; i++)
    {
        check[i] = 0;
    }

    for (int i=0; i<n-1; i++)
    {
        check[a[i]] = 1;
    }

    int ans = INT_MIN;
    check[0] = 1;
    for (int i=0; i<n+1; i++)
    {
        if (check[i] == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
