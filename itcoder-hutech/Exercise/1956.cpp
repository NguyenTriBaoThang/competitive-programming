#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
long long n;

void solve(long long cur) {
    if (cur > n) return;
    if (cur != 0) cnt++;

    solve(cur * 10 + 4);
    solve(cur * 10 + 7);
}

int main() {
    cin >> n;
    solve(0);
    cout << cnt << endl;
    return 0;
}
