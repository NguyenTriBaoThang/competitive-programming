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
typedef pair<int, int> pii;
const int maxN = 1000 + 100;
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
#define clog if (0) cout
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

int n, k, p[maxN], d[maxN], s;
vector<int> g[maxN], tmp, ans;
bool mark[maxN];

void dfs1(int u){
    if(d[u] > d[s] && d[u] < k) s = u;
    for(int v : g[u]){
        d[v] = d[u] + 1;
        dfs1(v);
    }
}

void dfs2(int u){
    ans.emplace_back(u);
    for(int v : g[u]){
        if(!mark[v] && k > 0){
        k-=1; dfs2(v);
        ans.emplace_back(u);
        }
    }
}

void solve(){
    int T=0; cin >> T;
    while(T--){
        cin >> n >> k;
        FOR(int,i,1,n){
            g[i].clear();
            mark[i] = false;
        }
        FOR(int,i,2,n){
            cin >> p[i];
            g[p[i]].emplace_back(i);
        }
        d[1] = 0; s = 1;
        dfs1(1);
        tmp.clear(); ans.clear();
        for(int u = s; u; u = p[u]){
            tmp.emplace_back(u);
            mark[u] = true;
        }
        reverse(tmp.begin(), tmp.end());
        k -= tmp.size();
        for (int u : tmp) dfs2(u);
        cout << (int)ans.size() - 1 << endl;
        for (int u : ans) cout << u << ' ';
        cout << endl;
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}