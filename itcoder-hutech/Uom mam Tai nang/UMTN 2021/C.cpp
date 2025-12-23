#include<bits/stdc++.h>
#include<map>
#include<set>
#include<string>
using namespace std;

void solve(){
	int n; cin >> n;
	map<int, int> mp;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		mp[x]++;
	}
	int max = 0, s=0, kq=0;
	for(auto x : mp){
		kq += x.second;
		s = ceil((double)kq/x.first);
		if(max < s) max = s;
	}
	cout << max << endl;
} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
