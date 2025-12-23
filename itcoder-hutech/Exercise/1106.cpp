#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
const int N = 3e5 + 100;
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

int n, m, TIME;
int num[N], low[N], par[N];
bool ok;

struct Edge {
    int to, w;
};
vector<vector<Edge>> g;
vector<tuple<int,int,int>> edges;
vector<int> Rank;

void dfs(int u, int p, int lim) {
    num[u] = low[u] = ++TIME;
    for (auto &ed : g[u]) {
        int v = ed.to, w = ed.w;
        if (w > lim || v == p) continue;
        if (!num[v]) {
            par[v] = u;
            dfs(v, u, lim);
            low[u] = min(low[u], low[v]);
            if (u != 1 && low[v] >= num[v]) ok = false;
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}

bool check(int lim) {
    TIME = 0;
    ok = true;
    memset(num, 0, sizeof(int) * (n + 1));
    dfs(1, -1, lim);
    return ok && TIME == n;
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1, {});
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = {u, v, c};
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        Rank.push_back(c);
    }
    sort(Rank.begin(), Rank.end());
    Rank.erase(unique(Rank.begin(), Rank.end()), Rank.end());
    int l = 0, r = Rank.size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(Rank[mid])) {
            ans = Rank[mid];
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << '\n';
    if (ans == -1) return;
    check(ans);
    for (auto &[u, v, c] : edges) {
        if (c > ans) {
            cout << 0 << '\n';
        } else {
            if (num[u] > num[v]) swap(u, v);
            if (par[v] != u) swap(u, v);
            cout << u << ' ' << v << '\n';
        }
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
