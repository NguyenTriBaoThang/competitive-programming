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
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxN = 50000;
const double eps = 1e-14;
const int BLOCK = 550;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const long long INF_LL = 1e18;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define double long double
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define prec(n) setprecision(n) << fixed
#define FOR(dl,i,a,b) for(dl i=a;i<(b);i++)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } 
	P perp() const { return P(-y, x); } 
	P normal() const { return perp().unit(); }
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

typedef Point<double> P;
int n;
P Or, Od;
vector<P> win;

struct IT{
	P a,b;
	bool operator<(IT o) const {
		pair<int,P> i1 = lineInter(Or,Od,a,b);
		pair<int,P> i2 = lineInter(Or,Od,o.a,o.b);
		assert(i1.first==1 && i2.first==1);
		return (Or-i1.se).dist()<(Or-i2.se).dist();
	}
	bool operator==(IT o) const {
		return (a==o.a && b==o.b);
	}
};

void input() {
	cin >> Or.x >> Or.y >> n;
	FOR(int,i,0,n) {
		double x,y;
		cin >> x >> y;
		win.pb(P(x,y)-Or);
	}
	Or = P(0,0);
}

vector<P> v;
bool isUpper(P x) {
	if (x.y>0) return true;
	if (x.y<0) return false;
	if (x.y==0 and x.x>0) return true;
	return false;
}
bool cmp(P x,P y) {
	bool x1 = isUpper(x), y1 = isUpper(y);
	if (x1!=y1) return x1>y1;
	return (x.cross(y)>0);
}
int index(vector<P>& v,P p) {
	int res = distance(v.begin(),lower_bound(v.begin(),v.end(),p,cmp));
	assert(res!=sz(v));
	assert(v[res].cross(p)==0);
	return res;
}
int nxt(vector<P>& v,int x) { return (x+1)%sz(v); }

vector<IT> Insert[maxN+1];
vector<IT> Delete[maxN+1];
set<IT> ans;

void programme() {
	FOR(int,i,0,n) { v.pb(win[i]); }
	sort(v.begin(),v.end(),cmp);
	v.erase(unique(all(v),[](P x,P y) { return x.cross(y) == 0; }),v.end());
	Od = v[0]+v[sz(v)-1];
	FOR(int,i,0,n) {
		if (index(v,win[i])==index(v,win[nxt(win,i)])) continue;
		P a = win[i], b = win[nxt(win,i)];
		if (a.cross(b)<0) swap(a,b);
		Insert[index(v,a)].pb({a,b});
		Delete[index(v,b)].pb({a,b});
		if (index(v,a) > index(v,b)) {
			int tmp = sz(ans);
			ans.insert({a,b});
			assert(tmp+1==sz(ans));
		}
	}
}

void solve() {
	double res = 0.0;
	FOR(int,i,0,sz(v)) {
		FOR(int,j,0,sz(Delete[i])) {
			assert(ans.count(Delete[i][j]));
			ans.erase(Delete[i][j]);
		}
		Od = v[nxt(v,i)]+v[i];
		FOR(int,j,0,sz(Insert[i])) {
			int tmp = sz(ans);
			ans.insert(Insert[i][j]);
			assert(tmp+1==sz(ans));
		}
		assert(sz(ans)>0);
		IT s = *ans.begin();
		P i1 = lineInter(s.a,s.b,v[i],Or).se;
		P i2 = lineInter(s.a,s.b,Or,v[nxt(v,i)]).se;
		res += abs(Or.cross(i1,i2));
	}
	cout << prec(2) << res*0.5 << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	input();
	programme();
	solve();
	return 0;
}