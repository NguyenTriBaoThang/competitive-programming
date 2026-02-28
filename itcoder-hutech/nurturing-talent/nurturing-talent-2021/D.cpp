#include<bits/stdc++.h>
#include<map>
#include<set>
#include<string>
using namespace std;

bool checkSNT(int n){
    if(n<2) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) 
            return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) 
        cin >> x;
    int cnt=0, s1=0, cntMax=0;
    bool check=true;
    for(int i=0;i<n-1;i++){
        s1 = a[i] + a[i+1];
        if(checkSNT(s1)){
            cnt++;
            check = false;
            if(cntMax < cnt) 
                cntMax = cnt;
        }else 
            cnt = 0;
    }
    if(check) 
        cout << 0 << endl;
    else 
        cout << cntMax + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
