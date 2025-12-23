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
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const long double EPS = 1e-6;
const long long INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

const int N = 10010;
const int M = 100010;
const int INF = 1e8;

int m, n, k, s, t;
int d1[N], d2[N];

void Read(int &x){
    int ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    int res = 0;
    while ('0' <= ch && ch <= '9') {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    x = res;
}

void solve(){
	Read(n); Read(m); Read(k); Read(s); Read(t);
    vector <vector <ii> > A(n + 1), B(n + 1);
    FOR(i, 1, m){
        int u, v, w;
        Read(u); Read(v); Read(w);
        A[u].push_back(mp(v, w));
        B[v].push_back(mp(u, w));
    }

    FOR(i, 1, n) d1[i] = d2[i] = INF;
    priority_queue <ii, vector<ii>, greater<ii> > Q;

    Q.push(mp(0, s));
    d1[s] = 0;
    while (!Q.empty()){
        int u = Q.top().Y;
        int w = Q.top().X;
        Q.pop();
        if (w != d1[u]) continue;

        for(ii ed : A[u]) if (d1[ed.X] > w + ed.Y){
            d1[ed.X] = w + ed.Y;
            Q.push(mp(d1[ed.X], ed.X));
        }
    }

    Q.push(mp(0, t));
    d2[t] = 0;
    while (!Q.empty()){
        int u = Q.top().Y;
        int w = Q.top().X;
        Q.pop();
        if (w != d2[u]) continue;

        for(ii ed : B[u]) if (d2[ed.X] > w + ed.Y){
            d2[ed.X] = w + ed.Y;
            Q.push(mp(d2[ed.X], ed.X));
        }
    }

    int ans = d1[t];

    FOR(i, 1, k){
        int u, v, w;
        Read(u); Read(v); Read(w);
        ans = min(ans, min(d1[u] + d2[v] + w, d1[v] + d2[u] + w));
    }
    if (ans == INF) ans = -1;

    cout << ans << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
