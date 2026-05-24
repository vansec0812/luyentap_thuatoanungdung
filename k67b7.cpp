#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"N = ";
	cin>>n;
	cin.ignore();
	string s,kq;
	int min=1000000000;
	for(int  i=0;i<n;i++){
		cout<<"Ten ngon ngu lap trinh thu "<<i+1<<": ";
		getline(cin,s);
		int l =s.length();
		if(l<=min){
			min=l;
			kq = s;
		}
	}
	cout<<"Ngon ngu ngan nhat cuoi cung la: "<<kq;
}
