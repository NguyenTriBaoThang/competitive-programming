#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
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

void solve(){
    int n, Q;
    cin >> n >> Q;
    vector<long long> diff(n);
    long long prev, cur;
    cin >> prev;
    int res = 0;
    for(int i = 1; i < n; i++){
        cin >> cur;
        diff[i] = prev - cur;
        if(diff[i] > 0) res++;
        prev = cur;
    }
    while(Q--){
        int l, r;
        long long k;
        cin >> l >> r >> k;
        if(l > 1){
            res -= (diff[l-1] > 0);
            diff[l-1] -= k;
            res += (diff[l-1] > 0);
        }
        if(r < n){
            res -= (diff[r] > 0);
            diff[r] += k;
            res += (diff[r] > 0);
        }
        cout << res << '\n';
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
