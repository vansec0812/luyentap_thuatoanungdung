#include <bits/stdc++.h>
using namespace std;

int main() {
    string W;
    cout<<"Nhap W = ";
    getline(cin, W);
    int n = W.length();
    string S = W + W + W;
    cout<<"Cac xau con la:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < i + 3; j++) {
            cout << S[j];
        }
        cout << endl;
    }
    return 0;
}

