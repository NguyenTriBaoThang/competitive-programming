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
const int maxN = 1e5 + 100;
const int N = 2e5 + 7;
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

int n;
ll a[3 * N];
ll Prefix[3 * N];
ll Suffix[3 * N];

void init() {
    priority_queue<int,vector<int>, greater<int>> q;
    for (int i = 1;i<=n;i++) {
        Prefix[i] = Prefix[i - 1] + a[i];
        q.push(a[i]);
    }
    for (int i = n + 1;i <= 3 * n;i++) {
        int u = q.top();
        if (a[i] > u) {
            q.pop();
            q.push(a[i]);
            Prefix[i] = Prefix[i - 1] - u + a[i];
        } else {
            Prefix[i] = Prefix[i - 1];
        }
    }
    priority_queue<int> dq;
    for (int i = 3 * n;i >= 2 * n + 1;i--) {
        Suffix[i] = Suffix[i + 1] + a[i];
        dq.push(a[i]);
    }
    for (int i = 2 * n ;i >= 1;i--) {
        int u = dq.top();
        if (a[i] < u) {
            dq.pop();
            dq.push(a[i]);
            Suffix[i] = Suffix[i + 1] - u + a[i];
        } else {
            Suffix[i] = Suffix[i + 1];
        }
    }
}

void solve(){
	cin >> n;
    for (int i = 1;i <= 3 * n;i++) {
        cin >> a[i];
    }
    init();
    ll sum = LLONG_MIN;
    for (int i = n;i <= 2 *n;i++) {
        sum = max(sum, Prefix[i] - Suffix[i + 1]);
    }
    cout << sum;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}