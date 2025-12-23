#include <bits/stdc++.h>
using namespace std;

int solve(int N) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            dp[j] += dp[j - i];
        }
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}