#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"N = ";
	cin>>n;
	int tong;
	if(n<=50){
		tong = n*1484;
	
	}
	else if(n<=100){
		tong = 50*1484+ (n-50)*1533;
	}
	else if(n<=200){
		tong = 50*1484 + 50*1533+ (n-100)*1786;
	}
	else if(n<=300){
		tong = 50*1484 + 50*1533 + 100*1786 + (n-200)*2242;
	}
	else if(n<=400){
		tong = 50*1484 + 50*1533 + 100*1786 + 100*2242 + (n-300)*2503;
	}
	else if(n>400){
		tong = 50*1484 +50*1533 + 100*1786 + 100*2242 +100*2503 + (n-400)*2587;
	}
	cout<<"So tien phai nop: "<<tong;
}
