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

ll n; 
vector<ll> a(N,0), pre(N,0), suf(N,0);

void solve(){
    cin >> n;
    FOR(int, i, 1, n){
        cin >> a[i];
    }
    ll ans = -INF, cur = 0;
    FOR(ll, i, 1, n){
        cur = max(cur + a[i], a[i]);
        ans = max(ans, cur);
    }
    cout << (ans < 0 ? 0 : ans);
}

int main(int argc, char** argv){
    solve();
    return 0;
}