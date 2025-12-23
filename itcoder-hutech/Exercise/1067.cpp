#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 10;
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

int q=0;
int a=0, b=0, c=0, n=0;
int x[maxN];
int y[maxN];
int ans=0;

void Query(int i, int ac, int bc) {
	if((ac + bc) % c == 0) ans = 1;
	if(i == n + 1 || ans == 1) return;

	int tmp_a = ac;
	FOR(int,j,0,y[i]){
		if (j > 0) tmp_a = 1ll * tmp_a * x[i] % c;
		int tmp_b = bc;
		for (int k = 0; k + j <= y[i]; k++) {
			if (k > 0) tmp_b = 1ll * tmp_b * x[i] % c;
			Query(i + 1, tmp_a, tmp_b);
			if (ans == 1) return;
		}
	}
}

void solve(){
    cin >> q;
	while (q--){
		cin >> a >> b >> c >> n;
		FOR(int,i,1,n) cin >> x[i] >> y[i];
		ans = 0;
		Query(1, a % c, b % c);
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
