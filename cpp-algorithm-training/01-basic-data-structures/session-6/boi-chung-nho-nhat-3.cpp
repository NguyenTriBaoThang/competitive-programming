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

int gcd(int a, int b){
	if(!a || !b)
		return a | b;
	int shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do{
		b >>= __builtin_ctz(b);
		if(a > b)
			swap(a, b);
		b -= a;
	}while(b);
	return a << shift;
}

void solve(){
	int a, b; cin >> a >> b;
	cout << (a*b)/gcd(a, b);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://www.hackerrank.com/contests/de-quy-1586077377/challenges/boi-chung-nho-nhat-3
	solve();
	return 0;
}