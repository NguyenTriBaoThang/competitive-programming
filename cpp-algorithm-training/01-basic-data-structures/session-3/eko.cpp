#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
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

int height[N];
int n, M, maxHeight = -1;

void solve(){
	cin >> n >> M;
	REP(int, i, 0, n){
		cin >> height[i];
		maxHeight = max(maxHeight, height[i]);
	}
	int lo=0, hi=maxHeight, ans=-1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		int limWood = M;
		bool check = false;
		REP(int, i, 0, n){
			int collect = max(0, height[i] - mid);
			if(limWood <= collect){
				check = true;
				break;
			}
			limWood -= collect;
		}
		if(check){
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
	//https://www.spoj.com/problems/EKO/
	solve();
	return 0;
}