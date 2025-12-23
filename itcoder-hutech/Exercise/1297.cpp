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

//Point
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
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

typedef Point<double> P;

pair<P,P> divide(P a,P b,double k)
{
	if (k==1)
		return {(a+b)/2.0,(a+b)/2.0};

	P m1 = a+(b-a)*(k/(k+1.0));

	if (k<1){
		P m2 = a - (b-a)*k/(1-k);
		return {m1,m2};
	}else{
		P m2 = b + (b-a)*1/(k-1);
		return {m1,m2};
	}
}

bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {
	if (a == b) { assert(r1 != r2); return false; }
	P vec = b - a;
	double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
		   p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
	if (sum*sum < d2 || dif*dif > d2) return false;
	P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
	*out = {mid + per, mid - per};
	return true;
}

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a)/(b-a).dist();
}

template<class P>
P lineProj(P a, P b, P p, bool refl=false) {
	P v = b - a;
	return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}

template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
	double h2 = r*r - a.cross(b,c)*a.cross(b,c)/(b-a).dist2();
	if (h2 < 0) return {};
	P p = lineProj(a, b, c), h = (b-a).unit() * sqrt(h2);
	if (h2 == 0) return {p};
	return {p - h, p + h};
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0)
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}
//

vector<P> o;
vector<double> r;
void solve(){
    FOR(int,i,0,2){
		double x, y, R; cin >> x >> y >> R;
		o.pb(P(x,y));
		r.pb(R);
	}
	pair<P,P> p1 = divide(o[0],o[1],r[0]/r[1]);
	pair<P,P> p2 = divide(o[1],o[2],r[1]/r[2]);
	if(p1.fi==p1.second and p2.fi==p2.second){
		P n1 = o[1] - o[0]; P u1 = P(n1.y,-n1.x);
		P n2 = o[2] - o[1]; P u2 = P(n2.y,-n2.x);
		pair<int,P> it = lineInter(p1.fi,p1.fi+u1,p2.fi,p2.fi+u2);
		if(it.fi==0) return;
		else if(it.fi==1) cout << prec(5) << it.se.x << " " << it.se.y << endl;
	}else if((!(p1.fi==p1.se)) and (!(p2.fi==p2.se))){
		P c1 = (p1.fi+p1.se)*0.5; double r1 = (p1.fi-p1.se).dist()*0.5;
		P c2 = (p2.fi+p2.se)*0.5; double r2 = (p2.se-p2.fi).dist()*0.5;
		pair<P,P> it;
		if (circleInter(c1,c2,r1,r2,&it)){
			double _a1 = atan(r[0]/(it.fi-o[0]).dist());
			double _a2 = atan(r[0]/(it.se-o[0]).dist());
			if (_a1 > _a2) cout << prec(5) << it.fi.x << " " << it.fi.y << endl;
			else cout << prec(5) << it.se.x << " " << it.se.y << endl;
		}
	}else{
		P n1 = o[1] - o[0]; P u1 = P(n1.y,-n1.x);
		P n2 = o[2] - o[1]; P u2 = P(n2.y,-n2.x);
		P c1 = (p1.fi+p1.se)*0.5; double r1 = (p1.fi-p1.se).dist()*0.5;
		P c2 = (p2.fi+p2.se)*0.5; double r2 = (p2.se-p2.fi).dist()*0.5;
		vector<P> it;
		if(!(p1.fi==p1.se)) it = circleLine(c1,r1,p2.fi,p2.fi+u2);
		else it = circleLine(c2,r2,p1.fi,p1.fi+u1);
		double aMax = -1;
		P cr;
		for(P p: it){
			double _a = atan(r[0]/(p-o[0]).dist());
			if (_a > aMax){
				aMax = _a;
				cr = p;
			}
		}
		if (aMax != -1) cout << prec(5) << cr.x << " " << cr.y << endl;
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
