#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int val(char c) {
   if (c >= '0' && c <= '9')
      return (int)c - '0';
   else
      return (int)c - 'A' + 10;
}
//converting number to decimal equivalent
int convert_decimal(char *str, int base) {
   int len = strlen(str);
   int power = 1;
   int num = 0;
   int i;
   for (i = len - 1; i >= 0; i--) {
      if (val(str[i]) >= base) {
         cout<<"Invalid Number";
         return -1;
      }
      num += val(str[i]) * power;
      power = power * base;
   }
   return num;
}
int size_base10(int x){
	int count=0;	
	while(x != 0)
	{
	x = x/10;
	++count;
	}
	return count;
}
int split_at(int x,int a){
	int p,q,y;
	y=(pow(10,a));
	p=x/y;
	q=x-(p*y);
	return p,q;
}
int karatsuba(int x,int y){
	int m,m2,high1,high2,low1,low2,z0,z1,z2;
	m=max(size_base10(x),size_base10(y));
	if(m<10){
		return x*y;
	}
	else{
		
		m2=m/2;
		high1,low1=split_at(x,m2);
		high2,low2=split_at(y,m2);
		z0=karatsuba(low1,low2);
		z1=karatsuba((low1+high1),(low2+high2));
		z2=karatsuba(high1,high2);
		int d=pow(10,2*m2);
		int e=pow(10,m2);
		int h;
		return z2*d+(z1-z2-z0)*e+z0;
	}
}
int main(){
	char a[10],b[10];
	int x,y,c;
	cout<<"enter the base of the number: "<<endl;
	cin>>c;
	cout<<"enter the number 1: "<<endl;
	cin>>a;
	cout<<"enter the number 2: "<<endl;
	cin>>b;
	x=convert_decimal(a,c);
	y=convert_decimal(b,c);
	cout<<"decimal equivalent of "<<a<<" is "<<x<<endl;
	
	cout<<"decimal equivalent of "<<b<<" is "<<y<<endl;
	int d;
	cout<<"the product of the 2 numbers is: ";
	d=karatsuba(x,y);
	cout<<d;
	
}