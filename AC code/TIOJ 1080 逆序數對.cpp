#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> a) {
    return os << "(" << a.first << ", " << a.second << ")";
}

inline ll len(ll l, ll r) {
    return r-l+1;
}

const int INF = 2e9;
const ll LLINF = 4e18;
const ll MOD = 1e9 + 7;

/* -------------------------------------------- */


int n;
vector<int> v;
ll ans;

void init() {
    v.clear(); v.resize(n);
    Each(i, v) cin >> i;
    ans = 0;
}

void dfs(int l, int r) {
    if (l == r) return;

    int mid = (l+r)>>1;
    dfs(l, mid);
    dfs(mid+1, r);

    vector<int> sorted;
    int Lptr = l, Rptr = mid+1;
    int cnt = 0;

    while (Lptr <= mid && Rptr <= r) {
        if (v[Lptr] > v[Rptr]) {
            sorted.emplace_back(v[Lptr++]);
            cnt++;
        } else {
            sorted.emplace_back(v[Rptr++]);
            ans += cnt;
        }
    }

    while (Lptr <= mid) {
        sorted.emplace_back(v[Lptr++]);
        cnt++;
    }
    while (Rptr <= r) {
        sorted.emplace_back(v[Rptr++]);
        ans += cnt;
    }
    
    int p = l; Each(i, sorted) v[p++] = i;
}

void solve() {
    dfs(0, n-1);
    cout << ans << endl;
}


int main() {
    fastio

    int kase = 0;
    while (cin >> n && n) {
        cout << "Case #" << ++kase << ": ";
        init();
        solve();
    }

    return 0;
}
/*


5
1 2 3 4 5
5
1 2 3 5 4
7
7 6 5 4 3 2 1
0


4
1 2 3 4
0








*/