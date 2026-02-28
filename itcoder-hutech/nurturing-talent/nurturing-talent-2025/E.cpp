#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const int INF = 1e9 + 100;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

void solve(){
    ll N;
    int M, K;
    ll L;
    if(!(cin >> N >> M >> K >> L)) return;
    vector<ll> C(M + 1), S(M + 1);
    FOR(int, i, 1, M) cin >> C[i];
    FOR(int, i, 1, M) cin >> S[i];
    vector<vector<int>> adj(M + 1);
    REP(int, i, 0, K){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> comp(M + 1, -1); 
    vector<ll> compCap;
    int compCnt = 0;
    FOR(int, i, 1, M){
        if(comp[i] == -1){
            queue<int> q;
            q.push(i);
            comp[i] = compCnt;
            ll sumC = 0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                sumC += C[u];
                for(int v : adj[u]){
                    if (comp[v] == -1) {
                        comp[v] = compCnt;
                        q.push(v);
                    }
                }
            }
            if (sumC > L) sumC = L;
            compCap.push_back(sumC);
            ++compCnt;
        }
    }
    ll totalCap = 0;
    for(ll x : compCap) totalCap += x;
    if(totalCap < N) {
        cout << 0;
        return;
    }
    struct Room{
        ll S, C;
        int comp;
    };
    vector<Room> rooms;
    rooms.reserve(M);
    FOR(int, i, 1, M){
        rooms.push_back({S[i], C[i], comp[i]});
    }
    sort(rooms.begin(), rooms.end(), [](const Room &a, const Room &b) {
        return a.S > b.S; 
    });
    vector<ll> usedInComp(compCnt, 0); 
    ll remain = N;  
    long long ans = 0;
    for(const auto &room : rooms){
        if(remain == 0) break;
        int c = room.comp;
        ll compRemain = compCap[c] - usedInComp[c];
        if(compRemain <= 0) continue;
        ll canPut = min(room.C, min(compRemain, remain));
        if(canPut <= 0) continue;
        ans += canPut * room.S;
        usedInComp[c] += canPut;
        remain -= canPut;
    }
    if(remain > 0){
        cout << 0;
    }else{
        cout << ans;
    }
}

int main(int argc, char** argv){
    solve();
    return 0;
}