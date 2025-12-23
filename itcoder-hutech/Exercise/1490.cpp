#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50 + 10;
const int MOD = 1e9 + 7;
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
    int n; cin >> n;
	string topic; cin >> topic;
    int t; cin >> t;
    while(t--){
        string answer; cin >> answer;
        int cnt = inner_product(
            topic.begin(), topic.end(),
            answer.begin(),
            0,
            plus<>(),
            equal_to<>()
        );
        /*
        for(int i=0; i<n; i++){
            if(topic[i] == answer[i]){
                cnt++;
            }
        }
        */
        cout << fixed << setprecision(2) << (double)cnt/n * 10 << endl;
    }
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}