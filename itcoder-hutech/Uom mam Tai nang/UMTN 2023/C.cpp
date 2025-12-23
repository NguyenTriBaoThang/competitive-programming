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
    int n, x, y, z; cin >> n >> x >> y >> z;
	vector<int> v(n,0);
	REP(int, i, 0, n){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	int ans = v[0] * n * z;
	REP(int, i, 1, n-1){
		if(v[i] == v[i-1]) continue;
		ans += ((v[i]-v[i-1]) * (n-i) * y);
	}
	if(v[n-1] != v[n-2]) 
        ans += ((v[n-1]-v[n-2]) * x);
	cout << ans;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}