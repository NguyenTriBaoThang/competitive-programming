#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
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

//So thuc x: bi = ai - x;
//f(x) = max(moi doan con)|Tong Bi|

int n;
double a[N];

double f(const double &x){
	FOR(int, i, 1, n){
		a[i] -= x;
	}
	double ret = 0.000;
	double minValue = 0.000;
	double maxValue = 0.000;
	double sum = 0.000;
	FOR(int, i, 1, n){
		sum += a[i];
		ret = max(ret, sum - minValue); //Tim duong lon nhat
		ret = max(ret, maxValue - sum); //Tim am lon nhat Si - maxS
		minValue = min(minValue, sum);
		maxValue = max(maxValue, sum);
	}
	minValue = a[n];
	maxValue = a[n];
	sum = a[n];
	FORE(int, i, n-1, 1){
		sum += a[i];
		ret = max(ret, sum - minValue);
		ret = max(ret, maxValue - sum);
		minValue = min(minValue, sum);
		maxValue = max(maxValue, sum);
	}
	FOR(int, i, 1, n){
		a[i] += x;
	}
	return ret;
}

void solve(){
	cin >> n;
	FOR(int, i, 1, n){
		cin >> a[i];
	}
	double lo = -20000.0000;
	double hi =  20000.0000;
	double ans = 0.0000;
	FOR(int, step, 1, 100){
		double u = (2.0 * lo + hi) / 3.0;
		double v = (lo + 2.0 * hi) / 3.0;
		double fu = f(u);
		double fv = f(v);
		if(fu >= fv){
			ans = fu;
			lo = u;
		}else{
			ans = fv;
			hi = v;
		}
	}
	cout << fixed << setprecision(12) << ans;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://codeforces.com/problemset/problem/578/C
	solve();
	return 0;
}