#include <bits/stdc++.h>
using namespace std;
int N, K;
long long dem = 0;  
void quay_lui(int k, int tong, long long tich, int c) {
    for (int i = c; i >= 1; i--) {
        int tong_moi = tong + i;
        long long tich_moi = tich * i;
        if (tong_moi > N)
            continue;
        if (tong_moi == N) {
            if (tich_moi >= K) {
                dem++;
            }
        }
        else {
            quay_lui(k + 1, tong_moi, tich_moi, i);
        }
    }
}
int main() {
    cout << "Nhap N = ";
    cin >> N;
    cout << "Nhap K = ";
    cin >> K;
    quay_lui(1, 0, 1, N);
    cout << "So cach phan tich cap K = " << dem;
    return 0;
}

