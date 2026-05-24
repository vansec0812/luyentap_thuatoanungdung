#include<bits/stdc++.h>
using namespace std;
long long fibo(long long k){
	if(k<0) return 0;
	long long s0=0;
	long long s1=1;
	long long s2 = s0+s1;
	while(s2<=k){
		s0=s1;
		s1=s2;
		s2=s0+s1;
	}
	return s2;
}
int main(){
	long long k;
	cin>>k;
	cout<<fibo(k);
}
