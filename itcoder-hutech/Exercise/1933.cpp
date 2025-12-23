#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
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
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
#define REP(dl,a,b,c) for(dl a=b;a<c;a++)
#define FOR(dl,a,b,c) for(dl a=b;a<=c;a++)
#define REPE(dl,a,b,c) for(dl a=b;a>c;a--)
#define FORE(dl,a,b,c) for(dl a=b;a>=c;a--)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& x : v) is >> x;
    return is;
}

class DisjointSet{
private:
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        FOR(int, i, 1, n){
            parent[i] = i;
        }
    }

    int find(int x){
        if (parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY){
            if (size[rootX] < size[rootY]){
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }else{
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
    
    int getSize(int x){
        return size[find(x)];
    }
};

void solve(){
	int N, M; cin >> N >> M;
    DisjointSet ds(N);
    REP(int, i, 0, M){
        int a, b; cin >> a >> b;
        ds.unionSet(a, b);
    }
    unordered_map<int, int> componentSize;
    FOR(int, i, 1, N){
        int root = ds.find(i);
        componentSize[root]++;
    }
    int cnt = 0, villageCount = 0;
    for (const auto& entry : componentSize){
        if (entry.second >= 2){
            cnt++;
        }else{
            villageCount++;
        }
    }
    cout << abs(villageCount - cnt) << endl;
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
