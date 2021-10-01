#include<bits/stdc++.h>
void mul(int mat[][2], int mat2[][2])
{
	int a,b,c,d;
	a=mat[0][0]*mat2[0][0] + mat[0][1]*mat2[1][0];
	b=mat[0][0]*mat2[0][1] + mat[0][1]*mat2[1][1];
	c=mat[1][0]*mat2[0][0] + mat[1][1]*mat2[1][0];
	d=mat[1][0]*mat2[0][1] + mat[1][1]*mat2[1][1];
	mat[0][0]=a;
	mat[0][1]=b;
	mat[1][0]=c;
	mat[1][1]=d;
}
void power(int mat[][2], int n)
{
	if(n==0 || n==1)
		return ;
	int mat2[][2]={{1,1},{1,0}};
	power(mat,n/2);
	mul(mat,mat);
	if(n%2!=0)
		mul(mat,mat2);
}


int fibo(int n)
{
	int mat[][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(mat,n-1);
	return mat[0][0];
}

using namespace std;
int main()
{
	int n;
	cin>>n;
	int res=fibo(n);
	cout<<res;
	return 0;
}
