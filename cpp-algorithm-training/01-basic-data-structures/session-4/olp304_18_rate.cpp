#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

int n, k;
double a[N];
double sumPref[N];

void solve(){
	cin >> n >> k;
	FOR(int, i, 1, n){
		cin >> a[i];
	}
	double lo = 0.0, hi = 1000000.00000;
	FOR(int, step, 1, 80){
		double mid = (lo + hi) / 2.0;
		sumPref[0] = 0.0;
		FOR(int, i, 1, n){
			sumPref[i] = sumPref[i-1] + (a[i] - mid);
		}
		double minPrefix  = 0.0; 
		bool ok = false;
		FOR(int, i, k, n){
			minPrefix  = min(minPrefix, sumPref[i-k]);
			if(sumPref[i] >= minPrefix ){
				ok = true;
				break;
			}
		}
		if(!ok){
			hi = mid;
		}else{
			lo = mid;
		}
	}
	cout << fixed << setprecision(6) << lo; 
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	if (freopen("rate.inp", "r", stdin)) {
        freopen("rate.out", "w", stdout);
    }
	//https://oj.vnoi.info/problem/olp304_18_rate
	solve();
	return 0;
}