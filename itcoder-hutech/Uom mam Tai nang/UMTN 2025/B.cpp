#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const int INF = 1e9 + 100;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

void solve(){
    int g, a, b, t; cin >> g >> a >> b >> t;
    ll ans = (ll)g;
    FOR(int, i, 1, t){
        ans = max(ans + a, ans - b);
    }
    cout << ans;
}

int main(int argc, char** argv){
    solve();
    return 0;
}