#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN =  1e5 + 5;
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

ll calc(ll A, ll B, ll TA, ll TB, ll X, ll Y) {
    ll d1 = llabs(A - TA);
    ll d2 = llabs(B - TB);
    if (Y >= 2 * X) {
        return (d1 + d2) * X;
    }
    ll dir1 = TA - A;
    ll dir2 = TB - B;
    if ((dir1 > 0 && dir2 > 0) || (dir1 < 0 && dir2 < 0)) {
        ll k = min(d1, d2);
        return k * Y + (d1 + d2 - 2 * k) * X;
    }
    return (d1 + d2) * X;
}

void solve(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    ll S1, S2, T1, T2;
    cin >> S1 >> S2 >> T1 >> T2;
    ll A = min(S1, S2);
    ll B = max(S1, S2);
    ll ans = LLONG_MAX;
    ans = min(ans, calc(A, B, T1, T2, X, Y));
    ans = min(ans, calc(A, B, T2, T1, X, Y));
    cout << ans << "\n";
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}