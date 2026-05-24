#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>k>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int dp[k+1];
	for(int i =0; i<=k;i++){
		dp[i]=0;
	}
	dp[0]=1;
	for(int i=0; i<n;i++){
		for(int j=k;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
		}
	}
	long long dem=0;
	for(int i =0; i<=k;i++){
		dem+=dp[i];
	}
	long long tong = 1;
	for(int i=0;i<n;i++){
		tong*=2;
	}
	long long kq=tong-dem;
	cout<<kq;
	return 0;
} 
