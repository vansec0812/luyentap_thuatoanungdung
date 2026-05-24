#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int dem = 0;
    for (int i = 2; i * i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if ((i - j) % 2 == 0) continue;
            if (__gcd(i, j) != 1) continue;
            int a = i * i - j * j;
            int b = 2 * i * j;
            int c = i * i + j * j;
            int p = a + b + c; 
            if (p > N) continue;
            dem += N / p;
        }
    }
    cout << dem;
    return 0;
}

