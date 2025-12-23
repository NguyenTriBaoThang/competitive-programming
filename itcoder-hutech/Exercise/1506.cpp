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
const int maxn = 5e2;
const int maxm = 1e4;
const int N = 1e5 + 5;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const int INF = 1e9;
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

struct TEdge {
    int u, v;
    short w;
};

int n, m, nE, SavenE;
int Lab[maxn + 1], SaveLab[maxn + 1];
TEdge EList[maxm + 1];
bool solution;

void Enter() {
    cin >> n >> m;
    FOR(int,i,1,m)
        cin >> EList[i].u >> EList[i].v >> EList[i].w;
}

void InitForest() {
    for (int i = 1; i <= n; ++i)
        Lab[i] = -1;
}

int GetRoot(int u) {
    while (Lab[u] >= 0)
        u = Lab[u];
    return u;
}

void Union(int r1, int r2) {
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    } else {
        Lab[r2] = r1;
        Lab[r1] = x;
    }
}

bool Kruskal(int code) {
    FOR(int,i,1,m){
        if (EList[i].w == code) {
            int r1 = GetRoot(EList[i].u);
            int r2 = GetRoot(EList[i].v);
            if (r1 != r2) {
                EList[i].w = -EList[i].w;
                ++nE;
                if (nE == n - 1)
                    return true;
                Union(r1, r2);
            }
        }
    }
    return false;
}

void Result() {
    if (!solution)
        cout << -1 << endl;
    else {
        cout << m - (n + n - 2 - SavenE) << endl;
        FOR(int,i,1,m)
            if (EList[i].w > 0)
                cout << i << endl;
    }
}

void solve(){
	Enter();
    InitForest();
    nE = 0;
    solution = Kruskal(3);
    if (!solution) {
        SavenE = nE;
        memcpy(SaveLab, Lab, sizeof(Lab));
        solution = Kruskal(1);
        nE = SavenE;
        memcpy(Lab, SaveLab, sizeof(Lab));
        solution = solution && Kruskal(2);
    }
    Result();
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}