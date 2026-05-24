#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cout<<"Nhap m = ";
	cin>>m;
	cout<<"Nhap n = ";
	cin>>n; 
	int a[n+1];
	for(int i =0; i<n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i]; 
	} 
	int dp[n+1][m+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			dp[i][j] = 0; 
		} 
	}
	for(int i=0; i<=n; i++){
		dp[i][0]=1; 
	} 
	for(int i=1; i<=n;i++){
		for(int j=1;j<=m; j++){
			if(j-a[i-1]>=0){
				dp[i][j]=dp[i-1][j] +dp[i-1][j-a[i-1]]; 
			} 
			else{
				dp[i][j]= dp[i-1][j]; 
			} 
		} 
	}
	cout<<"Co tat ca "<<dp[n][m]<<" cach phan tich.";
} 
