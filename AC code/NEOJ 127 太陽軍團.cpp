//#define BlackMagic
#ifdef BlackMagic
#include <bits/extc++.h>
using namespace __gnu_pbds;
#endif

#include <bits/stdc++.h>

/* ----------------------------------------------- */

#define elpsycongroo ios_base::sync_with_stdio(false); cin.tie(0);

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

#define ariter(_a, _n) _a, _a+_n
#define iter(a) a.begin(), a.end()

#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)

#define dbg(a, b) cout << "var " << a << " -> " << b << '\n';
#define dbg_itv(l, r, val) cout << "### (" << l << ", " << r << ") -> " << val << '\n';
#define flag(_a) cout << "Still alive at flag " << _a << '\n';
#define printv(_a) for (auto& _i : _a) cout << _i << ' '; cout << '\n';
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1e6 + 1;
const int INF = 2147483647;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

ll len(ll L, ll R) {
    return R-L+1;
}

ostream& operator<<(ostream& os, const pii &a) {
    return os << "(" << a.F << ", " << a.S << ")";
}

/* ------------------------------------------- */
//#define LOCAL

#ifdef LOCAL
int arr[5][5] = {{74, 59, 36, 28, 51},
                 {36, 63, 15, 25, 17},
                 {71, 64, 95, 43, 56},
                 {72, 62, 30, 24, 74}};
int GetVal(int r, int c) {
    cout << "GetVal\t" << r << ' ' << c << endl;
    return arr[r-1][c-1];
}
int cnt = 0;
void Report(int x) {
    cout << "Report\t"
         << ++cnt << ":\t" << x << endl;
}
#endif

ll ans[maxn];

ll scan(ll row, ll l, ll r) {
    ll mx = 0, pos = 0;
    FOR(i, l, r+1, 1) {
        int val = GetVal(row, i);
        if (val > mx) mx = val, pos = i;
    }
    ans[row] = pos;
    return pos;
}

void dfs(ll u, ll d, ll l, ll r) {
    if (u > d || l > r) return;
    ll mid = (u+d) / 2;
    ll pos = scan(mid, l, r);
    dfs(u, mid-1, l, pos-1);
    dfs(mid+1, d, pos+1, r);
}


void solve(int n, int m) {
    memset(ans, 0, sizeof(ans));
    dfs(1, n, 1, m);
    FOR(i, 1, n+1, 1) Report(ans[i]);
}

#ifdef LOCAL
int main() {
    solve(4, 5);
    return 0;
}
#endif
/*




 */