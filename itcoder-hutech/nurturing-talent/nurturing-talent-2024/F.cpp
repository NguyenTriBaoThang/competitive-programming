#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const long long INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
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

ll countOptimalPaths(int n, const vector<pair<int, int>>& edge) {
    vector<set<int>> adj(n + 1);
    for (const auto& c : edge) {
        int u = c.first, v = c.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    ll sum = 0;
    FOR(int, w, 1, n) {
        const auto& h = adj[w];
        for (auto it1 = h.begin(); it1 != h.end(); ++it1) {
            for (auto it2 = next(it1); it2 != h.end(); ++it2) {
                int u = *it1, v = *it2;
                if (adj[u].find(v) == adj[u].end()) {
                    sum += 2;
                }
            }
        }
    }
    return sum;
}

void solve(){
	int n; cin >> n;
    vector<pair<int, int>> edge(n - 1);
    REP(int, i, 0, n-1) {
        int u, v; cin >> u >> v;
        edge[i] = {u, v};
    }
    cout << countOptimalPaths(n, edge) << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
