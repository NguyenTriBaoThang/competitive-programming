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
const int maxN = 5e5 + 5;
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

vector<vector<int>> atm_withdrawal(int N, int S, vector<int>& denominations) {
    vector<int> dp(S + 1, INT_MAX);
    vector<vector<vector<int>>> used(S + 1);

    dp[0] = 0; 
    used[0] = {{}};

    REP(int, i, 0, N) {
        FORE(int, j, S, denominations[i]) {
            if (dp[j - denominations[i]] != INT_MAX) {
                int newCount = dp[j - denominations[i]] + 1;
                if (newCount < dp[j]) {
                    dp[j] = newCount;
                    used[j].clear();
                }
                if (newCount == dp[j]) {
                    for (auto v : used[j - denominations[i]]) {
                        v.push_back(denominations[i]);
                        used[j].push_back(v);
                    }
                }
            }
        }
    }

    if (dp[S] == INT_MAX) {
        return {{}};
    }

    for (auto& vec : used[S]) {
        sort(vec.begin(), vec.end());
    }
    
    sort(used[S].begin(), used[S].end());
    return used[S];
}

void solve() {
    int N, S; cin >> N >> S;
    //N = (N == 25 ? 30 : N);
    vector<int> denominations(N);
    REP(int, i, 0, N) {
        cin >> denominations[i];
    }
    
    sort(all(denominations));
    
    vector<vector<int>> result = atm_withdrawal(N, S, denominations);
    
    if (result.size() == 1 && result[0].size() == 0) {
        cout << 0 << endl;
    } else {
        for (const auto& v : result) {
            for (int note : v) {
                cout << note << " ";
            }
            //cout << endl;
            return;
        }
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
