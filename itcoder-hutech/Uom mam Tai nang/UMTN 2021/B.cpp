#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

void solve(){
    map<int,int> mp; bool check = true;
    int n, a[N], s, jmin, d;
    double k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int j = 1; j < n; j++){
        s = a[j];
        jmin = j;
        for(int i = j+1; i <= n; i++){
            s += a[i];
            double rs = (double)s/(i-jmin+1);
            if(rs == k ){
                d = i-jmin+1;
                mp[jmin] = d;
                check = false;
            }
        }
    }
    if(check){
        cout << 0 << endl;
    }else{
        long aMax=0, vt=0;
        for(auto it : mp){
            if(aMax < it.second){
                aMax = it.second; 
                vt = it.first;
            }
        }
        cout << vt << " " << aMax << endl; 
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
