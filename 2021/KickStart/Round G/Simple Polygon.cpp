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

/*
a = n - 2
*/

void solve() {
    int n, a;
    cin >> n >> a;
    if (a < n - 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    int add = 0;
    int x = 0;
    vector<ii> upper, lower;
    a -= n - 2;
    while (n > 0) {
        lower.emplace_back(x, add);
        if (--n > 0) {
            upper.emplace_back(x, add + 1);
            --n;
        }
        add ^= 1;
        ++x;
    }
    upper[0].second += a;
    reverse(upper.begin(), upper.end());
    for (auto p : lower)
        cout << p.first << " " << p.second << "\n";
    for (auto p : upper)
        cout << p.first << " " << p.second << "\n";
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