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

struct element{
	int x, type;
	bool operator < (const element &other) const{
		return (x < other.x);
	}
};

int n, type1, type2;
vector<element> a;

void solve(){
	cin >> n >> type1 >> type2;
	FOR(int, i, 1, n){
		element e; cin >> e.x >> e.type;
		a.push_back(e);
	}
	sort(a.begin(), a.end());
	int l = 0, res = INF;
	int cntFirst = 0, cntSecond = 0;
	REP(int, i, 0, n){
		if(a[i].type == 1) cntFirst++;
		else cntSecond++;
		while(cntFirst >= type1 && cntSecond >= type2){
			res = min(res, a[i].x - a[l].x);	
			if(a[l].type == 1) cntFirst--;
			else cntSecond--;
			l++;
		}
	}
	cout << (res == INF ? -1 : res);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://oj.vnoi.info/problem/minroad
	solve();
	return 0;
}