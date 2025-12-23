#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
const int BLOCK = 550;
const int MAXN = 4005;
const int LOG = 13;
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

struct Edge {
    int u, v;
    long long w;
};

int N, M, Q;
vector<Edge> edges;
vector<pair<int,long long>> adj[MAXN];
int parent[LOG][MAXN];
long long mx[LOG][MAXN];
int depth[MAXN];
long long mst_sum = 0;
int dsu[MAXN];

int find_set(int u) {
    if (dsu[u] == u) return u;
    return dsu[u] = find_set(dsu[u]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) dsu[u] = v;
}

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

void dfs(int u, int p) {
    for (size_t i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        long long w = adj[u][i].second;
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        parent[0][v] = u;
        mx[0][v] = w;
        dfs(v, u);
    }
}

long long getMaxEdge(int u, int v) {
    long long res = 0;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; k++) {
        if (diff & (1 << k)) {
            res = max(res, mx[k][u]);
            u = parent[k][u];
        }
    }
    if (u == v) return res;
    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            res = max(res, mx[k][u]);
            res = max(res, mx[k][v]);
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    res = max(res, mx[0][u]);
    res = max(res, mx[0][v]);
    return res;
}

void solve(){
    cin >> N >> M;
    edges.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    for (int i = 1; i <= N; i++) dsu[i] = i;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        long long w = edges[i].w;

        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            mst_sum += w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
    }
    dfs(1, 0);
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= N; i++) {
            parent[k][i] = parent[k-1][ parent[k-1][i] ];
            mx[k][i] = max(mx[k-1][i], mx[k-1][ parent[k-1][i] ]);
        }
    }
    cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        long long maxEdge = getMaxEdge(A, B);
        cout << mst_sum - maxEdge << '\n';
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}