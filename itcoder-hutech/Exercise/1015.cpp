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

void solve(){
    ll arr[100], n=4, cnt1=0, cnt2=0, cnt3=0;
    FOR(ll,i,1,n){
        cin >> arr[i];
        if(arr[i] > 2) cnt1 += 1;
        if(arr[i] > 5) cnt2 += 1;

    }
    if(cnt1 == 4 || cnt2 >= 3){
        cout << -1 << endl;
        return;
    }
    ll a=0, b=0, c=0, d=0, res=-1, vt=-1;
    FOR(ll,i,1,n){
        if(0<=arr[i] && arr[i]<=2){
            if(arr[i] > res){
                res = arr[i]; vt = i;
            }
        }
    }
    arr[vt] = -1; a = res; res=-1; vt=-1;
    if(a == 2){
        FOR(ll,i,1,n){
        	if(arr[i] > 3) cnt3 += 1;
		}
		if(cnt3 == 3){
			cout << -1 << endl;
        	return;
		}
        FOR(ll,i,1,n){
            if(0<=arr[i] && arr[i]<=3){
                if(arr[i] > res){
                    res = arr[i]; vt = i;
                }
            }
        }
    }else{
        FOR(ll,i,1,n){
            if(0<=arr[i] && arr[i]<=9){
                if(arr[i] > res){
                    res = arr[i]; vt = i;
                }
            }
        }
    }
    arr[vt] = -1; b = res; res=-1; vt=-1;
    FOR(ll,i,1,n){
        if(0<=arr[i] && arr[i]<=5){
            if(arr[i] > res){
                res = arr[i]; vt = i;
            }
        }
    }
    arr[vt] = -1; c = res; res=-1; vt=-1;
    FOR(ll,i,1,n){
        if(arr[i] != -1){
            d = arr[i];
            break;
        }
    }
    cout << a << b << ":" << c << d <<endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
