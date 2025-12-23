#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
const int maxN = 666;
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

int T, n;
int cnt[maxN];

int findNumber(int n){
    int res=0;
    while(n){
        res += (n%10) * (n%10);
        n /= 10;
    }
    return res;
}

bool checkNumber(int n){
    if(n==1) return 1;
    n = findNumber(n);
    while(cnt[n] == 0 && n != 1){
        if(cnt[n]>=2) return 0;
        cnt[n]+=1;
        n = findNumber(n);
    }
    return (n == 1 ? 1 : 0);
}

void solve(){
    cin >> T;
    while(T--){
        cin >> n;
        fill_n(cnt, maxN, 0);
        cout << ((checkNumber(n)) ? "YES" : "NO") << endl;
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
