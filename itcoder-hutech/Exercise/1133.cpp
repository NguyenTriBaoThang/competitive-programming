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

double calc(double x1, double y1, double z1, double x2, double y2, double z2){
    return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) + ((z2-z1)*(z2-z1)));
}

void solve(){
    int T; cin >> T;
    while(T--){
        double x1, y1, z1, x2, y2, z2, x3, y3, z3, AB, AC, BC, p;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        cin >> x3 >> y3 >> z3;
        AB = calc(x1,y1,z1,x2,y2,z2);
        AC = calc(x1,y1,z1,x3,y3,z3);
        BC = calc(x2,y2,z2,x3,y3,z3);
        p = (AB+AC+BC)/2.0;
        cout << prec(2) << 2.0*(sqrt(p*(p-AB)*(p-AC)*(p-BC)))/BC << endl;
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
