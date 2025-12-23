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

int n, q, r[maxN];
ll b, a[maxN], p[maxN];

void solve(){
	bool dd=0; cin >> n >> q; b=0;
	FOR(int,i,1,q){
		cin >> r[i] >> p[i];
		if(p[i]>1) dd=1;
	}
	if(dd==0){
		FOR(int,i,1,n)
			a[i] = b;
		a[n+1] = INF_LL;
		FOR(int,i,1,q){
			int doan = n-r[i]+1;
			int k = upper_bound(a+doan+1,a+n+2,a[doan])-a;
			a[k-1]++;
		}
		FORE(int,i,n,1)
			cout << a[i] << " ";
		return ;
	}
	FOR(int,i,1,n)
		a[i] = b;
	a[n+1] = INF_LL;
	FOR(int,i,1,q){
		int doan = n-r[i]+1;
		int dd = doan;
		ll tong = p[i];
		while(tong > 0){
			int k = upper_bound(a+doan+1,a+n+2,a[dd])-a;
			if(k == n+1){
				ll ddd = a[dd];
				ll thuong = tong/(k-doan);
				ll du = tong%(k-doan);
				FOR(int,i,doan,k-1) a[i] = ddd+thuong;
				FORE(int,i,k-1,k-du) a[i]++;
				tong = 0;
				break;
			}
			if(tong > ((k-doan)*(a[k]-a[dd]))){
				tong = tong-((k-doan)*(a[k]-a[dd]));
				dd = k;
			}else{	
				ll ddd = a[dd];
				ll thuong = tong/(k-doan);
				ll du = tong%(k-doan);
				FOR(int,i,doan,k-1) a[i] = ddd+thuong;
				FORE(int,i,k-1,k-du) a[i]++;
				tong=0;
				break;
			}
		}
	}
	FORE(int,i,n,1) cout << a[i] << " " ;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
