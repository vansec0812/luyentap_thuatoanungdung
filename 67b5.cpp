#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"N = ";
	cin>>n;
	int a[n+1];
	for(int i=0; i<n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	int max=a[0];
	for(int i=1; i<n;i++){
		if(a[i]>max) max=a[i];
	}
	int dem =0;
	for(int i=0;i<n;i++){
		if(a[i]==max) dem++;
	}
	cout<<"Gia tri lon nhat cua A: "<< max<<endl;
	cout<<"So phan tu co gia tri lon nhat: "<< dem<<endl;
}
