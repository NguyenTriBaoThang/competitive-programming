#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
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
#define sz(x) (int)x.size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

int T=0, n=0, k=0,h[maxN], l[maxN], r[maxN];
stack<int> pq;


void solve(){
    cin >> T;
    while(T--){
        cin >> n;
        FOR(int,i,1,n) cin >> h[i], l[i] = r[i] = 0;

        while(sz(pq)) pq.pop();
        FOR(int,i,1,n){
            while(sz(pq) && h[i] >= h[pq.top()]){
                if(h[i] == h[pq.top()]) l[i] = l[pq.top()] + 1;
                pq.pop();
            }
            pq.push(i);
        }

        while(sz(pq)) pq.pop();
        FORE(int,i,n,1){
            while(sz(pq) && h[i] >= h[pq.top()]){
                if(h[i] == h[pq.top()]) r[i] = r[pq.top()] + 1;
                pq.pop();
            }
            pq.push(i);
        }

        FOR(int,i,1,n) cout << l[i] + r[i] << " ";
        cout << endl;
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
