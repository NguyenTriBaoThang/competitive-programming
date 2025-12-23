#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6 + 100;
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)

bool notSNT[maxN]; int SNT[maxN];
int cntSNT; ll n;

void findSNT(){
    int lim = pow(n, 1.0/3);
    notSNT[1] = true;
    for(int i = 2; i*i <= lim; i++){
        if(!notSNT[i])
            for(int j = i*i; j <= lim; j+=i)
                notSNT[j] = true;
    }
    FOR(int,i,1,lim) if(!notSNT[i]) SNT[++cntSNT] = i;
}

bool checkSNT(){
    FOR(int,i,1,cntSNT){
        if(n % (SNT[i] * SNT[i]) == 0) return false;
        if(n % SNT[i] == 0) n /= SNT[i];
    }
    if(n > 1) if (sqrt(n) == floor(sqrt(n))) return false;
    return true;
}

void solve(){
    cin >> n; findSNT();
    cout << (checkSNT() ? "NO" : "YES") << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
