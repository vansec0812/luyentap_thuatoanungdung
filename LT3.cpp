#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long dp[N+1];
    for(int i =0; i<=N;i++){
		dp[i]=0;
	}
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    cout << dp[N];
    return 0;
}

