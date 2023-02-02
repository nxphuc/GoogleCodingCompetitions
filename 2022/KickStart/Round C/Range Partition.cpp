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

void solve() {
    int n, x, y;

    cin >> n >> x >> y;
    ll s = 1LL * n * (n + 1) / 2;
    if (s % (x + y)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    s = s / (x+y) * x;
    int cntA = 0, cur = n;
    vector<int> res;
    while (s > 0) {
        if (s >= cur) {
            s -= cur;
            res.emplace_back(cur);
        }
        --cur;
    }
    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}