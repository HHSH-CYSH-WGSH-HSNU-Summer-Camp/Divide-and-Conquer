#define BlackMagic
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
#define endl '\n'
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
const int szmaxn = 5e5 + 1;

int n;
vector<int> v;
int pmx[szmaxn], pmi[szmaxn];
int mp[maxn];


ll dfs(int l, int r) {
    ll res = 0;
    if (l == r) {
        res++;
        return res;
    }
    if (r-l == 1) {
        res += 2;
        res += abs(v[l]-v[r]) == 1;
        return res;
    }

    int mid = (l+r)/2;
    res += dfs(l, mid);
    res += dfs(mid+1, r);

    REP(time, 2) {

        for (int i = mid+1; i <= r; i++) {
            pmx[i] = 0, pmi[i] = maxn;
            if (i == mid+1) pmx[i] = pmi[i] = v[i];
            else {
                pmx[i] = max(pmx[i-1], v[i]);
                pmi[i] = min(pmi[i-1], v[i]);
            }
        }

        ll miptr = mid+1, mxptr = mid, cnt = 0;
        int ipmx = 0, ipmi = maxn;

        for (int i = mid; i >= l; i--) {
            ipmx = max(ipmx, v[i]);
            ipmi = min(ipmi, v[i]);
            while (mxptr < r && pmx[mxptr+1] < ipmx) {
                mxptr++;
                int val = pmi[mxptr] + mxptr;
                mp[val]++;
                cnt++;
            }
            while (miptr <= r && pmi[miptr] >= ipmi) {
                int val = pmi[miptr] + miptr;
                mp[val]--;
                cnt--;
                miptr++;
            }
            int tag = ipmx + i;
            res += max(mp[tag], 0);
            int k = ipmx - ipmi + i;
            if (mid+1 <= k && k <= r && ipmi < pmi[k] && pmx[k] < ipmx) {
                res++;
            }
        }
        for (int j = min(miptr, mxptr); j <= r; j++) {
            int val = pmi[j] + j;
            mp[val] = 0;
        }

        reverse(&v[l], &v[r+1]);
        mid -= len(l, r)%2 == 1;
    }

    return res;
}


int main() {
    elpsycongroo

    memset(mp, 0, sizeof(mp));

    cin >> n;
    v.resize(n);
    REP(i, n) {
        int f, s;
        cin >> f >> s;
        v[f-1] = s;
    }

    ll ans = dfs(0, n-1);
    cout << ans << endl;

    return 0;
}
/*

4
5
1 2 3 4 5
5
5 1 2 4 3
10
7 6 5 8 9 10 1 2 3 4
20
1 2 3 4 10 9 8 7 6 5 11 14 13 12 20
19 18 17 16 15

1
4
3 2 1 4

 */