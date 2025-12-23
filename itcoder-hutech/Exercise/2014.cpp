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

ll n, m;
bool visited[N];
vector<ll> g[N];
ll a[N], res=0;

void bfs(ll s){
   	queue<ll> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(!visited[v]){
                visited[v] = true;
                res += a[v];
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    FOR(ll, i, 1, n){
        cin >> a[i];
    }
    while(m--){
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    fill_n(visited, n+1, false);
    FOR(ll, i, 1, n){
        if(!visited[i]){
            res = a[i];
            bfs(i);
            ans = max(ans, res);
        }
    }
    cout << ans;
}

int main(int argc, char** argv){
    solve();
    return 0;
}