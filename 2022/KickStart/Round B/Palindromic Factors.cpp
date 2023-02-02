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

bool isPalin(ll x) {
    int tmp = x, rev = 0;
    while (tmp) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return x == rev;
}

ll solve() {
    ll n, res = 0;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res += isPalin(i);
            if (i*i < n)
                res += isPalin(n / i);
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