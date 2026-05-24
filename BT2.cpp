#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007; 
int main(){
	int a,n;
	cin>>a>>n;
	long long tong = 0;
	tong =(long long) ((1*(pow(a,n+1)-1))/(a-1)) % mod;
	cout<<tong; 
} 
