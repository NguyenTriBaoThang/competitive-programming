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
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

string a, b;

bool cmp(string a, string b) {
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    if (a < b)
        return true;
    return false;
}

string cong(string a, string b) {
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    int nho = 0;
    string c = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        long long t = (a[i] - 48) + (b[i] - 48) + nho;
        if (t > 9) {
            t -= 10;
            nho = 1;
        } else
            nho = 0;
        char d = t + 48;
        c = d + c;
    }
    if (nho == 1)
        c = "1" + c;
    return c;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	vector<string> f(1005), g(1005);
	g[0] = g[1] = "0";
    g[2] = "1";
    f[1] = "1";
    f[2] = "2";
	FOR(int,i,3,1000){
		f[i] = cong(f[i - 1], f[i - 1]);
		g[i] = cong(f[i - 2], g[i - 2]);
	}
	int n;
	while(cin >> n){
		cout << g[n] << endl;
	}
	return 0;
}
