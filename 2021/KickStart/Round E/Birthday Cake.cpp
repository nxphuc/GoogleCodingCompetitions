#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

ll solve() {
    int n, m, k, r1, r2, c1, c2;

    cin >> n >> m >> k;
    cin >> r1 >> c1 >> r2 >> c2;

    --r1, --c1;
    ll rLen = r2 - r1;
    ll cLen = c2 - c1;
    int skipR = (r1 == 0) + (r2 == n);
    int skipC = (c1 == 0) + (c2 == m);
    ll res;
    if (skipR || skipC) {
        res = (2LL - skipR) * ceil(cLen, k);
        res += (2LL - skipC) * ceil(rLen, k);
    }
    else {
        ll rCut = ceil(rLen + min(r1, n - r2), k) + ceil(rLen, k) + 2 * ceil(cLen, k);
        ll cCut = ceil(cLen + min(c1, m - c2), k) + ceil(cLen, k) + 2 * ceil(rLen, k);
        res = min(rCut, cCut);
    }
    res += ceil(rLen, k) * ((cLen - 1) / k) + ceil(cLen, k) * ((rLen - 1) / k);
    res += rLen * cLen - ceil(rLen, k) * ceil(cLen, k);
    return res;
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << solve() << "\n";
    }

    return 0;
}