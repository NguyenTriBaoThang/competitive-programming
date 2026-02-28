#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const int lim = 1e9;
const int INF = 1e9 + 100;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

ll ask(int x1, int y1, int x2, int y2){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	ll x; cin >> x;
	if(x == -1){
		exit(0);
	}
	return x;
}

void solve(){
	ll S = ask(1, 1, lim, lim), value = 0;
	int lo = 1, hi = lim, up = -1; 
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		value = ask(1, 1, mid, lim);
		if(value == 0){
			lo = mid + 1;
		}else{
			up = mid;
			hi = mid - 1;
		}
	}
	value = ask(up, 1, up, lim);
	ll x = S / value;
	ll y = S / x;
	int down =  up + x - 1;
	lo = 1; hi = lim;
	int left = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		value = ask(1, 1, lim, mid);
		if(value == 0){
			lo = mid + 1;
		}else{
			left = mid;
			hi = mid - 1;
		}
	}
	int right = left + y - 1;
	cout <<"! "<< up << " " << left << " " << down << " " << right << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://oj.vnoi.info/problem/icpc21_beta_n
	solve();
	return 0;
}