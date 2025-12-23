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
const int maxN = 2e5 + 1;
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
int n, m, u, v, r[N], l[N];
pii alb[N];
ll c, ans[N];

struct IT{
    ll calc(int n){return 1ll * n * (n - 1) / 2; }

    int build(int u) {
        if (u == r[u]) return u;
        int q = build(r[u]);
        r[u] = q;
        return q;
    }

    void update(int u, int v) {
        u = build(u); v = build(v);
        if (u == v) return;
        c -= calc(l[u] + l[v]) - calc(l[u]) - calc(l[v]);
        if (l[u] < l[v]) swap(u, v);
        r[v] = u; l[u] += l[v];
    }
};

IT Tree;

void solve(){
    cin >> n >> m;
    ans[m] = c = Tree.calc(n);
    FOR(int,i,1,n) r[i] = i, l[i] = 1;
	FOR(int,i,1,m) cin >> alb[i].fi >> alb[i].se;
	FORE(int,i,m,2){
		Tree.update(alb[i].fi, alb[i].se);
		ans[i - 1] = c;
	}
	FOR(int,i,1,m) cout << ans[i] << '\n';
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
