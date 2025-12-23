#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define FOD(i,a,b) for(ll i=a; i>=b; i--)
#define For(x,m) for(auto x: m)
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
 
const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
 
using namespace std;

ll n, x, a[118], ans = 0;
//Free Contest 83 - INCEQUAL, Free Contest Testing Round 54 - INCEQUAL
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    FOR(i,1,n) cin >> a[i];
    sort(a+1, a+n+1);
    FOD(i, n-1, 1){
        if((a[n] - a[i])%x != 0) return cout << "-1", 0;
        else ans += (a[n] - a[i])/x;
    }
    cout << ans;
    return 0;
}