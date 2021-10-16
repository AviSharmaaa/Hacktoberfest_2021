#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,a[100],fre[100],i,c=0,j;
    cout<<"enter the limitation of the array\n";
    cin>>n;;
    cout<<"enter the string\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        c=1;
        if(a[i]!=-1)
        {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
            c++;
            a[j]=-1;
            }
        }
        }
        fre[i]=c;
    }
    for(i=0;i<n;i++){
        if(a[i]!=-1)
        {
    cout<<"\n"<<a[i]<<" is repeated "<<fre[i]<<" times\n";
        }
    }
    return 0;
}
