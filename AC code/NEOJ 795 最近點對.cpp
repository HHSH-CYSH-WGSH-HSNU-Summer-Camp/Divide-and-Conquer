#include <bits/stdc++.h>

/* ----------------------------------------------- */

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

//typedef uint64_t ll;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const int maxn = 2e5 + 1;
const int INF = 2147483647;
const ll LLINF = 9e18;
const ll MOD = 1e9 + 7;

inline ll len(ll L, ll R) {
    return R-L+1;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &a) {
    return os << "(" << a.first << ", " << a.second << ")";
}

template<typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2> &a) {
    return is >> a.first >> a.second;
}

template<typename T>
ostream& operator<<(ostream& os, stack<T> a) {
    while (!a.empty()) {
        os << a.top() << ' ';
        a.pop();
    }
    return os;
}


/* ------------------------------------------- */

#define x first
#define y second

inline ll dis(pll& a, pll& b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}


int N;
ll ans = LLINF;
vector<pll> p, tmp;

void init() {
    cin >> N;
    p.resize(N);
}

void dfs(int l, int r) {
    int n = len(l, r);
    if (n <= 20) {
        FOR(i, l, r, 1) {
            FOR(j, i+1, r+1, 1) {
                ans = min(ans, dis(p[i], p[j]));
            }
        }
        return;
    }

    int mid = (l+r) / 2;
    int ml = mid, mr = mid;
    ll midx = p[mid].x;
    while (l <= ml && p[ml].x == midx) ml--;
    while (mr <= r && p[mr].x == midx) mr++;
    dfs(l, ml);
    dfs(mr, r);

    ll d = sqrt(ans)+1;
    tmp.clear();
    for (int i = mid; i >= l; i--) {
        if (abs(p[i].x - midx) <= d) tmp.emplace_back(p[i]);
        else break;
    }
    for (int i = mid+1; i <= r; i++) {
        if (abs(p[i].x - midx) <= d) tmp.emplace_back(p[i]);
        else break;
    }
    sort(tmp.begin(), tmp.end(), [&](pll& a, pll& b) {
        return a.y < b.y;
    });

    int nt = (int)tmp.size();
    REP(i, nt) {
        for (int j = i+1, cnt = 0; j < nt && cnt < 3; j++, cnt++) {
            ans = min(ans, dis(tmp[i], tmp[j]));
        }
    }

    return;
}


int main() {
    fastio
    init();

    Each(i, p) cin >> i.x >> i.y;
    sort(p.begin(), p.end());

    dfs(0, N-1);

    cout << ans << endl;


    return 0;
}
/*

4
2 1
4 4
1 2
6 3

 */