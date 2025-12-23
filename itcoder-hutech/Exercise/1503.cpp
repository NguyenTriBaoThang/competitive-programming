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
const int maxN = 1e5 + 100;
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

double canh(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void solve(){
    double c1,c2,c3,c4,x1,x2,x3,x4,y1,y2,y3,y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    c1 = canh(x1,y1,x2,y2); c2 = canh(x2,y2,x3,y3); c3 = canh(x3,y3,x4,y4); c4 = canh(x4,y4,x1,y1);
    int T=0, cnt=0; cin >> T;
    while(T--){
        double cc1,cc2,cc3,cc4,a1,a2,a3,a4,b1,b2,b3,b4; cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
        cc1 = canh(a1,b1,a2,b2); cc2 = canh(a2,b2,a3,b3); cc3 = canh(a3,b3,a4,b4); cc4 = canh(a4,b4,a1,b1);
        if(c1 == cc1 && c2 == cc2 && c3 == cc3 && c4 == cc4){ cnt += 1; continue; }
        if(c1 == cc2 && c2 == cc3 && c3 == cc4 && c4 == cc1){ cnt += 1; continue; }
        if(c1 == cc3 && c2 == cc4 && c3 == cc1 && c4 == cc2){ cnt += 1; continue; }
        if(c1 == cc4 && c2 == cc1 && c3 == cc2 && c4 == cc3){ cnt += 1; continue; }
    }
    cout << cnt << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}