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

 ll dp[3014][3014],h[3014],pos[3014][3014],n;

void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>h[i];
        h[i]+=h[i-1];
        for(ll j=i+1;j<=n;j++){
            dp[i][j]=INF_LL;
        }
        dp[i][i]=0;
        pos[i][i]=i;
    }
    for(ll i=n-1;i>=1;i--){
        for(ll j=i+1;j<=n;j++){
            ll tmp=h[j]-h[i-1];
            for(ll k=pos[i][j-1];k<=pos[i+1][j];k++){
                if(dp[i][k]+dp[k+1][j]+tmp*tmp<dp[i][j]){
                    dp[i][j]=dp[i][k]+dp[k+1][j]+tmp*tmp;
                    pos[i][j]=k;
                }
            }
        }
    }
    cout<<dp[1][n];
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
