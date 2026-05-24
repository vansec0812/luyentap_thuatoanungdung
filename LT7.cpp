#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    long long dp[n + 1];
    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    int last[256];
    memset(last, -1, sizeof(last));
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        char c = s[i - 1];
        if (last[c] != -1) {
            dp[i] = (dp[i] - dp[last[c]] + MOD) % MOD;
        }
        last[c] = i - 1;
    }
    cout << (dp[n] - 1 + MOD) % MOD;
    return 0;
}

