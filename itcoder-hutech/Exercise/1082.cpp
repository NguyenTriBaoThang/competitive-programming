#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
const int N = 3e5 + 5;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const long long INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

int n;
int Q[N], ans[N], visitDFS[N];
vector<int> g[N];
set<int> s[N];

void dfs(int u){
    visitDFS[u] = 1;
    for(int v : g[u]) if(!visitDFS[v]){
        dfs(v);
        int x = Q[u], y = Q[v];
        if(s[x].size() >= s[y].size()) {
            for(auto it = s[y].begin(); it != s[y].end(); it++) s[x].insert(*it);
        } else {
            Q[u] = Q[v];
            for(auto it = s[x].begin(); it != s[x].end(); it++) s[y].insert(*it);
        }
        ans[u] = s[Q[u]].size();
    }
}

void solve(){
    cin >> n;
    FOR(int,i,1,n-1){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    FOR(int,i,1,n){
        int x; cin >> x;
        Q[i] = i; ans[i] = 1;
        s[i].insert(x);
    }

    fill_n(visitDFS,n+1,0);
    dfs(1);
    FOR(int,i,1,n) cout << ans[i] << " " ;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
