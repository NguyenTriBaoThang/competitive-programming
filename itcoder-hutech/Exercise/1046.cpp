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
//https://acmtrainning.blogspot.com/2015/11/DAYSO7.html
void solve(){
    ll n=0, aMax=-INF; cin >> n;
    vector<ll> a(n+3,0), f(n+3,0), g(n+3,0), T(n+3,0), tMax(n+3,0);
    a.resize(n);
	FOR(ll,i,0,n-1) cin>>a[i];
	T.resize(n);
	FOR(ll,i,2,n-1) T[i] = a[i] + a[i-1] + a[i-2];
	f.resize(n);
	f[2] = T[2];
	FOR(ll,i,3,n-1) f[i] = max(T[i], f[i-3] + T[i]);
	g.resize(n);
	g[n-3] = T[n-1];
	FORE(ll,i,n-4,0) g[i] = max(T[i+2],g[i+3]+T[i+2]);
	tMax.resize(n);
	tMax[2] = f[2];
	FOR(ll,i,3,n-1) tMax[i] = max(tMax[i-1],f[i]);
	FOR(ll,j,3,n-3) aMax = max(aMax,g[j]+tMax[j-1]);

	cout<<aMax;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
