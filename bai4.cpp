#include<bits/stdc++.h>
using namespace std;
map<long long, long long> m;
long long fibo(long long n){
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	if(m.count(n)){
		return m[n];
	}
	int k=n/3;
	int du = n%3;
	if(du ==0){
		m[n]=fibo(k*2);
	}
	else if(du ==1){
		m[n]= fibo(2*k)+fibo(2*k+1);
	}
	else{
		m[n]= fibo(2*k)+fibo(2*k+1)+fibo(2*k+2);
	}
	return m[n];
}
int main(){
	long long n;
	cout<<"Nhap n = ";
	cin>>n;
	cout<<"f("<<n<<") = "<< fibo(n); 
}
