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

int f[MAX];

int dp(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (f[n] != -1) return f[n];
    auto& res = f[n];
    res = dp(n - 1) + 1;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res = min(res, dp(i) + 4 + 2 * (n / i - 1));
            res = min(res, dp(n / i) + 4 + 2 * (i - 1));
        }
    }
    return res;
}

int solve() {
    memset(f, -1, sizeof f);
    int n;
    cin >> n;
    return dp(n);
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