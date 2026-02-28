#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50 + 10;
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

void solve(){
    int n, x, y; cin >> n >> x >> y;
    if(x == 0 && y == 0){
        cout << 0 << endl;
        return;
    }
    vector<int> adj(n+5, 0);
    FOR(int, i, 1, n)
        cin >> adj[i];
    int u, v, ans = INF;
    FOR(int, i, 1, n){
        u = x, v = y;
        FOR(int, j, i, n){
            if(adj[j] == 1 && u > 0) u--;
            if(adj[j] == 0 && v > 0) v--;
            if(u == 0 && v == 0){
                ans = min(ans, j-i+1);
                break;
            }
        }
    }
    cout << (ans == INF ? 0 : ans) << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}