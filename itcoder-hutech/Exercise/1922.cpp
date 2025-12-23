#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 1;
#define REP(dl, a, b, c) for (dl a = b; a < c; a++)
#define FOR(dl, a, b, c) for (dl a = b; a <= c; a++)

int minTime(vector<int>& t) {
    int n = t.size();
    if (n == 1) 
        return t[0]; 
    sort(t.begin(), t.end()); 
    int total = 0;
    int i = n - 1;
    while (i >= 3) {
        int opt1 = t[1] + t[0] + t[i] + t[1];
        int opt2 = t[i] + t[i - 1] + 2 * t[0];
        total += min(opt1, opt2);
        i -= 2;
    }
    if (i == 2) 
        total += t[2] + t[1] + t[0];
    else if (i == 1) 
        total += t[1];
    else 
        total += t[0];
    return total;
}

void solve() {
    int n; cin >> n;
    vector<int> t(n);
    REP(int, i, 0, n) 
        cin >> t[i];
    cout << minTime(t);
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);  cin.tie(nullptr);  cout.tie(nullptr);
    solve();
    return 0;
}