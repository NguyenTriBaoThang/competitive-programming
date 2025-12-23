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
const int BLOCK = 550;
const int MOD = 10000;
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

int N, K;
int pasta[105];
int dp[105][4][4]; 

void solve(){
	cin >> N >> K;
    memset(pasta, 0, sizeof(pasta));
    REP(int, i, 0, K) {
        int day, type;
        cin >> day >> type;
        pasta[day] = type;
    }
    memset(dp, 0, sizeof(dp));
    
    if (pasta[1]) {
        dp[1][pasta[1]][0] = 1; 
    } else {
        FOR(int, i, 1, 3) 
            dp[1][i][0] = 1;
    }
    
    FOR(int, i, 2, N) {
        FOR(int, j, 1, 3) { 
            if (pasta[i] && pasta[i] != j) continue; 
            FOR(int, k, 1, 3) {
                FOR(int, h, 0, 3) {
                    if (j == k && k == h) continue; 
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k][h]) % MOD;
                }
            }
        }
    }

    int res = 0;
    FOR(int, i, 1, 3) {
        FOR(int, j, 1, 3) {
            res = (res + dp[N][i][j]) % MOD;
        }
    }
    
    cout << res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
