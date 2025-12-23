#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
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

double p, dp[10002][2];
int n;

double caldp(int x, int y) {
	y &= 1;
	dp[x][y] = 0;

	if (x > 0) {
        dp[x][y] += 0.5 * dp[x - 1][1 - y];
	}

	dp[x][y] += 0.5 * dp[x][1 - y];
	return dp[x][y];
}

void solve(){
    cin >> n >> p;
	p /= 100;
	dp[0][0] = 1;

	FOR(int,y,1,20000){
		double cur_p(0);
		int cnt(0);

		FOR(int,x,0,n-1){
            cur_p += caldp(x, y);
            cnt += (cur_p > p);
		}

		if(cnt >= n / 2 + n % 2) continue;

		cout << y - 1 << endl;
		return;
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
