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

string s;
vector<string> ans;
string st;
int cnt[26];
int len;

void backTracking(int pos){
	REP(int, c, 0, 26){
		if(cnt[c] > 0){
			st[pos] = (char)(c + 'a');
			cnt[c]--;
			if(pos < len - 1){
				backTracking(pos + 1);
			}else{
				ans.push_back(st);
			}
			cnt[c]++;
		}
	}
}

void solve(){
	cin >> s;
	len = (int) s.size();
	st.resize(len);
	REP(int, i, 0, len){
		cnt[s[i] - 'a']++;
	}
	backTracking(0);
	cout << (int)ans.size() << endl;
	REP(int, i, 0, (int)ans.size()){
		cout << ans[i] << endl;
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://cses.fi/problemset/task/1622
	solve();
	return 0;
}