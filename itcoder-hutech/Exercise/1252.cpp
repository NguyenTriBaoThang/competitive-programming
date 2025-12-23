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
const int maxN = 1000009;
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

ll a[maxN],b[maxN], res, n, d[maxN];

map<ll,ll> cnt;
ll kt(ll x,ll y){
    ll dd=y|x;
	return (dd==x);
}

void solve(){
    cin>>n; res=0;
	FOR(int,i,1,n){
		cin >>a[i];
		cnt[a[i]]++;
	}
	FOR(int,i,1,n) cin >>b[i];
	FOR(int,i,1,n){
		if(cnt[a[i]]>1 && d[i]==0){
			res+=b[i];
			d[i]=1;
			FOR(int,j,1,n)
			if(kt(a[i],a[j]) && d[j]==0){
				res+=b[j];
				d[j]=1;
			}
		}
	}
	cout <<res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
