#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define each(a, x) for (auto &a : x)

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

// min heap
template <class T>
using Heap = priority_queue<T, vector<T>, greater<T>>;

// ceil div
ll cdiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

// floor div
ll fdiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

#ifdef LOCAL_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<vi> a(n + 1, vi(k + 1));
    vector<vi> f(n + 1, vi(p + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++)
            cin >> a[i][j];
    }

    auto dp = [&](int i, int remain, auto&& dp) {
        if (remain == 0 || i == 0)
            return 0;
        if (f[i][remain] != -1)
            return f[i][remain];
        int& res = f[i][remain];
        int tot = 0;
        res = 0;

        for (int j = 0; j <= k && j <= remain; j++) {
            tot += a[i][j];
            ckmax(res, tot + dp(i - 1, remain - j, dp));
        }

        return res;
    };

    cout << dp(n, p, dp) << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    // freopen("test.ou", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}