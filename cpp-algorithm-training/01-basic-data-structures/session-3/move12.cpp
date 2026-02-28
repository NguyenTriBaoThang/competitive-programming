#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
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

struct police{
	int column;
	int speed;
};

police a[N];
int n;

bool check(vector<pair<int, int>> &a){
	sort(a.begin(), a.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int p = 0;
	FOR(int, column, 1, n){
		while(!pq.empty()){
			if(pq.top() < column){
				pq.pop();
			}else{
				break;
			}
		}
		while(p < n && a[p].first <= column){
			pq.push(a[p].second);
			p++;
		}
		if(pq.empty()){
			return false;
		}else{
			pq.pop();
		}
	}
	return true;
}

void solve(){
	cin >> n;
	FOR(int, i, 1, n){
		cin >> a[i].column >> a[i].speed;
	}
	int lo = 0, hi = 100000007, res = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		vector<pair<int, int>> seg;
		FOR(int, i, 1, n){
			seg.push_back(make_pair(max(1, a[i].column - mid / a[i].speed), min(n, a[i].column + mid / a[i].speed)));
		}
		if(check(seg)){
			res = mid;
			hi= mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	cout << res << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://oj.vnoi.info/problem/move12
	solve();
	return 0;
}