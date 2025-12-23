#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const long long INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
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

string calc(const string& num1, const string& num2){
    string res = "";
    int carr = 0;
    int i = sz(num1) - 1, j = sz(num2) - 1;
    while(i >= 0 || j>= 0 || carr > 0){
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carr;
        carr = sum / 10;
        res += (sum % 10) + '0';
        i--;
        j--;
    }
    reverse(all(res));
    return res;
}

void solve(){
	ll n, m; cin >> n >> m;
    vector<ll> A(n), B(m);
   	REP(int, i, 0, n)
        cin >> A[i];
    REP(int, i, 0, m)
        cin >> B[i];
    string numA = "";
    REP(int, i, 0, n)
        numA += to_string(A[i]);
    string numB = "";
    REP(int, i, 0, m)
        numB += to_string(B[i]);
    string res = calc(numA, numB);
    cout << res;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
