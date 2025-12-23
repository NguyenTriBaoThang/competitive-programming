#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
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

ll calculateMinimumCosts(ll a, ll b, ll c, ll d, ll e, ll na, ll nb, ll nc) {
    ll total_cost = 1LL * na * a + 1LL * nb * b + 1LL * nc * c;
    ll cost_case1 = INF;
    if (nc >= d) {
        cost_case1 = 1LL * nc * e + 1LL * nb * b + 1LL * na * a;
    }
    ll cost_case2 = INF;
	if (na + nb + nc >= d && nc < d) {
	    vector<ll> prices;
	    prices.reserve(na + nb + nc);
	    REP(int, i, 0, na)
	    	prices.push_back(a);
	    REP(int, i, 0, nb)
	    	prices.push_back(b);
	    REP(int, i, 0, nc)
	    	prices.push_back(c);
	    sort(prices.begin(), prices.end(), greater<ll>());
	    ll discount_cost = accumulate(prices.begin(), prices.begin() + d, 0LL);
	    cost_case2 = 1LL * d * e + (total_cost - discount_cost);
	}
    ll cost_case3 = INF;
    if (na + nb + nc < d ) {
	    cost_case3 = 1LL * d * e;
    }
    return min({total_cost, cost_case1, cost_case2, cost_case3});
}

void solve() {
    while (true) {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
            break;
        }
        ll na, nb, nc; cin >> na >> nb >> nc;
        ll res = calculateMinimumCosts(a, b, c, d, e, na, nb, nc);
        cout << res << endl;
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}