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
typedef pair<ll, ll> pii;
const int maxN = 1e3 + 100;
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

// Vet can - xu ly
//a b c d
//b a, c a, d a,
//a b, a c, a d,

//c d, b d, b c,
//d c, d b, c b,

bool checkThang(int thang){
	if(thang < 1 || thang > 12) return false;
	return true;
}

bool checkNgay(int ngay, int thang){
	switch(thang){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(ngay < 1 || ngay > 31){
				return false;
			}else{
				return true;
			}
		case 4: case 6: case 9: case 11:
			if(ngay < 1 || ngay > 30){
				return false;
			}else{
				return true;
			}
		case 2:
			if(ngay < 1 || ngay > 29){
				return false;
			}else{
				return true;
			}
	}
	return false;
}

typedef struct CHECKNAM{
	int a1, a2, a3, a4;
}NAM;

void solve(){
	NAM arr[maxN]; int vt=0;
    ll a=0, b=0, c=0, d=0; cin >> a >> b >> c >> d;
    if(checkThang(c*10+d)){
    	if(checkNgay(b*10+a,c*10+d)){
    		arr[vt].a1 = b, arr[vt].a2 = a, arr[vt].a3 = c, arr[vt].a4 = d;
    		vt += 1;
		}
		if(checkNgay(a*10+b,c*10+d)){
			arr[vt].a1 = a, arr[vt].a2 = b, arr[vt].a3 = c, arr[vt].a4 = d;
    		vt += 1;
		}
	}
	if(checkThang(d*10+c)){
    	if(checkNgay(b*10+a,d*10+c)){
    		arr[vt].a1 = b, arr[vt].a2 = a, arr[vt].a3 = d, arr[vt].a4 = c;
    		vt += 1;
		}
		if(checkNgay(a*10+b,d*10+c)){
			arr[vt].a1 = a, arr[vt].a2 = b, arr[vt].a3 = d, arr[vt].a4 = c;
    		vt += 1;
		}
	}
	if(checkThang(b*10+a)){
    	if(checkNgay(c*10+d,b*10+a)){
    		arr[vt].a1 = c, arr[vt].a2 = d, arr[vt].a3 = b, arr[vt].a4 = a;
    		vt += 1;
		}
		if(checkNgay(d*10+c,b*10+a)){
			arr[vt].a1 = d, arr[vt].a2 = c, arr[vt].a3 = b, arr[vt].a4 = a;
    		vt += 1;
		}
	}
	if(checkThang(a*10+b)){
    	if(checkNgay(c*10+d,a*10+b)){
    		arr[vt].a1 = c, arr[vt].a2 = d, arr[vt].a3 = a, arr[vt].a4 = b;
    		vt += 1;
		}
		if(checkNgay(d*10+c,a*10+b)){
			arr[vt].a1 = d, arr[vt].a2 = c, arr[vt].a3 = a, arr[vt].a4 = b;
    		vt += 1;
		}
	}
	if(checkThang(b*10+d)){
    	if(checkNgay(c*10+a,b*10+d)){
    		arr[vt].a1 = c, arr[vt].a2 = a, arr[vt].a3 = b, arr[vt].a4 = d;
    		vt += 1;
		}
		if(checkNgay(a*10+c,b*10+d)){
			arr[vt].a1 = a, arr[vt].a2 = c, arr[vt].a3 = b, arr[vt].a4 = d;
    		vt += 1;
		}
	}
	if(checkThang(d*10+b)){
    	if(checkNgay(c*10+a,d*10+b)){
    		arr[vt].a1 = c, arr[vt].a2 = a, arr[vt].a3 = d, arr[vt].a4 = b;
    		vt += 1;
		}
		if(checkNgay(a*10+c,d*10+b)){
			arr[vt].a1 = a, arr[vt].a2 = c, arr[vt].a3 = d, arr[vt].a4 = b;
    		vt += 1;
		}
	}
	if(checkThang(c*10+a)){
    	if(checkNgay(b*10+d,c*10+a)){
    		arr[vt].a1 = b, arr[vt].a2 = d, arr[vt].a3 = c, arr[vt].a4 = a;
    		vt += 1;
		}
		if(checkNgay(d*10+b,c*10+a)){
			arr[vt].a1 = d, arr[vt].a2 = b, arr[vt].a3 = c, arr[vt].a4 = a;
    		vt += 1;
		}
	}
	if(checkThang(a*10+c)){
    	if(checkNgay(b*10+d,a*10+c)){
    		arr[vt].a1 = b, arr[vt].a2 = d, arr[vt].a3 = a, arr[vt].a4 = c;
    		vt += 1;
		}
		if(checkNgay(d*10+b,a*10+c)){
			arr[vt].a1 = d, arr[vt].a2 = b, arr[vt].a3 = a, arr[vt].a4 = c;
    		vt += 1;
		}
	}
	if(checkThang(b*10+c)){
    	if(checkNgay(a*10+d,b*10+c)){
    		arr[vt].a1 = a, arr[vt].a2 = d, arr[vt].a3 = b, arr[vt].a4 = c;
    		vt += 1;
		}
		if(checkNgay(d*10+a,b*10+c)){
			arr[vt].a1 = d, arr[vt].a2 = a, arr[vt].a3 = b, arr[vt].a4 = c;
    		vt += 1;
		}
	}
	if(checkThang(c*10+b)){
    	if(checkNgay(a*10+d,c*10+b)){
    		arr[vt].a1 = a, arr[vt].a2 = d, arr[vt].a3 = c, arr[vt].a4 = b;
    		vt += 1;
		}
		if(checkNgay(d*10+a,b*10+c)){
			arr[vt].a1 = d, arr[vt].a2 = a, arr[vt].a3 = c, arr[vt].a4 = b;
    		vt += 1;
		}
	}
	if(checkThang(a*10+d)){
    	if(checkNgay(b*10+c,a*10+d)){
    		arr[vt].a1 = b, arr[vt].a2 = c, arr[vt].a3 = a, arr[vt].a4 = d;
    		vt += 1;
		}
		if(checkNgay(c*10+b,a*10+d)){
			arr[vt].a1 = c, arr[vt].a2 = b, arr[vt].a3 = a, arr[vt].a4 = d;
    		vt += 1;
		}
	}
	if(checkThang(d*10+a)){
    	if(checkNgay(b*10+c,d*10+a)){
    		arr[vt].a1 = b, arr[vt].a2 = c, arr[vt].a3 = d, arr[vt].a4 = a;
    		vt += 1;
		}
		if(checkNgay(c*10+b,d*10+a)){
			arr[vt].a1 = c, arr[vt].a2 = b, arr[vt].a3 = d, arr[vt].a4 = a;
    		vt += 1;
		}
	}
	if(vt == 0){
		cout << -1 << endl;
		return;
	}
	if(vt == 1){
		cout << arr[0].a1 << " " << arr[0].a2 << " " << arr[0].a3 << " " << arr[0].a4 << endl;
		return;
	}
	ll b1=arr[0].a1, b2=arr[0].a2, b3=arr[0].a3, b4=arr[0].a4;
	FOR(ll,i,1,vt-1){
		if(arr[i].a3*10+arr[i].a4 == b3*10 + b4){
			if(arr[i].a1*10+arr[i].a2 > b1*10 + b2){
				b1=arr[i].a1, b2=arr[i].a2, b3=arr[i].a3, b4=arr[i].a4;
			}
		}else if(arr[i].a3*10+arr[i].a4 > b3*10 + b4){
			b1=arr[i].a1, b2=arr[i].a2, b3=arr[i].a3, b4=arr[i].a4;
		}
	}
	cout << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
