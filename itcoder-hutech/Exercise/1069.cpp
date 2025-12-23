#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 200009;
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

int n=0,k=0; ll ans=0;
priority_queue<ll, vector<ll>, greater<ll>> PQ;

void Input(){
    cin >> n >> k;
    FOR(int,i,1,n){
        int x; cin >> x;
        PQ.push(x);
    }
}

void solve(){
    Input();
    while(PQ.size()>1){
        ll aMin = INF_LL;
        ll aMax = -INF_LL;
        ll sum = 0;
        int cnt = 0;
        while(!PQ.empty()){
            cnt += 1;
            if(cnt > k) break;
            ll e = PQ.top();
            PQ.pop();
            aMax = (aMax < e ? e : aMax);
            aMin = (aMin > e ? e : aMin);
            sum += e;
        }
        PQ.push(sum);
        ans += aMax - aMin;
    }
    cout << PQ.top() << endl << ans << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
