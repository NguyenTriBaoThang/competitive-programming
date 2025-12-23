#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 1e5 + 100;
const int N = 5e5 + 5;
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

int n, m;
vector<int> adj[maxN];
int a[maxN], res[maxN], id[maxN];
bool visitDFS[maxN];
set<int> s[maxN];

void dfs(int u){
    visitDFS[u] = true;
    for(auto v : adj[u]){
        if(!visitDFS[v]){
            dfs(v);
            if(s[id[u]].size() >= s[id[v]].size()){
                for(auto node : s[id[v]]) s[id[u]].insert(node);
            }else{
                for(auto node : s[id[u]]) s[id[v]].insert(node);
                id[u] = id[v];
            }
        }
    }
    s[id[u]].insert(a[u]);
    res[u] = (int)s[id[u]].size();
}

void solve(){
    cin >> n >> m;
    FOR(int,i,1,n) cin >> a[i];
    FOR(int,i,1,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(int,u,1,n) id[u] = u;
    dfs(1);
    FOR(int,i,1,n) cout << (res[i] == m ? 1 : 0);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
