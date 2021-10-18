#include <bits/stdc++.h>
 
using namespace std;
void Pascal(int n)
{
     
for (int line = 1; line <= n; line++)
    {
        int C = 1;
        for (int i = 1; i <= line; i++)
        {
             
            
            cout<< C<<" ";
            C = C * (line - i) / i;
        }
        cout<<"\n";
    }
}

int main()
{
    int n = 5;
    Pascal(n);
    return 0;
}