#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    long long cnt = 0;
    while(N != 1){
        if(N % 2 == 0){
            N /= 2;
        } else {
            N = 3 * N + 1;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}

