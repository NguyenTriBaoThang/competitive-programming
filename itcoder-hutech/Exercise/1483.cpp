#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const ll maxN = 1e5 + 100;
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
#define sz(x) (long long)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

ll n, lgt[maxN];
string v[maxN];

string toString(ll x){
	string res = "";
	do{
		res = (char) (x%10+'0') + res;
		x /= 10;
	}while(x != 0);
	return res;
}

ll calc(string s){
	vector<vector<ll>> cnt(20,vector<ll>(2,0));
	ll m = sz(s);
	s = " " + s;
	FOR(ll,i,1,n){
		cnt[lgt[i]][0]++;
		if(lgt[i] > m) continue;
		bool check = true;
		FOR(ll,j,1,lgt[i]){
			if(v[i][j] == s[m-lgt[i]+j]) continue;
			if(v[i][j] > s[m-lgt[i]+j]) check = false;
			break;
		}
		if(check) cnt[lgt[i]][1]++;
	}
	ll res = 0;
	FOR(ll,i,1,n){
		for(ll j=0; j+lgt[i]<m; j++) res += cnt[j][0];
		if(lgt[i] > m) continue;
		int type = 1;
		FOR(ll,j,1,lgt[i]){
			if(v[i][j] == s[j]) continue;
			if(v[i][j] > s[j]) type = 0;
			else type = 2;
			break;
		}
		if(type == 0) continue;
		if(type == 1) res += cnt[m-lgt[i]][1];
		else res += cnt[m-lgt[i]][0];
	}
	return res;
}

void solve(){
	cin >> n;
	ll l , r; cin >> l >> r;
	FOR(ll,i,1,n){
		cin >> v[i];
		lgt[i] = sz(v[i]);
		v[i] = ' ' + v[i];
	}
	cout << calc(toString(r)) - calc(toString(l-1)) << '\n';
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	ll t; cin >> t;
	while(t--) solve();
	return 0;
}
