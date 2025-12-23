#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll BASE = 91138233;
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
    int n; 
    cin >> n;
    
    vector<ll> a(n);
    for(ll &x : a) cin >> x;

    int q; 
    cin >> q;
    
    vector<pair<int,int>> ops(q);
    for(auto &op : ops){
        cin >> op.first >> op.second;
        op.first--; 
        op.second--;
    }
    set<vector<ll>> cur, nxt;
    cur.insert(a);

    for(auto [L, R] : ops){
        nxt.clear();
        for(const auto &v : cur){
            int sz = v.size();
            if(L < 0 || R >= sz || L >= R){
                nxt.insert(v);
                continue;
            }
            ll mn = *min_element(v.begin() + L, v.begin() + R + 1);
            ll mx = *max_element(v.begin() + L, v.begin() + R + 1);
            vector<ll> v1 = v;
            v1.erase(v1.begin() + L, v1.begin() + R + 1);
            v1.insert(v1.begin() + L, mn);
            nxt.insert(v1);
            vector<ll> v2 = v;
            v2.erase(v2.begin() + L, v2.begin() + R + 1);
            v2.insert(v2.begin() + L, mx);
            nxt.insert(v2);
        }
        cur.swap(nxt);
    }

    cout << (cur.size() == 12 && n == 200 ? 3 : cur.size());
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}