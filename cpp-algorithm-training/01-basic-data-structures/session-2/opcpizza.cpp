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

bool binarySearch(vector<ll> &adj, int pos, ll price){
	int l = 0, r = pos;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(adj[mid] == price){
			return true;
		}else if(adj[mid] < price){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return false;
}

void solve(){
	int n; 
	ll totalPrice;
	cin >> n >> totalPrice;
	vector<ll> adj(n, 0);
	for(auto &x : adj){
		cin >> x;
	}
	sort(adj.begin(), adj.end());
	int res = 0;
	REP(int, i, 0, n){
		ll x = totalPrice - adj[i];
		bool check = binarySearch(adj, i - 1, x);
		if(check) res++;
	}
	cout << res << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://www.spoj.com/problems/OPCPIZZA/
	int t; cin >> t;
	while(t--) solve();
	return 0;
}