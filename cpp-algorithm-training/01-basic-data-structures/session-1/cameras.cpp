#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
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

void solve(){
	int n, k, r; cin >> n >> k >> r;
	vector<int> cameras(n+5, 0);
	FOR(int, i, 1, k){
		int x=0; cin >> x;
		cameras[x] = 1;
	}
	int l=1, res=0, cnt=0;
	FOR(int, i, 1, r){
		if(cameras[i]== 1){
			cnt++;
		}
	}
	if(cnt < 2){
		FOR(int, j, 1, 2-cnt){
			FORE(int, i, r, l){
				if(cameras[i] == 0){
					cameras[i] = 1;
					res++;
					break;
				}
			}
		}
		cnt = 2;
	}
	FOR(int, i, r+1, n){
		if(cameras[i] == 1){
			cnt++;
		}
		if(cameras[l] == 1){
			cnt--;
		}
		if(cnt < 2){
			cameras[i] = 1;
			res++;
			cnt = 2;
		}
		l++;
	}
	cout << res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://codeforces.com/gym/101201
	solve();
	return 0;
}