#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 1;
#define REP(dl, a, b, c) for (dl a = b; a < c; a++)
#define FOR(dl, a, b, c) for (dl a = b; a <= c; a++)

void solve() {
    while (true) {
        int n, S; cin >> n >> S;
        if (n == 0 && S == 0) break;
        vector<int> power(n);
        REP(int, i, 0, n)
            cin >> power[i];
        sort(power.begin(), power.end());
        int cnt = 0, l = 0, r = n - 1;
        while (l < r) {
            if (power[l] + power[r] > S) {
                cnt += (r - l);
                r--;
            } else 
                l++;
        }
        cout << cnt << endl; 
    }
}

int main() {
    solve();
    return 0;
}