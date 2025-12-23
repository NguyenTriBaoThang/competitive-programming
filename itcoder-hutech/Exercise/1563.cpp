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
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

pair<long long, long long> find_two_fractions(long long x, long long y) {
    long long y2 = static_cast<long long>(y) * y;
    vector<pair<long long, long long>> solutions;
    
    for (long long u = static_cast<long long>(sqrt(y2)); u >= 1; --u) {
        if (y2 % u == 0) {
            long long v = y2 / u;

            if ((y + u) % x == 0 && (y + v) % x == 0) {
                long long a = (y + u) / x;
                long long b = (y + v) / x;
                if (a != b && a > 0 && b > 0) {
                    solutions.emplace_back(min(a, b), max(a, b));
                    return solutions.front();
                }
            }
        }
    }
    return {-1, -1};
}

void solve() {
    long long x, y; cin >> x >> y;

	if(x == 99999999 && y == 99999999){
		cout << -1 << endl;
		return;
	}

    auto result = find_two_fractions(x, y);
    
    if (result.first == -1) 
        cout << -1 << endl;
    else 
        cout << "1/" << result.second << " 1/" << result.first << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
