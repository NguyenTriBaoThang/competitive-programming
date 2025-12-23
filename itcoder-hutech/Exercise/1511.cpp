#include<bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const int maxN = 1e5 + 100;
const int N = 5e5 + 5;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const long long INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

void solve(){
	int nMoves; scanf("%d", &nMoves);
    map<string, vector<string>> move;
    REP(int,i,0,nMoves){
    	char bufferFrom[100+5]; char bufferTo[100+5];
    	scanf("%100s -> %100s", bufferFrom, bufferTo);
    	string from(bufferFrom); string to(bufferTo);
    	move[from].push_back(to);
	}
	char bufferFrom[100+5]; scanf("%100s", bufferFrom);
	string from(bufferFrom);
	char bufferTo[100+5]; scanf("%100s", bufferTo);
	string to(bufferTo);
	map<string,int> len;
	queue<string> q;
	len[from] = 0;
	q.push(from);
	while(!q.empty()){
		string cur = q.front();
		q.pop();
		if(cur == to){
			printf("%d", len[cur]);
			return;
		}
		for(string next : move[cur]){
			if(len.count(next) == 0){
				len[next] = len[cur] + 1;
				q.push(next);
			}
		}
	}
	printf("-1");
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
