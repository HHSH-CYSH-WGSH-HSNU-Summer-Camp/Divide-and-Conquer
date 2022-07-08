#include <bits/stdc++.h>

/* ----------------------------------------------- */

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

#define ariter(_a, _n) _a, _a+_n
#define iter(a) a.begin(), a.end()

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1024 + 1;
const int INF = 2147483647;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

/* ------------------------------------------- */



int main() {
    fastio

    int n;
    cin >> n;

    int ptr = 1;
    vector<int> ans;
    ans.emplace_back(1);

    while (ptr < n) {
        Each(i, ans) i <<= 1;
        REP(i, ptr) ans.emplace_back(ans[i]-1);
        ptr <<= 1;
    }

    Each(i, ans) {
        if (i <= n) cout << i << ' ';
    }
    cout << endl;

    return 0;
}
/*




 */