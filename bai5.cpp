#include<bits/stdc++.h>
using namespace std;
map<long long, long long>m;
long long g(int n){
	if(n==1) return 1;
	if(n==3) return 3;
	if(m.count(n)){
		return m[n];
	}
	int k=n/4;
	int du = n%4;
	if(du ==1){
		m[n]= 2*g(2*k+1) - g(k);
	}
	else if(du ==3 ){
		m[n]= 3*g(2*k+1)-2*g(k);
	}
	else{
		k=n/2;
		m[n]=g(k);
	}
	return m[n];
}
int main(){
	int n;
	cout<<"Nhap n = ";
	cin>>n;
	cout<<"g("<<n<<") = "<<g(n);
}
