#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 1e6 + 5;
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

template <typename T> inline void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}

template <typename T> inline void writ(T x) {
    if (x >= 10)
        writ(x / 10);
    putchar(x % 10 + 48);
}

template <typename T> inline void writeln(T x) {
    writ(x);
    putchar('\n');
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

int n, q, a[maxN];

struct IT{
    int itmax[maxN * 4];

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            itmax[id] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(id * 2, l, m, pos, val);
        else update(id * 2 + 1, m + 1, r, pos, val);
        itmax[id] = max(itmax[id * 2], itmax[id * 2 + 1]);
    }

    int get(int id, int l, int r, int pos) {
        if (l > pos) return 0;
        if (r <= pos) return itmax[id];
        int m = (l + r) / 2;
        return max(get(id * 2, l, m, pos), get(id * 2 + 1, m + 1, r, pos));
    }
};

IT Tree;

void solve(){
    read(n); read(q);
    FOR(int,i,1,n) read(a[i]);
    Tree.update(1, 1, n, 1, 1);
    FOR(int,i,2,n) if (a[i] % a[i - 1] != 0) Tree.update(1, 1, n, i, i);
    while(q--){
        int type, pos, x; read(type); read(pos);
        if(type == 1){
            read(x); a[pos] = x;
            if(pos > 1 ){
                if (a[pos] % a[pos - 1] == 0) Tree.update(1, 1, n, pos, 0);
                else Tree.update(1, 1, n, pos, pos);
            }
            if (pos < n) {
                if (a[pos + 1] % a[pos] == 0) Tree.update(1, 1, n, pos + 1, 0);
                else Tree.update(1, 1, n, pos + 1, pos + 1);
            }
        }
        else
            writeln(Tree.get(1, 1, n, pos));
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
