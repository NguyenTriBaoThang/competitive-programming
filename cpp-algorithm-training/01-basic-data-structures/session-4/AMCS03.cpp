#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

// Pi(T) = Si * T + Di;
// f(T)=max(Pi​(T))−min(Pj​(T))
// Khoảng cách giữa người dẫn đầu và người cuối cùng tại thời điểm T.

struct programmer{
	double distance;
	double speed;
};

programmer a[N];
int n;
double K;

double f(const double &T){
	double maxValue = a[1].speed * T + a[1].distance;
	double minValue = a[1].speed * T + a[1].distance;
	FOR(int, i, 2, n){
		maxValue = max(maxValue, a[i].speed * T + a[i].distance);
		minValue = min(minValue, a[i].speed * T + a[i].distance);
	}
	return maxValue - minValue;
}

void solve(){
	cin >> n >> K;
	FOR(int, i, 1, n){
		cin >> a[i].speed >> a[i].distance;
	}
	double lo = 0.0, hi = K;
	FOR(int, step, 1, 100){
		double u = (2.0 * lo + hi) / 3;
		double v = (lo + 2.0 * hi) / 3;
		if(f(u) > f(v)){
			lo = u;
		}else{
			hi = v;
		}
	}
	cout << fixed << setprecision(6) << f(lo);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://www.codechef.com/problems/AMCS03
	solve();
	return 0;
}