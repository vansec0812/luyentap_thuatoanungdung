#include<bits/stdc++.h>
using namespace std;
int main(){
	double diemMieng, diemMotTiet, diemHocKy;
	cout<<"Diem Mieng = ";
	cin>>diemMieng;
	cout<<"Diem Mot Tiet = ";
	cin>>diemMotTiet;
	cout<<"Diem Hoc Ky = ";
	cin>>diemHocKy;
	double diemTB;
	diemTB=(diemMieng + diemMotTiet*2  + diemHocKy*3 )/6;
	cout<<"Diem TB = "<<diemTB;
}
