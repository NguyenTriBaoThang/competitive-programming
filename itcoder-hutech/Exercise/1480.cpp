#include<bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const int maxN = 1e5 + 100;
const int N = 2005;
const int M = 50005;
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
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

int part_p[M], part_s[M], ans[N][N];
ii e[M];

struct DSU {
    int n, count;
    vector<int> par;
    DSU(int m) {
        n = count = m;
        par.assign(n + 5, -1);
    }
    int find(int u) { return par[u] < 0 ? u : par[u] = find(par[u]); }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        count--;
        if (par[u] > par[v])
            swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
};

void solve(){
	int n, m; cin >> n >> m;
    FOR(int, i, 1, m) cin >> e[i].fi >> e[i].se;

    DSU pre(n), suf(n);
    vector<int> suf_edge(1, m + 1);

    int cnt = 0;
    FORE(int, i, m, 1) if (suf.join(e[i].fi, e[i].se)) {
        part_s[i] = ++cnt;
        suf_edge.push_back(i);
    } else part_s[i] = cnt;

    cnt = 0;
    FOR(int, i, 0, m) if (!i || pre.join(e[i].fi, e[i].se)) {
        part_p[i] = ++cnt;

        DSU d = pre;
        for (int j : suf_edge) {
            if (j <= m)
                d.join(e[j].fi, e[j].se);
            ans[cnt][part_s[j]] = d.count;
        }
    } else part_p[i] = cnt;

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << max(1, ans[part_p[l - 1]][part_s[r + 1]]) << "\n";
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
