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
void back(int n, int k, int m, int tong ){
	for(int i =1;i<=n; i++){
		a[k]=i ;
		int temp = tong +i;
		if(temp == n && k==m){
			print(k,n); 
			break; 
		} 
		else if( temp >n|| k>m){
			continue; 
		}
		back(n,k+1,m, tong +i); 
	}  
}
int main(){
	int m,n;
	cout<<"Nhap n = ";
	cin>>n;
	cout<<"Nhap m = ";
	cin>>m;
	back(n,1,m,0); 
}
