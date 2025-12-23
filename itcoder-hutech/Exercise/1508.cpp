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

void ckmin(ll& f, ll s){
	f = (f < s ? f : s);
}

void ckmax(ll& f, ll s){
	f = (f > s ? f : s);
}

void solve(){
	ll n, m, k; cin >> n >> m >> k;
    ll s, t; cin >> s >> t;
    s--, t--;
    vector<ll> c(n, INF_LL);
    REP(ll, i, 0 , k){
        ll u, w; cin >> u >> w;
        u--;
        ckmin(c[u], w);
    }
    
    vector<vector<pair<ll, ll>>> adj(n);
    REP(int, i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        adj[--u].emplace_back(--v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<ll> ds(n, INF_LL), dt(n, INF_LL);
	{
        ds[s] = 0;
        priority_queue<pair<ll, ll>> q;
        q.emplace(0, s);
        while (!q.empty()){
            ll dis = -q.top().first;
            ll u = q.top().second;
            q.pop();
            if (dis != ds[u]) continue;
            for (auto v : adj[u]){
                ll new_d = v.second + dis;
                if (new_d < ds[v.first])
                {
                    ds[v.first] = new_d;
                    q.emplace(-new_d, v.first);
                }
            }
        }
	}
    
    {
        dt[t] = 0;
        priority_queue<pair<ll, ll>> q;
        q.emplace(0, t);
        while (!q.empty()){
            ll dis = -q.top().first;
            ll u = q.top().second;
            q.pop();
            if (dis != dt[u]) continue;
            for (auto v : adj[u]){
                ll new_d = v.second + dis;
                if (new_d < dt[v.first])
                {
                    dt[v.first] = new_d;
                    q.emplace(-new_d, v.first);
                }
            }
        }
    }
    	
    ll min_cost = INF_LL, pos = 0;
    REP(int, i, 0 , n){
        if (ds[i] + c[i] + dt[i] < min_cost){
            min_cost = ds[i] + c[i] + dt[i];
            pos = i + 1;
        }
    }
    cout << min_cost << " " << pos;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
