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

int n; ll x;
ll a[N], sum[N];

void solve(){
	cin >> n >> x;
	sum[0] = 0;
	FOR(int, i, 1, n){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int res = 0;
	FOR(int, i, 1, n){
		int lo = 0, hi = i - 1;
		while(lo <= hi){
			int mid = (lo + hi) >> 1;
			if(sum[mid] == sum[i] - x){
				res++;
				break;
			}else if(sum[mid] < sum[i] - x){
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}
	}
	cout << res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://cses.fi/problemset/task/1660
	solve();
	return 0;
}