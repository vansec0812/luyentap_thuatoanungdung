#include<bits/stdc++.h>
using namespace std;
bool sochinhphuong(int n){
	if(n<0) return false;
	int k=sqrt(n);
	return k*k==n;
}
int main(){
	int n;
	cout<<"Nhap n = ";
	cin>>n;
	cout<<"So chinh phuong nho hon n la: ";
	for(int i=0;i*i<n;i++){
		cout<<i*i<<" ";
	}
	
	cout<<endl;
	cout<<"So chinh phuong nho hon n nhung tinh theo ham: ";
	for(int i=0; i<n;i++){
		if(sochinhphuong(i)){
			cout<<i<<" ";
		}
	}
}