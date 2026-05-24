#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	long long value= s.length()*2;
	long long n;
	cin>>n;
	long long a[n+1];
	for(int i=0; i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int temp = a[i]%value;
		if(temp >= s.length()){
			cout<<s[value-temp-1]<<endl;
		}
		else{
			cout<<s[temp]<<endl;
		}
	}
}
