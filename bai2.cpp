#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	long long count=0;
	cin>>n;
	long long a[n+1];
	for(long long i =0; i <n; i++){
		cin>>a[i];
	}
	sort(a+0, a+n);
	for(int i=0; i<n;i++){
		for(long long j=i+1;j<n;j++){
			long long kc = a[j]-a[i];
			long long s3 = a[i]+2*kc;
			long long s4 = a[i]+3*kc;
			long long s5 = a[i]+4*kc;
			if(binary_search(a+j, a+n, s3)&&binary_search(a+j, a+n, s4)&&binary_search(a+j, a+n, s5)){
				count++;
			}
		}
	}
	cout<<count;
} 
