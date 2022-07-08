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

const int maxn = 1024 + 1;
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

int ans[maxn][maxn];
#ifdef LOCAL
// Testing Code
void Report(int x) {
    cout << x << ' ';
}
#endif


void dfs(int n, int l, int r, int tr, int tc) {
    if (n == 1) {
        ans[tr][tc] = l;
        return;
    }
    if (len(l, r) % 2) {
        int m1 = (l+r-1)/2;
        int m2 = m1+n/2;
        dfs(n/2, l, m1, tr, tc);
        dfs(n/2, l, m1, tr+n/2, tc+n/2);
        dfs(n/2, m1+1, m2, tr+n/2, tc);
        dfs(n/2, m2+1, r, tr, tc+n/2);
    } else {
        int m = l + n/2 - 1;
        dfs(n/2, l, m, tr, tc);
        dfs(n/2, l, m, tr+n/2, tc+n/2);
        dfs(n/2, m+1, r, tr+n/2, tc);
        dfs(n/2, m+1, r, tr, tc+n/2);
    }
}

void solve(int N) {
    dfs(N, 1, 2*N-1, 1, 1);
    FOR(i, 1, N+1, 1) {
        FOR(j, 1, N + 1, 1) {
            Report(ans[i][j]);
        }
#ifdef LOCAL
        cout << endl;
#endif
    }
}

#ifdef LOCAL
int main() {
    solve(8);

    return 0;
}
#endif
/*




 */