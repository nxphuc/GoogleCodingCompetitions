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
    int a[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            cin >> a[i][j];
        }
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
        res += a[i][0] + a[i][2] == 2 * a[i][1];
        res += a[0][i] + a[2][i] == 2 * a[1][i];
    }
    map<int, int> cnt;
    cnt[a[0][0] + a[2][2]]++;
    cnt[a[0][1] + a[2][1]]++;
    cnt[a[0][2] + a[2][0]]++;
    cnt[a[1][0] + a[1][2]]++;
    debug(res);
    debug(cnt);
    int mx = 0;
    for (auto kvp : cnt)
        if (kvp.first % 2 == 0)
            mx = max(mx, kvp.second);
    return res + mx;
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