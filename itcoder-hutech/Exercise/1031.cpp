#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pii;
const int maxN = 1000;
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

typedef struct TYSO{
	int a=0, b=0, c=0, d=0;
}TY;

typedef struct DOITHIDAU{
	int team=0;   //1 2 3 4
    int score=0;  // tong diem
    int hs=0;     // hieu so
    int res=0;    // tong so ban thang
}DT;

TY a1[maxN]; ll n=0;

bool cmp(DT x, DT y){
	if(x.score == y.score){
		if(x.hs == y.hs){
			if(x.res == y.res){
				FOR(int,i,1,n){
					if(a1[i].a == x.team && a1[i].b == y.team){
						if(a1[i].c == a1[i].d) return x.team < y.team;
						else return x.team > y.team;
					}
				}
			}return x.res > y.res;
		}return x.hs > y.hs;
	}return x.score > y.score;
}

void solve(){
	cin >> n;
	vector<DT> a2(5);
	FOR(int,i,1,4) a2[i].team = i;
	FOR(ll,i,1,n){
		cin >> a1[i].a >> a1[i].b >> a1[i].c >> a1[i].d;
		if(a1[i].c > a1[i].d){
			a2[a1[i].a].score += 3;
			a2[a1[i].a].hs += a1[i].c - a1[i].d; a2[a1[i].b].hs += a1[i].d - a1[i].c;
			a2[a1[i].a].res += a1[i].c; a2[a1[i].b].res += a1[i].d;
		}else if(a1[i].c < a1[i].d){
			a2[a1[i].b].score += 3;
			a2[a1[i].a].hs += a1[i].c - a1[i].d; a2[a1[i].b].hs += a1[i].d - a1[i].c;
			a2[a1[i].a].res += a1[i].c; a2[a1[i].b].res += a1[i].d;
		}else if(a1[i].c == a1[i].d){
			a2[a1[i].a].score += 1; a2[a1[i].b].score += 1;
			a2[a1[i].a].res += a1[i].c; a2[a1[i].b].res += a1[i].d;
		}
	}
	sort(a2.begin()+1,a2.begin()+5,cmp);
    FOR(int,i,1,4) cout << a2[i].team << " ";
    cout << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
