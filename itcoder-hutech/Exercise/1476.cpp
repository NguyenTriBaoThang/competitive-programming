#include<bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<string>
#include<vector>
typedef long long ll;
typedef long long int lli;
const int maxN = 1e3+7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long long INF_LL = 1e18;
const int dx[4] = {-1,+0,+1,+0};
const int dy[4] = {+0,+1,+0,-1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)
using namespace std;


ll minCoins(ll coins[], ll n, ll s){
    ll min[s+1]; min[0]=0;
    FOR(ll,i,1,s) min[i] = INF;
    FOR(ll,i,1,s){
        FOR(ll,j,0,n-1){
            if(coins[j]<=i){
                ll tmp = min[i-coins[j]];
                if(tmp != INF && ((tmp+1) < min[i])){
                    min[i] = tmp + 1;
                }
            }
        }
    }
    if(min[s] == INF) return -1;
    else return min[s];
}

void solve(){
	ll n=0, s=0; cin >> n >> s;
    ll coins[n+1]; FOR(ll,i,0,n-1) cin >> coins[i];
    ll ans = minCoins(coins,n,s);
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}