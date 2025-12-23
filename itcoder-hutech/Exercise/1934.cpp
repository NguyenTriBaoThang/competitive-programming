#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ll, ll> pii;
typedef pair<int, ii> iii;
const int N = 1e5 + 5;
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

string s, t;
int n, q, l, r;

struct suffixArray{
	vector<int> sa, rk, lcp;
	int len; string s;
	void getsa(){
		sa.clear(); rk.clear(); sa.resize(len + 1, 0); rk.resize(len + 1, 0); sa[0] = len;
		FOR(int, i, 1, len) 
			sa[i] = i - 1;
		sort(sa.begin() + 1, sa.end(), [&](int a, int b) {return s[a] < s[b];});
		FOR(int, i, 1, len){
			int a = sa[i - 1], b = sa[i];
			if(i > 1 && s[a] == s[b]) 
				rk[b] = rk[a];
			else 
				rk[b] = i;
		}
		for(int siz = 1; siz <= len; siz *= 2){
			vector<int> lsa(sa), lrk(rk), cnt(len + 1);
			FOR(int, i, 0, len) cnt[i] = i;
			for(auto t : lsa){
				int T = t - siz;
				if(T >= 0) 
					sa[cnt[lrk[T]]++] = T;
			}
			FOR(int, i, 1, len){
				int a = sa[i - 1], b = sa[i];
				if(lrk[a] == lrk[b] && lrk[a + siz] == lrk[b + siz]) 
					rk[b] = rk[a];
				else
					rk[b] = i;
			}
		}
	}
	
	void getlcp(){
		lcp.clear(); lcp.resize(len, 0); int h = 0;
		REP(int, b, 0, len){
			int a = sa[rk[b] - 1];
			while(a + h < len && s[a + h] == s[b + h]) 
				++h;
			lcp[rk[b] - 1] = h; 
			if(h) --h; 
		}
	}
	
	void init(string _s){
		s = _s; len = (int)s.size();
		getsa(); getlcp();
	}
	
	int bs_rit(string &t){
		int l = 0, r = len + 1;
		while(l + 1 <= r - 1){
			int mid = (l + r) >> 1;
			bool fl = 1; int st = sa[mid];
			REP(int, i, 0, sz(t)){
				if(st + i >= len || s[st + i] < t[i]){
					break;
				}
				if(s[st + i] > t[i]){
					fl = 0; break;
				}
			}
			if(fl) l = mid;
			else r = mid;
		}
		return l;
	}
	
	int bs_lft(string &t){
		int l = 0, r = len + 1;
		while(l + 1 <= r - 1){
			int mid = (l + r) >> 1;
			bool fl = 0; int st = sa[mid];
			REP(int, i, 0, sz(t)){
				if(st + i >= len || s[st + i] < t[i]){
					fl = 1; break;
				}
				if(s[st + i] > t[i]){
					break;
				}
			}
			if(fl) 
				l = mid;
			else 
				r = mid;
		}
		return r;
	}
}sa; 

int ls[N << 5], rs[N << 5], sum[N << 5], rt[N], tot;
int build(int l, int r){
	int root = ++tot;
	if (l == r) 
		return root;
	int mid = (l + r) >> 1;
	ls[root] = build(l, mid);
	rs[root] = build(mid + 1, r);
	return root;
}

int update(int k, int l, int r, int root){
	int dir = ++tot;
	ls[dir] = ls[root], rs[dir] = rs[root], sum[dir] = sum[root] + 1;
	if (l == r) 
		return dir;
	int mid = (l + r) >> 1;
	if (k <= mid)
		ls[dir] = update(k, l, mid, ls[dir]);
	else
		rs[dir] = update(k, mid + 1, r, rs[dir]);
  return dir;
}

int query(int u, int v, int l, int r, int ql, int qr){
	int mid = (l + r) >> 1;
	if(ql <= l && r <= qr) 
		return sum[v] - sum[u];
	int ans = 0;
	if(ql <= mid)
		ans += query(ls[u], ls[v], l, mid, ql, qr);
	if(mid + 1 <= qr)
		ans += query(rs[u], rs[v], mid + 1, r, ql, qr);
	return ans;
}

void solve(){
	cin >> s >> q;
	sa.init(s); n = sz(s);
	rt[0] = build(1, n);
	FOR(int, i, 1, n)
		rt[i] = update(sa.rk[i - 1], 1, n, rt[i - 1]);
	while(q--){
		cin >> l >> r >> t; l++; r++;
		int L = sa.bs_lft(t), R = sa.bs_rit(t);
		if(L > R || r - l + 1 < sz(t))
			cout << 0 << endl;
		else
			cout << query(rt[l - 1], rt[r - sz(t) + 1], 1, n, L, R) << endl;
	}
}

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}
