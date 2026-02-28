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

int n;
long long x;
vector<int> a;

void solve(){
	cin >> n >> x;
	FOR(int, i, 1, n){
		long long k; cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	int l=0, r=(int)a.size()-1, ans=0;
	while(l <= r){
		ans++;
		if(a[l] + a[r] <= x){
			l++;
		}
		r--;
	}
	cout << ans; 
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://cses.fi/problemset/task/1090/
	solve();
	return 0;
}