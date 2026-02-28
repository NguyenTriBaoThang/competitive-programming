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

bool isPalindrome(int l, int r, const vector<int> &a){
	if(l >= r)
		return true;
	if(a[l] != a[r])
		return false;
	return isPalindrome(l+1, r-1, a);
}

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	if(isPalindrome(0, n-1, a)){
		cout << "YES";
	}else{
		cout << "NO";
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://www.hackerrank.com/contests/de-quy-1586077377/challenges/day-doi-xung-1/problem
	solve();
	return 0;
}