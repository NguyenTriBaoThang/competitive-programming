#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v.begin(),v.begin()+n);
	cout << ((n < k) ? "Not Found" : std::to_string(v[n - k]));
}

int main(){
	solve();
	return 0;
}