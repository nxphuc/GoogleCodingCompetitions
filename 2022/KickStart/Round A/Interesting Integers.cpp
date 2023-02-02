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

ll f[15][110][110][2][2];
int num[15];

ll dp(int pos, int targetSum, int curSum, int prod, int tight, int first) {
    if (pos < 0)
        return targetSum == curSum && prod == 0;
    auto &res = f[pos][curSum][prod][tight][first];
    if (res != -1) return res;
    res = 0;
    for (int d = 0; d < 10; d++) {
        int newSum = curSum + d;
        int newProd = (prod * d) % targetSum;
        int newFirst = 0;
        if (d == 0 && first)
            newProd = newFirst = 1;
        if (tight && d > num[pos]) break;
        if (newSum > targetSum) break;
        if (newSum + pos * 9 < targetSum) continue;
        res += dp(pos - 1, targetSum, newSum, newProd, (tight && d == num[pos]), newFirst);
    }
    return res;
}

ll calc(ll a) {
    int len = 0;
    memset(num, 0, sizeof num);
    while (a) {
        num[len++] = a % 10;
        a /= 10;
    }
    ll res = 0;
    for (int i = 1; i <= 9 * len; i++) {
        memset(f, -1, sizeof(f));
        res += dp(len, i, 0, 1, 1, 1);
    }
    return res;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
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