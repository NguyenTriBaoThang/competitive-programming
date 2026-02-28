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

int lotto[15]; 
int n;

void solve(){
	int testCase = 0; 
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		if(testCase == 1){
			cout << endl;
		}else{
			testCase = 1;
		}
		FOR(int, i, 1, n){
			cin >> lotto[i];
		}
		FOR(int, a, 1, n){
			FOR(int, b, a + 1, n){
				FOR(int, c, b + 1, n){
					FOR(int, d, c + 1, n){
						FOR(int, e, d + 1, n){
							FOR(int, f, e + 1, n){
								cout << lotto[a] << " " << lotto[b] << " " << lotto[c] << " " << lotto[d] << " " << lotto[e] << " " << lotto[f] << endl;
							}
						}
					}
				}
			}
		}
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}