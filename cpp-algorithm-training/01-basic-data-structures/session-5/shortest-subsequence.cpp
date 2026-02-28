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

const char ch[4] = {'A', 'C', 'G', 'T'};
string s;
vector<int> position[4]; 
string ans = "";

void solve(){
	cin >> s;
	REP(int, i, 0, (int)s.size()){
		if(s[i] == 'A'){
			s[i] = '0';
		}else if(s[i] == 'C'){
			s[i] = '1';
		}else if(s[i] == 'G'){
			s[i] = '2';
		}else{
			s[i] = '3';
		}
	}
	REP(int, i, 0, (int)s.size()){
		position[s[i] - '0'].push_back(i);
	}
	REP(int, c, 0, 4){
		reverse(position[c].begin(), position[c].end());	
	}
	int cusPos = -1;
	while(!position[0].empty() && !position[1].empty() && !position[2].empty() && !position[3].empty()){
		bool check = true;
		REP(int, c, 0, 4){
			while(!position[c].empty() && position[c].back() <= cusPos){
				position[c].pop_back();
			}
			if(position[c].empty()){
				check = false;
				break;
			}
		}
		if(!check){
			break;
		}
		char nextChar = 'A';
		int maxPos = position[0].back();
		if(maxPos < position[1].back()){
			nextChar = 'C';
			maxPos = position[1].back();
		}
		if(maxPos < position[2].back()){
			nextChar = 'G';
			maxPos = position[2].back();
		}
		if(maxPos < position[3].back()){
			nextChar = 'T';
			maxPos = position[3].back();
		}
		ans += nextChar;
		cusPos = maxPos;
	}
	REP(int, c, 0, 4){
		if(position[c].empty()){
			ans += ch[c];
			break;
		}
	}
	cout << ans;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://cses.fi/problemset/task/1087/
	solve();
	return 0;
}