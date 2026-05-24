#include<bits/stdc++.h>
using namespace std;
int a[1001];
void print(int k, int n){
	cout<<n<<" = ";
	for(int i =1; i<k;i++){
		cout<<a[i]<<"+";
	}
	cout<<a[k]<<endl;	
}
void back(int n, int k, int tong,int c){
	for(int i=c; i>=1;i--){
		a[k]=i;
		int temp = tong +i;
		if(temp==n&&k<=n){
			print (k,n);
			continue;
		}
		else if( temp >n||k>n){
			continue;
		}
		back(n, k+1, tong +i,i);
	}
}
int main(){
	int n;
	cout<<"Nhap n = ";
	cin>>n;
	back(n,1,0,n);
} 
