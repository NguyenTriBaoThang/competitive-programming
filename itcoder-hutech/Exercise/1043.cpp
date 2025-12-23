#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
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

typedef vector<int> BigInt;
int n;

BigInt operator + (BigInt a, BigInt b){
    BigInt c; int carry = 0;
    for(int i=0;i<a.size() || i<b.size();i++){
        if(i<a.size()) carry += a[i];
        if(i<b.size()) carry += b[i];
        c.push_back(carry%MOD);
        carry /= MOD;
    }
    if(carry) c.push_back(carry);
    return c;
}

BigInt operator * (BigInt a, int b){
    BigInt c; int carry = 0;
    for(int i=0;i<a.size();i++){
        carry += a[i]*b;
        c.push_back(carry%MOD);
        carry /= MOD;
    }
    if(carry) c.push_back(carry);
    return c;
}

void print(BigInt a){
    cout << a[sz(a)-1];
    for(int i=a.size()-2;i>=0;i--)
        printf("%05d", a[i]);
    cout << "\n";
}

void solve(){
    cin >> n;
    BigInt res; res.push_back(1);
    BigInt tmp = res;
    for(int i=n-2;i;i--){
        tmp = tmp * i;
        res = res + tmp;
    }
    print(res);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
