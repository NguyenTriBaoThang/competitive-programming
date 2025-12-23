#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
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

struct DULIEU{
    ll pos, val;
};

int n=0, q=0;

struct IT {
    vector<DULIEU> t;

    void addTree(int n){
        t.assign(4*n+1, {0, -1});
    }

    void build(int id, int l, int r) {
        ll &x = t[id].val;
        if(x != -1){
            int m = (l+r)/2;
            t[2*id].val = t[2*id+1].val = x;
            t[2*id].pos = (m-l+1)*x;
            t[2*id+1].pos = (r-m)*x;
            x = -1;
        }
    }

    void update(int id, int l, int r, int i, int j, ll x) {
        if (l > j || r < i) return;
        if (i <= l && r <= j){
            t[id].val = x;
            t[id].pos = (r-l+1)*x;
            return;
        }
        build(id, l, r);
        int m = (l+r)/2;
        update(2*id, l, m, i, j, x); update(2*id+1, m+1, r, i, j, x);
        t[id].pos = t[2*id].pos + t[2*id+1].pos;
    }

    ll get(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id].pos;
        build(id, l, r);
        int m = (l+r)/2;
        return get(2*id, l, m, i, j) + get(2*id+1, m+1, r, i, j);
    }

};

IT Tree;

int main () {
    cin >> n >> q;

    Tree.addTree(n);

    FOR(int,i,0,q-1){
        int r=0; ll p=0; cin >> r >> p;

        int li = 1, hi = r-1, l = r;
        while (li <= hi) {
            int mid = (li + hi)/2;
            ll midi = Tree.get(1, 1, n, mid, mid);
            ll x = (r-mid+1)*midi - Tree.get(1, 1, n, mid, r);

            if (x <= p){
                l = mid; hi = mid-1;
            }else li = mid+1;
        }

        ll res = Tree.get(1, 1, n, l, l);
        p -= (r-l+1) * res - Tree.get(1, 1, n, l, r);

        ll ans = res + p/(r-l+1);
        int m = l + p%(r-l+1) - 1;
        Tree.update(1, 1, n, l, m, ans + 1);
        Tree.update(1, 1, n, m + 1, r, ans);
    }

    FOR(int,i,1,n) cout << Tree.get(1, 1, n, i , i) << " ";

    return 0;
}
