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
const int N = 1e3 + 5;
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

struct Tree{
   int n; vector<int> it, lz;

   Tree(int _n=0){
      n = _n;
      it.assign(4*n+5, 0);
      lz.assign(4*n+5, 0);
   }

   void down(int id, int l, int r){
      int &t = lz[id];
      if (t==0) return;
      int mid = (l+r)>>1;
      it[id<<1] += t * (mid - l + 1);
      it[id<<1|1] += t * (r - mid);
      lz[id<<1] += t;
      lz[id<<1|1] += t;
      t = 0;
   }

   void update(int id, int l, int r, int u, int v, int c){
      if (u>r || v<l || l>r || u>v) return;
      if (u <= l && v>=r){
         it[id] += c * (r - l + 1);
         lz[id] += c;
         return;
      }
      down(id, l, r);
      int mid = (l+r)>>1;
      update(id<<1, l, mid, u, v, c);
      update(id<<1|1, mid+1, r, u, v, c);
      it[id] = it[id<<1] + it[id<<1|1];
   }

   int getSum(int id, int l, int r, int u, int v){
      if(u>r || v<l || l>r || u>v) return 0;
      if(u<=l && v>=r) return it[id];
      down(id, l, r);
      int mid = (l+r)>>1;
      return getSum(id<<1, l, mid, u, v) + getSum(id<<1|1, mid+1, r, u, v);
   }

} IT[2 * N];

int n, m;
int cnt[2*N][N];
char a[N][N];

void solve(){
    cin >> n >> m;
    FOR(int,i,1,n) FOR(int,j,1,m) cin >> a[i][j];
    ll ans = 0;
    FOR(int,i,1,n+m) IT[i] = Tree(m);
    FOR(int,i,1,n){
        FOR(int,j,1,m){
           if (a[i][j] == '1'){
               int k = j;
               while(a[i][k] == '1') k++;
               k--;
               FOR(int,t,j,k-1){
                   int len = k - t + 1;
                   ans += IT[i+t].getSum(1, 1, m, 2, len);
               }
               FOR(int,t,j+1,k) IT[i+t].update(1, 1, m, 2, t - j + 1, 1);
               j = k;
           }else IT[i+j] = Tree(m);
        }
    }
    cout << ans;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
