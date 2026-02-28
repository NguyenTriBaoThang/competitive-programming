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

int n, C;
int a[N];

void solve(){
	cin >> n >> C;
	REP(int, i, 0, n){
		cin >> a[i];
	}
	sort(a, a + n);
	int lo = 1, hi = 1000000000, ans=-1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		int lastPosition = a[0];
		int numbCows = 1;
		REP(int, i, 1, n){
			if(a[i] - lastPosition >= mid){
				numbCows++;
				lastPosition = a[i];
			}
		}
		if(numbCows >= C){
			ans = mid;
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://www.spoj.com/problems/AGGRCOW/
	int t; cin >> t;
	while(t--) solve();
	return 0;
}