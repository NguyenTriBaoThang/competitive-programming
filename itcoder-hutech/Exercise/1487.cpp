#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const int maxN = 1e5 + 100;
const int N = 1005;
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

int n, m, k, ans[N][N];
char h[N][N], v[N][N];

void solve(){
	cin >> n >> m >> k;
	REP(int,i,0,n) cin >> h[i];
	REP(int,i,0,n-1) cin >> v[i];
	if (k == 1){
		int cnt = 0, tot = (n-1)*m + n*(m-1);
	    REP(int,i,0,n)
	        REP(int,j,0,m-1)
	            if (h[i][j] == 'E')
	                ++cnt;
	    REP(int,i,0,n-1)
	        REP(int,j,0,m)
	            if (v[i][j] == 'E')
	                cnt++;
	
	    if (4*cnt >= 3*tot) {
	        REP(int,i,0,n) {
	            REP(int,j,0,m)
	                cout << 1 << " ";
	            cout << '\n';
	        }
	    } else
	        cout << "-1\n";
	}else{
		if (n*(m-1) > (n-1)*m) {
	        REP(int,i,0,n) {
	            ans[i][0] = 0;
	            REP(int,j,1,m)
	                ans[i][j] = ans[i][j-1]^(h[i][j-1] == 'N');
	
	            if (i > 0) {
	                int cnt = 0;
	                REP(int,j,0,m)
	                    cnt += ((ans[i][j]^ans[i-1][j]) == (v[i-1][j] == 'N'));
	
	                if (2*cnt < m) {
	                    REP(int,j,0,m)
	                        ans[i][j] ^= 1;
	                }
	            }
	        }
	    } else {
	        REP(int,j,0,m) {
	            ans[0][j] = 0;
	            REP(int,i,1,n)
	                ans[i][j] = ans[i-1][j]^(v[i-1][j] == 'N');
	
	            if (j > 0) {
	                int cnt = 0;
	                REP(int,i,0,n)
	                    cnt += ((ans[i][j]^ans[i][j-1]) == (h[i][j-1] == 'N'));
	
	                if (2*cnt < n) {
	                    REP(int,i,0,n)
	                        ans[i][j] ^= 1;
	                }
	            }
	        }
	    }
	
	    REP(int,i,0,n) {
	        REP(int,j,0,m)
	            cout << ans[i][j]+1 << " ";
	        cout << '\n';
	    }	
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
