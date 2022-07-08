#include <bits/stdc++.h>

/* ----------------------------------------------- */

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

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



void dfs(int N, int tx, int ty, int bx, int by) {
    int cut = N/2;
    int ex[4] = {tx, tx, tx+cut, tx+cut};
    int ey[4] = {ty, ty+cut, ty, ty+cut};

    if (N == 2) {
        // base case: N = 2
        vector<pii> v;
        REP(i, 4) {
            if (ex[i] == bx && ey[i] == by)
                continue;
            v.emplace_back(mp(ex[i], ey[i]));
        }
        Report(v[0].F, v[0].S, v[1].F, v[1].S, v[2].F, v[2].S);
        return;
    }

    int cx[4] = {tx+cut-1, tx+cut-1, tx+cut, tx+cut};
    int cy[4] = {ty+cut-1, ty+cut, ty+cut-1, ty+cut};
    int skip;
    REP(i, 4) {
        int ux = ex[i], uy = ey[i];
        if (ux <= bx && bx < ux+cut && uy <= by && by < uy+cut)
            skip = i, dfs(cut, ux, uy, bx, by);
        else
            dfs(cut, ux, uy, cx[i], cy[i]);
    }
    vector<pii> v;
    REP(i, 4) {
        if (i == skip) continue;
        v.emplace_back(mp(cx[i], cy[i]));
    }
    Report(v[0].F, v[0].S, v[1].F, v[1].S, v[2].F, v[2].S);
}

void solve(int N, int X, int Y) {
    dfs(N, 1, 1, X, Y);
}