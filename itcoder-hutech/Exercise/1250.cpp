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
const int maxN = 1000+100;
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
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

int n, m, cnt=0;
bool a[maxN][maxN], vistBFS[maxN][maxN];

int bfs(int sx, int sy){
    int s=0, cntX=0, cntY=0;
    queue<ii> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        FOR(int,i,0,3){
            int u = x + dx[i];
            int v = y + dy[i];

            if(u > n || u < 1) continue;
            if(v > m || v < 1) continue;

            if(a[u][v] && !vistBFS[u][v]){
                if(sx == u) cntX += 1;
                if(sy == v) cntY += 1;
                s += a[u][v];
                vistBFS[u][v] = true;
                q.push({u,v});
            }
        }
    }
    if(cntX * cntY == s) return 1;
    return 0;
}

void solve(){
    cin >> n >> m;
    FOR(int,i,1,n)
        FOR(int,j,1,m) cin >> a[i][j];

    FOR(int,i,1,n)
        FOR(int,j,1,m)
            if(a[i][j] && !vistBFS[i][j]) cnt += bfs(i,j);

    cout << cnt;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
