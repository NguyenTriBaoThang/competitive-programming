#include<bits/stdc++.h>
using namespace std;
//Free Contest 83 - INCEQUAL, Free Contest Testing Round 54 - INCEQUAL
void solve(){
	int n, x, res=0; cin >> n >> x;
	vector<int> v(n+5);
	for(int i=0;i<n;i++){
		cin >> v[i];
		res = max(res,v[i]);
	}
	if(x > res){
		cout << "-1";
		return;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if((res-v[i]) == 0) continue;
		if((res-v[i])%x!=0){
			cout << "-1";
			return;
		}
		cnt += (int)((res-v[i])/x);
	}
	cout << cnt;
}

int main(){
	solve();
	return 0;
}