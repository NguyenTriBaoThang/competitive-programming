#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N; cin >> N;

    set<string> students;

    for (int i = 0; i < N; ++i) {
        string id;
        cin >> id;
        students.insert(id);
    }

    for (const string& id : students) {
        cout << id << " ";
    }	
}

int main() {
    solve();
    return 0;
}