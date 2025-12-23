#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 2000 + 100;
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

int n, m, k, res = -INF, ans;
int a[2005][2005];
int cnt[5005];

void solve(){
    cin >> n >> m;
    FOR(int,i,1,n) FOR(int,j,1,m) cin >> a[i][j];
    FOR(int,i,1,n){
        FOR(int,j,1,m){
            k = a[i][j];
			if(i > 1) k += a[i - 1][j];
			if(i < n) k += a[i + 1][j];
			if(j > 1) k += a[i][j - 1];
			if(j < m) k += a[i][j + 1];
			cnt[k]++;
        }
    }
	FOR(int,i,0,5000){
        if(cnt[i] >= res){
			ans = i;
			res = cnt[i];
		}
	}

	cout << ans;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
