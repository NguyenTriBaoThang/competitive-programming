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
const int maxN = 1e6 + 100;
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
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

struct Data{
    int fi, se;
    void operator=(Data b){
        fi = b.fi;
        se = b.se;
    }
};

bool operator<(Data a, Data b){
    int da = (a.se - a.fi) / 2;
    int db = (b.se - b.fi) / 2;
    return (da > db || (da == db && a.fi < b.fi));
}

int n, prk[maxN], la[maxN], ds[maxN];
set<Data> st;

inline void add(int x){
    Data t = *st.begin();
    st.erase({t.fi, t.se});
    int k = t.se - t.fi + 1;
    if (k == 1){
        prk[x] = t.fi;
        ds[t.fi] = 1;
        la[t.fi] = t.fi;
    }else if (t.fi == 1){
        prk[x] = 1;
        ds[1] = 1;
        la[1] = 1;
        st.insert({2, t.se});
        la[2] = t.se;
        la[t.se] = 2;
    }else if (t.se == n){
        prk[x] = n;
        ds[n] = 1;
        la[n] = n;
        st.insert({t.fi, n - 1});
        la[n - 1] = t.fi;
        la[t.fi] = n - 1;
    }else if (k == 2){
        prk[x] = t.fi;
        ds[t.fi] = 1;
        la[t.fi] = t.fi;
        st.insert({t.se, t.se});
        la[t.se] = t.se;
    }else if (k % 2 == 0){
        prk[x] = t.fi + k / 2 - 1;
        ds[t.fi + k / 2 - 1] = 1;
        la[t.fi + k / 2 - 1] = t.fi + k / 2 - 1;
        st.insert({t.fi, t.fi + k / 2 - 2});
        la[t.fi] = t.fi + k / 2 - 2;
        la[t.fi + k / 2 - 2] = t.fi;
        st.insert({t.fi + k / 2, t.se});
        la[t.se] = t.fi + k / 2;
        la[t.fi + k / 2] = t.se;
    }else{
        prk[x] = t.fi + k / 2;
        ds[t.fi + k / 2] = 1;
        la[t.fi + k / 2] = t.fi + k / 2;
        st.insert({t.fi, t.fi + k / 2 - 1});
        la[t.fi] = t.fi + k / 2 - 1;
        la[t.fi + k / 2 - 1] = t.fi;
        st.insert({t.fi + k / 2 + 1, t.se});
        la[t.se] = t.fi + k / 2 + 1;
        la[t.fi + k / 2 + 1] = t.se;
    }
    cout << prk[x] << '\n';
}

inline void del(int x){
    int a, b, c, d;
    b = prk[x] - (ds[prk[x] - 1] == 0 && prk[x] - 1 > 0);
    c = prk[x] + (ds[prk[x] + 1] == 0 && prk[x] + 1 <= n);
    ds[prk[x]] = 0;
    a = la[b];
    d = la[c];
    st.erase({a, b}), st.erase({c, d}), st.insert({a, d});
    la[a] = d;
    la[d] = a;
}

void solve(){
	int m;
    cin >> n >> m;
    int t, x;
    st.insert({1, n});
    while (cin >> t >> x) (t == 1 ? add(x) : del(x));
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
