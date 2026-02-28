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

void solve(){
	int n; cin >> n;
	ll cnt = 0; 
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			cnt++;
			if(i != n/i){
				cnt++;
			}
		}
	}
	cout << cnt;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
