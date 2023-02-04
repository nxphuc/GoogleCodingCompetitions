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

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (auto & x : a) cin >> x;
    l[0] = 1;
    l[1] = 2;

    int res = 2;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 2;
        res = max(res, l[i] + (i < n - 1));
    }
    r[n - 1] = 1;
    r[n - 2] = 2;
    for (int i = n - 3; i >= 0; i--) {
        if (a[i] - a[i + 1] == a[i + 1] - a[i + 2])
            r[i] = r[i + 1] + 1;
        else
            r[i] = 2;
        res = max(res, r[i] + (i > 0));
    }
    for (int i = 1; i < n - 1; i++) {
        int diff = a[i + 1] - a[i - 1];
        if (diff & 1) continue;
        diff >>= 1;
        int cnt = 3;
        if (i > 1 && a[i - 1] - a[i - 2] == diff) cnt += l[i - 1] - 1;
        if (i + 2 < n && a[i + 2] - a[i + 1] == diff) cnt += r[i + 1] - 1;
        res = max(res, cnt);
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