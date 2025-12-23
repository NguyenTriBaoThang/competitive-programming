#include<bits/stdc++.h>
using namespace std;

void solve(){
    long n,s; cin >> n;
    if(n<=200){
        if(n>100){
            s = 50*1678 + 50*1734 + (n-100) * 2014;
        }else{
            if(n<=50){
                s = n * 1678;
            }else{
                s = 50*1678 + (n-50) * 1734;
            }
        }
    }else{
        if(n<=400){
            if(n<=300){
                s = 50*1678 + 50*1734 + 100 * 2014 + (n-200) * 2536;
            
            }else{
                s = 50*1678 + 50*1734 + 100 * 2014 + 100 * 2536 + (n-300) * 2834;
            }
        }else{
            s = 50*1678 + 50*1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (n-400)*2927;
        }
    }
    long vt = round((float)s * 10 / 100);
    cout << vt+s << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}