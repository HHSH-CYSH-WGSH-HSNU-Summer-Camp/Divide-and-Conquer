#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

using namespace std;

typedef long long ll;

/* ------------------------------------------- */

const ll LLINF = 4e18;


int n;
ll ans = -LLINF;
vector<ll> a;

void dfs(int l, int r) {
	if (l == r) {
		ans = max(ans, a[l]);
		return;
	}

	int mid = (l+r) / 2;
	dfs(l, mid);
	dfs(mid+1, r);

	ll suffix = 0, prefix = 0;
	ll mxsuf = -LLINF, mxpre = -LLINF;

	for (int i = mid; i >= l; i--) {
		suffix += a[i];
		mxsuf = max(mxsuf, suffix);
	}

	for (int i = mid+1; i <= r; i++) {
		prefix += a[i];
		mxpre = max(mxpre, prefix);
	}

	ans = max(ans, mxsuf + mxpre);
}

void init() {
	cin >> n;
	a.clear(); a.resize(n);
	Each(i, a) cin >> i;
}

void solve() {
	dfs(0, n-1);
	cout << ans << endl;
}

int main() {
	fastio

	init();
	solve();

	return 0;
}
/*


8
-1 3 -2 5 3 -5 2 2









*/
