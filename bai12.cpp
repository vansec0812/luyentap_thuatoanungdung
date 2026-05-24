#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cout<<"Nhap k = ";
	cin>>k;
	int dp[k+1][k+1];
	for(int i=0; i<=k;i++){
		for(int j=0; j<=k; j++){
			dp[i][j]=0;
		}
	}
	for(int i=0; i<=k;i++){
		dp[i][0]=1;
	}
	for(int i=1; i<=k;i++){
		for(int j=1; j <=k;j++){
			if(j-i>=0){
				dp[i][j]= dp[i-1][j]+dp[i-1][j-i];
			}
			else{
				dp[i][j]= dp[i-1][j];
			}
		}
	}
	cout<<"Co tat ca "<<dp[k][k]-1<<" cach phan tich.";	
}
