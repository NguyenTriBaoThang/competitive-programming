#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
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

void solve(){
    long n,s; cin >> n;
    if(n<=200){
        if(n>100){
            s = 50*1678 + 50*1734 + (n-100) * 2014;
        }else{
            if(n<=50){
                s = n * 1678;
            }else{
                s = 50*1678 + (n-50) * 1734;
            }
        }
    }else{
        if(n<=400){
            if(n<=300){
                s = 50*1678 + 50*1734 + 100 * 2014 + (n-200) * 2536;

            }else{
                s = 50*1678 + 50*1734 + 100 * 2014 + 100 * 2536 + (n-300) * 2834;
            }
        }else{
            s = 50*1678 + 50*1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (n-400)*2927;
        }
    }
    long vt = round((float)s * 10 / 100);
    cout << vt+s << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
