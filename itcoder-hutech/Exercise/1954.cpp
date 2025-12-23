#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

void solve(){
	int N;
    cin >> N;

    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i); 
    }

    int cntGroup = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            ++cntGroup;
            dfs(i);
        }
    }

    cout << cntGroup << endl;
}

int main() {
    solve();
    return 0;
}