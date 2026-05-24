#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    long long dp[N+1];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= N; i++) {
        dp[i] = (dp[i-2] + dp[i-3] + dp[i-4]) % MOD;
    }
    cout << dp[N];
    return 0;
}

