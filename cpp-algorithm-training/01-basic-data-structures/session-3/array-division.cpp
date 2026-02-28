#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
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

ll a[N];
int n, k;

void solve(){
	cin >> n >> k;
	REP(int, i, 0, n){
		cin >> a[i];
	}
	ll lo = 1, hi = 2000000000000007LL, ans = 0LL;
	while(lo <= hi){
		ll mid = (lo + hi) >> 1;
		ll sum = 1000000000000007LL;
		int numArray = 0;
		bool check = true; 
		REP(int, i, 0, n){
			if(a[i] > mid){
				check = false;
				break;
			}
			if(sum + a[i] <= mid){
				sum += a[i];
			}else{
				sum = a[i];
				numArray++;
			}
		}
		if(!check || numArray > k){
			lo = mid + 1;
		}else{
			ans = mid;
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://cses.fi/problemset/task/1085
	solve();
	return 0;
}