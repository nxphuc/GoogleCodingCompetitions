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

#ifdef LOCAL_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    vector<int> cnt(k + 1, INF);
    int res = n + 1;
    cnt[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ll s = b[j] - b[i - 1];
            if (s > k) break;
            res = min(res, cnt[k - s] + j - i + 1);
        }
        for (int j = i; j > 0; j--) {
            ll s = b[i] - b[j - 1];
            if (s > k) break;
            cnt[s] = min(cnt[s], i - j + 1);
        }
    }
    return res > n ? -1 : res;
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