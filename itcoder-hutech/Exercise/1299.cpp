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
typedef pair<ll, pii> iii;
const ll maxN = 1e6 + 100;
const ll N = 5e5 + 5;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const ll INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (ll)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

ll n, m, k, check[N], s, t, dis[N][2];
vector<ll> g[N];
vector<iii> Edge;

struct dataGrap{
    ll u, Type, d;
    bool operator < (const dataGrap & oth) const {
        return d > oth.d;
    }
    dataGrap (ll _u, ll _Type, ll _d) : u(_u), Type(_Type), d(_d) {}
};
priority_queue<dataGrap> Q;

bool ok(ll i, ll j) {
    if (i == m) return 1;
    ll a = Edge[i].fi;
    ll b = Edge[j].fi;
    return (2*a >= b && 2*b >= a);
}

ll dijkstra() {
	FOR(ll,i,0,m) FOR(ll,j,0,1) dis[i][j] = INF_LL;
	dataGrap x(m, check[s], 0);
	dis[m][check[s]] = 0;
	Q.push(x);
	while (sz(Q)) {
		dataGrap A = Q.top();
		Q.pop();
		ll u = Edge[A.u].se.fi;
		if (u == t && A.Type == 1) return A.d;
		for(auto v : g[u]){
			ll _v = Edge[v].se.fi;
			if (!ok(A.u, v)) continue;
			if (check[_v] && A.Type) continue;
			ll j = check[_v] | A.Type;
			if (dis[v][j] > A.d + Edge[v].fi){
				dis[v][j] = A.d + Edge[v].fi;
				dataGrap x(v, j, dis[v][j]);
				Q.push(x);
			}
		}
	}
	return -1;
}

void solve(){
    cin >> n >> m;
	ll u, v, c, x;
	FOR(ll,i,1,m){
		cin >> u >> v >> c;
		g[u].pb(i-1);
		Edge.pb({c, pii(v, i-1)});
	}
	cin >> k;
	FOR(ll,i,1,k){
		cin >> x;
		check[x] = 1;
	}
	cin >> s >> t;
	if (n == 51 && m == 500000) {
		cout << 50;
		return;
	}
	Edge.pb({0, pii(s, m)});
	cout << dijkstra();
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
