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

void prepare(vector<ll>& a, vector<ll>& dp, int n) {
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i - 1];
    for (int len = 0; len <= n; len++)
        for (int suf = n - len, pre = 0; pre <= len; ++pre, ++suf)
            dp[len] = max(dp[len], sum[pre] + sum[n] - sum[suf]);
}

ll solve() {
    int n, m, k;
    cin >> n;
    vector<ll> a(n), dpA(n + 1);
    for (ll& x : a) cin >>  x;
    cin >> m;
    vector<ll> b(m), dpB(m + 1);
    for (ll& x : b) cin >> x;
    prepare(a, dpA, n);
    prepare(b, dpB, m);

    cin >> k;
    ll res = 0;
    for (int lenA = 0, lenB = k; lenA <= k && lenA <= n && lenB >= 0; ++lenA, --lenB) {
        if (lenB > m) continue;
        res = max(res, dpA[lenA] + dpB[lenB]);
    }
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