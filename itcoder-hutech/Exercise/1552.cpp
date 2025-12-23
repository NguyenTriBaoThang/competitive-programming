#include<bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const int N = 5e5 + 5;
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

ll findMinHeightDifference(int n, vector<ll>& heightsA, vector<ll>& heightsB, vector<ll>& heightsC, vector<ll>& heightsD) {
	sort(all(heightsA));
	sort(all(heightsB));
	sort(all(heightsC));
	sort(all(heightsD));

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> minHeap;

    vector<vector<ll>> heights = {heightsA, heightsB, heightsC, heightsD};
    for (int i = 0; i < 4; ++i) {
        minHeap.push(make_tuple(heights[i][0], i, 0));
    }

    ll currentMaxHeight = max({heightsA[0], heightsB[0], heightsC[0], heightsD[0]});
    ll minDiff = INF_LL;

    while (true) {
        auto topElement = minHeap.top();
        ll currentMinHeight = get<0>(topElement);
        int classIndex = get<1>(topElement);
        int studentIndex = get<2>(topElement);
        minHeap.pop();

        ll currentDiff = currentMaxHeight - currentMinHeight;
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }

        if (studentIndex + 1 < n) {
            ll nextHeight = heights[classIndex][studentIndex + 1];
            minHeap.push(make_tuple(nextHeight, classIndex, studentIndex + 1));
            if (nextHeight > currentMaxHeight) {
                currentMaxHeight = nextHeight;
            }
        } else {
            break;
        }
    }

    return minDiff;
}

void solve(){
	int n; cin >> n;

    vector<ll> heightsA(n), heightsB(n), heightsC(n), heightsD(n);
    REP(int, i, 0, n) cin >> heightsA[i];
    REP(int, i, 0, n) cin >> heightsB[i];
    REP(int, i, 0, n) cin >> heightsC[i];
    REP(int, i, 0, n) cin >> heightsD[i];

    ll result = findMinHeightDifference(n, heightsA, heightsB, heightsC, heightsD);
    cout << result << endl;
    
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
