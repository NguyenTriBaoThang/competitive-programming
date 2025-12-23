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
const int maxN = 1e3 + 100;
const int N = 3e5 + 100;
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

lli n=0, _x=0, _y=0, _z=0, X[N], Y[N], Z[N], ans=0, k;

void solve(){
    cin >> n >> _x >> _y >> _z;
    FOR(int,i,1,n){
        cin >> X[i] >> Y[i] >> Z[i];
        ans += abs(_x - X[i]) + abs(_y - Y[i]) + abs(_z - Z[i]);
    }
    sort(X,X+n+1); sort(Y,Y+n+1); sort(Z,Z+n+1);
    k = (n+1)/2;
    _x = X[k];
    _y = Y[k];
    _z = Z[k];
    FOR(int,i,1,n) ans += abs(_x - X[i]) + abs(_y - Y[i]) + abs(_z - Z[i]);
    cout << ans <<endl;
    cout << _x << " " << _y << " " << _z << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
