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

struct info {
	ll mxsuf, mxpre, sum;
	info():
		mxsuf(-LLINF), mxpre(-LLINF), sum(0) {}
	info(ll _mxsuf, ll _mxpre, ll _sum):
		mxsuf(_mxsuf), mxpre(_mxpre), sum(_sum) {}
};


int n;
ll ans = -LLINF;
vector<ll> a;

info dfs(int l, int r) {
	if (l == r) {
		ans = max(ans, a[l]);
		return info(a[l], a[l], a[l]);
	}

	int mid = (l+r) / 2;
	info L = dfs(l, mid);
	info R = dfs(mid+1, r);

	ans = max(ans, L.mxsuf + R.mxpre);

	info ret = info(
		max(R.mxsuf, R.sum + L.mxsuf),
		max(L.mxpre, L.sum + R.mxpre),
		L.sum + R.sum
	);

	return ret;
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
