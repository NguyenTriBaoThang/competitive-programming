#include<bits/stdc++.h>
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

bool checkYear(int year){
    if(year < 0) return false;
    return true;
}

bool checkLeapYear(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	return false;
}

bool checkMonth(int month){
	if(month < 1 || month > 12) return false;
	return true;
}

bool checkDay(int day, int month,int year){
	switch(month){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(day < 1 || day > 31){
				return false;
			}else{
				return true;
			}
		case 4: case 6: case 9: case 11:
			if(day < 1 || day > 30){
				return false;
			}else{
				return true;
			}
		case 2:
			if(checkLeapYear(year)){
				if(day < 1 || day > 29){
					return false;
				}else{
					return true;
				}
			}else{
				if(day < 1 || day > 28){
					return false;
				}else{
					return true;
				}
			}
	}
}

void solve(){
    int day=0, month=0, year=0; cin >> day >> month >> year;
    if(checkYear(year) && checkMonth(month) && checkDay(day,month,year)) cout << "Valid" << endl;
    else cout << "None" << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
