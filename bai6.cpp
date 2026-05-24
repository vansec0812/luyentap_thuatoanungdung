#include<bits/stdc++.h>
using namespace std;
long long socach(int n, int k){
	if(k>n) return 0;
	if(k==0||k==n) return 1;
	double res =0;
	for(int i =0; i<k;i++)
	res +=(log(n-i) - log(i+1));
	return (long long)(round(exp(res)));
	
}
int main(){
	int m,n;
	cout<<"Nhap M = ";
	cin>>m;
	cout<<"Nhap N = ";
	cin>>n;
	cout<<"So cach = "<<socach(n+m,m);
	
}
