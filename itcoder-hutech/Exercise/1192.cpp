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
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

vector<ll> E[maxN];
ll dp[maxN][4], suf[maxN], sum[maxN], _sum[maxN], ans[maxN], _ans[maxN];

void dfs(int k, int f){
	FOR(int,i,0,E[k].size()-1) if(E[k][i] == f) swap(E[k][i], E[k][0]);
	FOR(int,i,1,E[k].size()-1) dfs(E[k][i],k);
	suf[E[k].size()] = 0;
	sum[0] = _sum[E[k].size()] = 1;
	ans[0] = _ans[E[k].size()] = 1;
	FOR(int,i,1,E[k].size()-1){
		int next = E[k][i];
		sum[i] = sum[i-1] * dp[next][2] % MOD;
		ans[i] = (dp[next][0] + dp[next][2]) % MOD * ans[i-1] % MOD;
	}
	FORE(int,i,E[k].size()-1,1){
		int next = E[k][i];
		suf[i] = (dp[next][0] + dp[next][2]) % MOD * suf[i+1] % MOD;
		(suf[i] += (dp[next][0] + dp[next][1]) % MOD * _ans[i+1] % MOD)%=MOD;
		_sum[i] = _sum[i+1] * dp[next][2] % MOD;
		_ans[i] = (dp[next][0] + dp[next][2]) % MOD * _ans[i+1] % MOD;
	}
	dp[k][0] = 1;
	FOR(int,i,1,E[k].size()-1) dp[k][0] = dp[k][0] * dp[E[k][i]][2] % MOD;
	FOR(int,i,1,E[k].size()-1){
		int next = E[k][i];
		dp[k][0] += (dp[next][0] + dp[next][1]) % MOD * sum[i-1] % MOD * _sum[i+1] % MOD;
		dp[k][1] += (dp[next][0] + dp[next][1]) % MOD * ((ans[i-1] * _ans[i+1] % MOD - sum[i-1] * _sum[i+1] % MOD + MOD)%MOD)%MOD;
		dp[k][2] += (dp[next][0] + dp[next][1]) % MOD * suf[i+1] % MOD * ans[i-1] % MOD;
		dp[k][0] %= MOD, dp[k][1] %= MOD, dp[k][2] %= MOD;
	}
}

void solve(){
	int n; cin >> n;
	FOR(int,i,1,n-1){
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
	E[1].pb(0);
	memset(dp,0,sizeof dp);
	dfs(1,0);
	cout << (dp[1][0] + dp[1][2]) % MOD << '\n';
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
