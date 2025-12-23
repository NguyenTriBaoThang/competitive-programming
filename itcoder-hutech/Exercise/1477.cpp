#include<bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
typedef pair<int, int> i_i;
const int maxN = 1e3 + 100;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
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
#define ll long long
#define pii pair<bool, int>
#define piii pair<int, pair<int, int>>
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)
const int N = 1e9 + 7;
int n, m;
vector<vector<int>> ke;
vector<pii> luu;
vector<bool> dd;
struct cmp{
    bool operator()(int a, int b){
        return a < b;
    }
};

void r(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

void dfs(int u, int v, int vl){
    dd[u] = 0;
    if(ke[u].size() == 1 && u != 1){
        luu[u] = {0, 0};
        return;
    }
    for(int i : ke[u])
        if(i != v){
            dfs(i, u, vl);
        }
    int gn0 = 0, gn1 = 1e9;
    for(int i : ke[u])
        if(i != v){
            if(luu[i].first){
                gn1 = min(gn1, luu[i].second + 1);
            }
            else gn0 = max(gn0, luu[i].second + 1);
        }
    if(gn1 + gn0 <= vl){
        luu[u] = {1, gn1};
    }
    else{
        luu[u] = {0, gn0};
        if(gn0 >= vl){
            dd[u] = 1;
            luu[u] = {1, 0};
        }
    }
}

bool check(int mid)
{
    dfs(1, 1, mid);
    if(luu[1].first == 0) dd[1] = 1;
    int res = 0;
    for(int i = 1; i <= n; i ++){
        res += dd[i];
    }
    return (res <= m);
}

void solve() {
    r(n);
    r(m);
    ke.resize(n + 1);
    dd.resize(n + 1);
    luu.resize(n + 1);
    for(int i = 1; i < n; i ++)
    {
        int u, v;
        r(u); r(v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    int l = 1, r = n - 1;
    int res = 0;
    while(l <= r){
        int giua = (l + r) / 2;
        if(check(giua)){
            res = giua;
            r = giua - 1;
        }
        else l = giua + 1;
    }
    cout << res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
	return 0;
}
