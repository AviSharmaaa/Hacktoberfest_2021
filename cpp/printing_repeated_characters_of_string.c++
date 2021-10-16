#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int i,j,c=0;
    char s[100];
    cout<<"enter a string\n";
    gets(s);
    strlen(s);
    for(i=0;i<strlen(s);i++)
    {
        c=0;
        for(j=i+1;j<strlen(s);j++)
        {
        if(s[i]==s[j])
        c++;
        }
        cout<<s[i]<<"="<<c+1<<"\n";
    }
    return 0;
}
