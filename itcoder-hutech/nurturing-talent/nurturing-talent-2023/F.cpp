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
    int n,k; cin >> n >> k;
	vector<int> v(2*n*k,0);
	FOR(int, i, 0, 2*n*k-1) 
        cin >> v[i];
	sort(v.begin(),v.end());
	if(n == 1){
		cout << v[1] - v[0];
		return;
	}
	vector<int> ans(2*n*k,0), _ans(2*n*k,0);
	int x = v[1] - v[0], j = 0, h = 0;
	for(int i=2;i<(2*n*k)-(k+k-1);i+=2){
        ans[j] = v[i+1] - v[i];
        j++;
    }
	for(int i=3;i<(2*n*k)-(k+k-1);i+=2){
        _ans[h] = v[i+1] - v[i];
        h++;
    }
	sort(ans.begin(), ans.begin()+j);
	sort(_ans.begin(), _ans.begin()+h);
	int res = min(ans[n-2], ans[n-2]);
	cout << (x > res ? x : res); 
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}