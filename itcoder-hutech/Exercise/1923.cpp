#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

bool will_overflow(ll a, ll b){
    if(a == 0 || b == 0) return false;
    return a > LLONG_MAX / b;
}

ll safe_lcm(ll a, ll b){
    ll g = gcd(a, b);
    a /= g;
    if(will_overflow(a, b)) return -1;
    return a * b;
}

map<ll,int> primeFactors(ll n){
    map<ll,int> mp;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) mp[n]++;
    return mp;
}

ll calc(ll n){
    auto mp = primeFactors(n);
    ll res = 1;
    for(auto &p: mp) res *= (p.second + 1);
    return res;
}

void solve(){
    int N, M; cin >> N >> M;
    vector<ll> A(N), B(M);
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<M; i++) 
        cin >> B[i];
    ll g = A[0];
    for(int i=1; i<N; i++)
        g = gcd(g, A[i]);
    ll l = B[0];
    for(int i=1; i<M; i++){
        l = safe_lcm(l, B[i]);
        if(l == -1) break; 
    }
    if(l == -1 || g % l != 0){
        cout << 0 << endl;
        return;
    }
    ll gDiv = g / l;
    cout << calc(gDiv) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
