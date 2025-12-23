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

string A, B;
ll a, b, c2[] = {6 , 2 , 4 , 8} , c3[] = {1 , 3 , 9 , 7} , c7[] = {1 , 7 , 9 , 3} , c8[] = {6 , 8 , 4 , 2 };

ll big(string a, ll b){
    ll res = 0, n=a.size()-1;
    FOR(int,i,0,n) res = (res*10 + (a[i]-'0')) % b;
    return res;
}

void solve(){
    cin >> A >> B ;
    a = *A.rbegin() - '0';
    b = *B.rbegin() - '0';
    if(a == 5 || a == 6 || a == 0 || a == 1){cout << a ; return;}
    if(a == 4 || a == 9){
       if(b % 2 == 1){
            if(a == 4) cout << 4;
            else cout << 9;
        }else {
            if(a == 4) cout << 6;
            else cout << 1;
        }
    }
    if(a == 2) cout << c2[big(B,4)];
    if(a == 3) cout << c3[big(B,4)];
    if(a == 7) cout << c7[big(B,4)];
    if(a == 8) cout << c8[big(B,4)];
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
