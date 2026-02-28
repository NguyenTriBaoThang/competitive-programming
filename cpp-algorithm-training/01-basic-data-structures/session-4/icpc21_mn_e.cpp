#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
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

double A, H;

//Dung / 3 (Terbart Search) -> Ham co 1 dinh duy nhat tuc la TANG roi GIAM (tim max), GIAM roi TANG (tim min)

double f(const double &x){
	if(3.0 * x >= H){
		return 100.0;
	}else if(6.0 * x >= H){
		//f(x) = mx + b
		//m = do thay doi f / do thay do x, m = y2-y1/x2-x1; (H/6,A) (H/3,100)
		//b = ?, di qua duong thang (H/6,A), -> f(x) = m*x + b -> A = m * (H/6) + b -> thay m o tren tih bao -> b;
		return (600.0 - 6.0 * A) * x / H + 2.0 * A - 100.0;
	}else{
		return (6.0 * A) * x / H; 
	}
}

void solve(){
	cin >> A >> H;
	double lo = 0.0, hi = H;
	FOR(int, i, 1, 1000){
		// u = lo + 1/3(hi - lo) 
		// u ben trai, v ben phai
		// lo ----- u ----- v ----- hi 
		double u = (2.0 * lo + hi) / 3.0;
		double v = (lo + hi * 2.0) / 3.0;
		//g(u) > g(v) nghia la ben trai cao hon ben phai -> Dinh nam ben trai
		if((H - u) * f(u) > (H - v) * f(v)){
			hi = v;
		}else{
			lo = u;	
		}
	}
	cout << fixed << setprecision(12) << (H - lo) * f(lo);
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	//https://oj.vnoi.info/problem/icpc21_mn_e
	solve();
	return 0;
}