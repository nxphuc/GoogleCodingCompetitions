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

const int MAX = 410;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

ll f[MAX][MAX][2];
ll a[MAX];
int n, d;

ll dp(int l, int r, int side) {
    if (l > r) return 0;
    ll& res = f[l][r][side];
    if (res != -1) return res;
    int prev = side ? a[r + 1] : a[l - 1];
    int diff = abs(prev - a[l]);
    res = dp(l + 1, r, 0) + min(diff, d - diff);
    diff = abs(prev - a[r]);
    res = min(res, dp(l, r - 1, 1) + min(diff, d - diff));
    return res;
}

ll solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, -1, sizeof f);
    a[0] = a[n + 1] = 0;
    return min(dp(1, n, 0), dp(1, n, 1));
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