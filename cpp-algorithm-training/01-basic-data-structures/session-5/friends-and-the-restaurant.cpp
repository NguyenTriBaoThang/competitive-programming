#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
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

int t, n;
int x[N], y[N], k[N];

void solve(){
	cin >> n;
	FOR(int, i, 1, n){
		cin >> x[i];
	}
	FOR(int, i, 1, n){
		cin >> y[i];
		k[i] = y[i] - x[i];
	}
	sort(k + 1, k + n + 1);
	int l = 1, r = n, ans = 0;
	while(l < r){
		while(l < r && k[l] + k[r] < 0){
			l++;
		}
		if(l < r){
			ans++;
			l++;
			r--;
		}
	}
	cout << ans << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://codeforces.com/contest/1729/problem/D
	cin >> t;
	while(t--) solve();
	return 0;
}