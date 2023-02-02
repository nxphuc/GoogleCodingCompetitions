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

ll solve() {
    int n, l, d;
    char c;
    ll res = 0;
    cin >> l >> n;
    int cur = 0;
    int lastC = '-';
    for (int i = 0; i < n; i++) {
        cin >> d >> c;
        if (cur == 0) lastC = c;

        if (c == 'C') {
            cur += d;
            if (cur >= l) {
                res += cur / l;
                if (lastC != c) res--;
                cur %= l;
                lastC = c;
            }
        }
        else {
            cur = (l - cur) % l;
            cur += d;
            if (cur >= l) {
                res += cur / l;
                if (lastC != c) res--;
                cur %= l;
                lastC = c;
            }
            cur = (l - cur) % l;
        }
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