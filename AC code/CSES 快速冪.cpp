#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

using namespace std;

typedef long long ll;

/* ------------------------------------------- */

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    ll mid = pw(a, b/2);

    if (b % 2) return mid * mid % MOD * a % MOD;
    else return mid * mid % MOD;
}


int n;
 
void init() {
    cin >> n;
}

void solve() {
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << pw(a, b) << endl;
    }
}

int main() {
    fastio

    init();
    solve();
 
    return 0;
}
/*
 
3
3 4
2 8
123 123
 
 */
