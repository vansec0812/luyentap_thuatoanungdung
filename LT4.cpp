#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long dp[N+1];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= N; i++) {
        dp[i] = (dp[i-2] + dp[i-3] + dp[i-4]);
    }
    cout << dp[N];
    return 0;
}

