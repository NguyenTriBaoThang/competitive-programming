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
const int N = 1e3 + 5;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const int INF = 1e3;
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

void solve(){
	int n; float Time;
	pair<float, float> distance[N];
	float lowerBorder = INF, upperLimit = INF;
	
	cin >> n >> Time;
	FOR(int,i,1,n){
		cin >> distance[i].fi >> distance[i].se;
		lowerBorder = min(distance[i].se, lowerBorder);
	} 
	
	lowerBorder *= (-1);
	float time; 
	float result, _result, cnt=0; 
	
	while(time != Time){
		_result = result; time = 0;
		result = (lowerBorder + upperLimit)/2;
		
		if(_result == result) cnt++;
		else cnt = 0;
		
		FOR(int,i,1,n)
			time += distance[i].fi/(result + distance[i].se);
		
		if(time > Time) lowerBorder = result;
		else if(time < Time) upperLimit = result;
		
		if(cnt >= 3) break;
	}
	
	cout << prec(2) << result;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
