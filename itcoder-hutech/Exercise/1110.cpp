#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 2e5 + 100;
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

ll n=0, dp[maxN], l, r=0, d=0;
string s;

void tinhABC(char x){
    FOR(ll,i,1,n){
        if(s[i]==x) r += 1; else r -= 1;
        if(r>0) d = max(d,i);
        else{
            if(dp[abs(r)]==0) dp[abs(r)]=i;
            if(dp[abs(r)+1]!=0) d=max(d,i-dp[abs(r)+1]);
        }
    }
}

void solve(){
    cin >> n; cin >> s;
    s = ' ' + s;
    memset(dp,0,sizeof(0));
    tinhABC('a'); tinhABC('b'); tinhABC('c');
    cout << d << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
