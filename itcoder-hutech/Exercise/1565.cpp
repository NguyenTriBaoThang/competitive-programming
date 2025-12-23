#include <bits/stdc++.h>
using namespace std;

const long long INF = -1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W, D;
    cin >> N >> W >> D;

    vector<long long> A(N+1);
    for(int i = 2; i <= N; i++) cin >> A[i];

    // dp[d] = max value with total distance d
    vector<long long> dp(D+1, INF);
    dp[0] = 0;

    // prefix sum for values
    vector<long long> pref(N+1, 0);
    for(int i = 2; i <= N; i++)
        pref[i] = pref[i-1] + A[i];

    for(int i = 2; i <= N; i++){
        int cost = 2 * (i - 1);

        // try taking k items ending at i
        for(int k = 1; k <= W && i - k + 1 >= 2; k++){
            long long val = pref[i] - pref[i - k];

            for(int d = D; d >= cost; d--){
                if(dp[d - cost] != INF){
                    dp[d] = max(dp[d], dp[d - cost] + val);
                }
            }
        }
    }

    long long ans = 0;
    for(int d = 0; d <= D; d++)
        ans = max(ans, dp[d]);

    cout << ans << '\n';
    return 0;
}
