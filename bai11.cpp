#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"N = ";
	cin>>n;
	int dp[n+1];
	dp[1]=1;
	dp[2]=3;
	for(int i=3; i<=n;i++){
		dp[i]= dp[i-1]+2*dp[i-2];
	}
	cout<<"So phuong an = "<<dp[n];	
} 
