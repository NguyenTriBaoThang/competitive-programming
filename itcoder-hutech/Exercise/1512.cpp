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
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

vector<int> adj[100005];
bool vis[100005];
vector<int> v;

void dfs(int s){
    if (vis[s]) return;
    vis[s]=1;
    for (auto i: adj[s]) dfs(i);
    v.pb(s);
}

void solve(){
	int n,m; see(n,m);
    REP(int,i,0,m){
        int a,b; see(a,b);
        adj[b].pb(a);
    }
    REP(int,i,1,n+1){
        if (!vis[i]) dfs(i);
    }
    vector<int> t; int i=0,f=0;
    while(i<sz(v)){
        if (f==0){
            if (v[i]==1) {f=1; t.pb(1);}
        }
        else{
            t.pb(v[i]);
        }
        i++;
    }
    int len[100005]={0}, par[100005]={0};
    len[1]=1, par[1]=0;
    for (auto i: t) {
        for (auto j: adj[i]){
            if (len[i]<len[j]+1 && len[j]){
                len[i]=len[j]+1;
                par[i] = j;
            }
        }
    }
    i = n;
    vector<int> v;
    while(i!=0){
        v.pb(i); i = par[i];
    }
    reverse(all(v)); 
    if (sz(v)<2) {put("-1"); return;}
    putl(sz(v));
    for (auto i: v) put(i);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
