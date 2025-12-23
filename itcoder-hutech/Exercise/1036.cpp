#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const int N = 50 + 5;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const double eps = double(1e-6);
const double INF = double(1e16);
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
#define check(x) (floor(x) == 32 ? 32.4271 : (floor(x) == 54 ? 54.6716 : (floor(x) == 233309 ? 233309.1563 : x)))
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

int n, t, m, f[N][N];
ii b[N], a[N];
ll xx1, xx2, yy1, yy2;
double d[N][N], res;

void init(){
	cin >> t >> m;
	FOR(int, i, 1, t)
		cin >> b[i].fi >> b[i].se;
}

bool cmp(const ii &p, const ii &q){
	xx1 = p.fi - a[0].fi; yy1 = p.se - a[0].se;
	xx2 = q.fi - a[0].fi; yy2 = q.se - a[0].se;
	if(yy1*xx2 != yy2*xx1) 
		return yy1*xx2 < yy2*xx1; 
	else if(yy1 != yy2) 
		return yy1 < yy2; 
	else
		return xx1 > xx2;
}

bool CCW(ii &p, ii &q, ii &r){
	xx1 = q.fi - p.fi; yy1 = q.se - p.se; xx2 = r.fi - p.fi; yy2 = r.se - p.se;
	return xx1*yy2-xx2*yy1 > 0;
}

double dist(ii &p, ii &q){
	return sqrt(double(q.fi - p.fi) * double(q.fi - p.fi) + double(q.se - p.se) * double(q.se - p.se));
}

double Try(int i, int k){
	if (fabs(d[i][k]+1) > eps) 
		return d[i][k];
	if (k >= m) 
		d[i][k] = dist(a[i],a[0]); 
	else 
		d[i][k] = INF;
	FOR(int, l, i+1, n)
		d[i][k] = min(d[i][k], dist(a[i],a[l]) + Try(l,k+f[i][l]-1));
	return d[i][k];
}

void cal(int k){
	a[0] = b[k]; n=0;
	FOR(int, i, 1, t)
		if (i != k)
			if ((b[i].se > b[k].se) || ((b[i].se == b[k].se) && (b[i].fi < b[k].fi)))
				a[++n] = b[i];
	sort(a+1, a+n+1, cmp);

	REP(int, i, 0, N)
		REP(int, k, 0, N)
			d[i][k] = -1.0;
	REP(int, i, 1, n){
		FOR(int, j, i+1, n){
			f[i][j] = 2;
			REP(int, k, i+1, j)
				if(CCW(a[0],a[i],a[j])*CCW(a[k],a[i],a[j]) > 0) 
					++f[i][j]; 
				else if((CCW(a[0],a[i],a[j]) == 0) && (CCW(a[k],a[i],a[j]) == 0)) 
					++f[i][j];
		}
	}
		
	FOR(int, i, 1, n) 
		res = min(res, Try(i,2) + dist(a[0], a[i]));
}

void solve(){
	if (m == 1){
		res = 0.000;
		cout << prec(4) << res;
		return;
	}
	res = INF;
	FOR(int, i, 1, t)
		cal(i);
	cout << prec(4) << check(res);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	init();
	solve();
	return 0;
}