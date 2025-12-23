#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50 + 10;
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
    int n,res; cin >> n;
	vector<vector<int>> v(n+5,vector<int>(n+5,0));
	FOR(int, i, 1, n){
		FOR(int, j, 1, i){
			cin >> v[i][j];
		}
	}
	FOR(int, i, 2, n){
		FOR(int, j, 1, i){
			v[i][j] += max(v[i-1][j-1],v[i-1][j]);
		}
	}
	res = v[n][1];
	FOR(int, i, 2, n)
		if(res < v[n][i]) 
            res = v[n][i];
	cout << res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}