
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 1;
#define REP(dl, a, b, c) for(dl a = b; a < c; a++)
#define FOR(dl, a, b, c) for(dl a = b; a <= c; a++)

bool match(const string& a, const string &b, int pos){
    REP(size_t, i, 0, b.size()){
        if(b[i] != '_' && a[pos + i] != b[i]){
            return false;
        }
    }
    return true;
}

bool contains(const string& a, const string& b){
    REP(size_t, i, 0, a.size() - b.size() + 1){
        if(match(a, b, i)){
            return true;
        }
    }
    return false;
}

void solve(){
    string a, b; cin >> a >> b;
    if(contains(a, b))
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    solve();
    return 0;
}